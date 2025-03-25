#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Process
{
public:
    int id;
    int arrivingTime;
    int startTime;
    int waitingTime;
    int runningTime;//运行
    int endTime;
    int turnAroundTime;//周转
    int priority;
    int remainingTime;//剩余时间


};


// 冒泡排序：按到达时间排序进程
void bubbleSortByArrivalTime(vector<Process>& processes) 
{
    int n = processes.size();
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - 1 - i; ++j) 
        {
            if (processes[j].arrivingTime > processes[j + 1].arrivingTime) {
                swap(processes[j], processes[j + 1]); // 交换两个进程的位置
            }
        }
    }
}

// 按运行时间排序进程（升序）
void bubbleSortByRunningTime(vector<Process>& processes)
{
    int n = processes.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (processes[j].runningTime > processes[j + 1].runningTime) {
                swap(processes[j], processes[j + 1]); // 交换两个进程的位置
            }
        }
    }
}



// 先来先服务（FIFO）
void FIFO(vector<Process>& processes) 
{
    bubbleSortByArrivalTime(processes);
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;

    for (auto& p : processes) 
    {
        p.startTime = max(currentTime, p.arrivingTime);
        p.endTime = p.startTime + p.runningTime;
        p.waitingTime = p.startTime - p.arrivingTime;
        p.turnAroundTime = p.endTime - p.arrivingTime;
        currentTime = p.endTime;

        totalWaitingTime += p.waitingTime;
        totalTurnAroundTime += p.turnAroundTime;
    }

    for (const auto& p : processes) 
    {
        cout << "Process " << p.id << ": Start = " << p.startTime
             << ", End = " << p.endTime << ", Waiting = " << p.waitingTime
             << ", Turnaround = " << p.turnAroundTime << endl;
    }

    int n = processes.size();
    cout << "Average Waiting Time = " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl;
}


void SJF(vector<Process>& processes) 
{
    bubbleSortByRunningTime(processes);
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;

    for (auto& p : processes) 
    {
        p.startTime = max(currentTime, p.arrivingTime);
        p.endTime = p.startTime + p.runningTime;
        p.waitingTime = p.startTime - p.arrivingTime;
        p.turnAroundTime = p.endTime - p.arrivingTime;
        currentTime = p.endTime;

        totalWaitingTime += p.waitingTime;
        totalTurnAroundTime += p.turnAroundTime;
    }

    for (const auto& p : processes) 
    {
        cout << "Process " << p.id << ": Start = " << p.startTime
             << ", End = " << p.endTime << ", Waiting = " << p.waitingTime
             << ", Turnaround = " << p.turnAroundTime << endl;
    }

    int n = processes.size();
    cout << "Average Waiting Time = " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl;
}

// void SJF(vector<Process>& processes) 
// {
//     bubbleSortByArrivalTime(processes); // 按到达时间排序
//     int currentTime = 0; // 当前时间
//     int totalWaitingTime = 0; // 总等待时间
//     int totalTurnAroundTime = 0; // 总周转时间
    
//     int processIndex = 0; // 进程的索引

//     // 循环处理所有进程
//     while (processIndex < processes.size()) {
//         vector<Process> availableProcesses; // 当前时刻所有可用的进程
        
//         // 选择所有到达的进程
//         while (processIndex < processes.size() && processes[processIndex].arrivingTime <= currentTime) {
//             availableProcesses.push_back(processes[processIndex]);
//             processIndex++;
//         }

//         if (!availableProcesses.empty()) {
//             // 按运行时间排序可用进程，选择运行时间最短的进程
//             bubbleSortByRunningTime(availableProcesses);

//             Process p = availableProcesses.front(); // 选择最短作业
//             availableProcesses.erase(availableProcesses.begin()); // 删除已选进程

//             p.startTime = max(currentTime, p.arrivingTime); // 进程开始时间
//             p.endTime = p.startTime + p.runningTime; // 进程结束时间
//             p.waitingTime = p.startTime - p.arrivingTime; // 计算等待时间
//             p.turnAroundTime = p.endTime - p.arrivingTime; // 计算周转时间
//             currentTime = p.endTime; // 更新当前时间

//             totalWaitingTime += p.waitingTime;
//             totalTurnAroundTime += p.turnAroundTime;

//             cout << "Process " << p.id << ": Start = " << p.startTime
//                  << ", End = " << p.endTime << ", Waiting = " << p.waitingTime
//                  << ", Turnaround = " << p.turnAroundTime << endl;
//         } else {
//             // 如果没有进程可以执行，跳到下一个进程的到达时间
//             currentTime = processes[processIndex].arrivingTime;
//         }
//     }

//     // 输出平均等待时间和平均周转时间
//     int n = processes.size();
//     cout << "Average Waiting Time = " << (double)totalWaitingTime / n << endl;
//     cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl;
// }

void RR(vector<Process>& processes, int timeQuantum) 
{
    // 初始化 remainingTime
    for (auto& p : processes) {
        p.remainingTime = p.runningTime;
        p.startTime = -1; // 标记尚未开始
    }

    // 按到达时间排序
    bubbleSortByArrivalTime(processes);
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int n = processes.size();
    int completedCount = 0;

    // 使用指针避免拷贝
    queue<Process*> readyQueue;
    int processIndex = 0; // 当前处理的进程索引

    while (completedCount < n) {
        // 将所有到达的进程加入就绪队列
        while (processIndex < n && processes[processIndex].arrivingTime <= currentTime) {
            readyQueue.push(&processes[processIndex]);
            processIndex++;
        }

        if (readyQueue.empty()) {
            // 如果没有进程可执行，跳到下一个进程的到达时间
            if (processIndex < n) {
                currentTime = processes[processIndex].arrivingTime;
                continue;
            }
        }

        if (!readyQueue.empty()) {
            Process* p = readyQueue.front();
            readyQueue.pop();

            // 如果是首次执行，记录开始时间
            if (p->startTime == -1) {
                p->startTime = currentTime;
            }

            // 执行时间
            int execTime = min(timeQuantum, p->remainingTime);
            currentTime += execTime;
            p->remainingTime -= execTime;

            // 在执行期间，可能有新的进程到达
            while (processIndex < n && processes[processIndex].arrivingTime <= currentTime) {
                readyQueue.push(&processes[processIndex]);
                processIndex++;
            }

            if (p->remainingTime > 0) {
                // 进程未完成，重新加入队列
                readyQueue.push(p);
            } else {
                // 进程完成
                p->endTime = currentTime;
                p->turnAroundTime = p->endTime - p->arrivingTime;
                p->waitingTime = p->turnAroundTime - p->runningTime;

                totalWaitingTime += p->waitingTime;
                totalTurnAroundTime += p->turnAroundTime;
                completedCount++;

                // 输出进程结果
                cout << "Process " << p->id << ": Start = " << p->startTime
                     << ", End = " << p->endTime << ", Waiting = " << p->waitingTime
                     << ", Turnaround = " << p->turnAroundTime << endl;
            }
        }
    }

    // 输出平均等待时间和周转时间
    cout << "Average Waiting Time = " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl;
}

// 多级反馈队列调度（MLFQ）
void MLFQ(vector<Process>& processes) 
{
    // 定义队列数量和每个队列的时间片
    const int NUM_QUEUES = 3;
    int timeQuantums[NUM_QUEUES] = {4, 8, 12}; // 时间片设置，可根据需要调整

    // 按到达时间排序
    bubbleSortByArrivalTime(processes);
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int n = processes.size();
    int completedCount = 0;

    // 初始化每个进程的 remainingTime 和 currentQueueLevel
    for (auto& p : processes) {
        p.remainingTime = p.runningTime;
        p.priority = 0; // 初始放在最高优先级队列
    }

    // 定义多个就绪队列
    vector<queue<Process*>> queues(NUM_QUEUES, queue<Process*>());

    int processIndex = 0; // 当前处理的进程索引

    while (completedCount < n) {
        // 将所有到达的进程加入最高优先级队列
        while (processIndex < n && processes[processIndex].arrivingTime <= currentTime) {
            queues[0].push(&processes[processIndex]);
            processIndex++;
        }

        bool foundProcess = false;
        // 从最高优先级队列开始寻找可执行的进程
        for (int q = 0; q < NUM_QUEUES; ++q) {
            if (!queues[q].empty()) {
                Process* p = queues[q].front();
                queues[q].pop();

                // 如果是首次执行，记录开始时间
                if (p->startTime == -1) {
                    p->startTime = currentTime;
                }

                // 执行时间为当前队列的时间片或剩余时间的较小值
                int execTime = min(timeQuantums[q], p->remainingTime);
                p->remainingTime -= execTime;
                currentTime += execTime;

                // 在执行期间，可能有新的进程到达
                while (processIndex < n && processes[processIndex].arrivingTime <= currentTime) {
                    queues[0].push(&processes[processIndex]);
                    processIndex++;
                }

                if (p->remainingTime > 0) {
                    // 如果当前队列不是最低优先级队列，则降级
                    if (q < NUM_QUEUES - 1) {
                        p->currentQueueLevel = q + 1;
                        queues[q + 1].push(p);
                    } else {
                        // 已在最低优先级队列，重新加入该队列
                        queues[q].push(p);
                    }
                } else {
                    // 进程完成
                    p->endTime = currentTime;
                    p->turnAroundTime = p->endTime - p->arrivingTime;
                    p->waitingTime = p->turnAroundTime - p->runningTime;

                    totalWaitingTime += p->waitingTime;
                    totalTurnAroundTime += p->turnAroundTime;
                    completedCount++;

                    // 输出进程结果
                    cout << "Process " << p->id << ": Start = " << p->startTime
                         << ", End = " << p->endTime << ", Waiting = " << p->waitingTime
                         << ", Turnaround = " << p->turnAroundTime << endl;
                }

                foundProcess = true;
                break; // 只执行一个进程，回到检查队列
            }
        }

        if (!foundProcess) {
            // 如果没有进程可执行，跳到下一个进程的到达时间
            if (processIndex < n) {
                currentTime = processes[processIndex].arrivingTime;
            }
        }
    }

    // 输出平均等待时间和周转时间
    cout << "Average Waiting Time = " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl;
}







int main()
{
    cout<<"numbers of processes";
    int n;
    cin>>n;
    vector<Process> processes(n);
    cout<<"id    runningTime   arrivingTime   Priority";
    for(int i=0;i<n;i++)
    {
        cin>>processes[i].id>>processes[i].runningTime>>processes[i].arrivingTime>>processes[i].priority;
    }

    cout<<"Choose the scheduling algorithm:"<<endl<<"1:FIFO"<<endl<<"2:SJF"
    <<endl<<"3:Priority"<<endl<<"4:RR"<<endl<<"5:MLFQ";
    int choice;
    cin >> choice;

    int timeQuantum;//时间片
    if (choice == 4||choice==5) 
    {
        cout << "Enter time quantum: ";
        cin >> timeQuantum;
    }

     switch (choice) {
        case 1:
            FIFO(processes); // 调用FIFO调度
            break;
        case 2:
            SJF(processes); // 调用SJF调度
            break;
        case 3:
            //priorityScheduling(processes); // 调用优先级调度
            break;
        case 4:
            RR(processes, timeQuantum); // 调用Round Robin调度
            break;
        case 5:
            //
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}