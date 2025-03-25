#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

// 定义 Process 类
class Process
{
public:
    int id;
    int arrivingTime;
    int startTime;
    int waitingTime;
    int runningTime; // 运行时间
    int endTime;
    int turnAroundTime; // 周转时间
    int priority;
    int remainingTime; // 剩余时间
    int currentQueueLevel; // 当前队列级别

    Process() : startTime(-1), waitingTime(0), endTime(0), turnAroundTime(0), remainingTime(0), currentQueueLevel(0) {}
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

// 短作业优先调度（SJF）
void SJF(vector<Process>& processes) 
{
    // 先按到达时间排序
    bubbleSortByArrivalTime(processes);
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int n = processes.size();
    vector<bool> completed(n, false);
    int completedCount = 0;

    while (completedCount < n) {
        // 找到所有已到达且未完成的进程
        vector<int> available;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivingTime <= currentTime && !completed[i]) {
                available.push_back(i);
            }
        }

        if (available.empty()) {
            // 如果没有进程可执行，跳到下一个到达的进程
            int nextArrival = INT32_MAX;
            for (int i = 0; i < n; ++i) {
                if (!completed[i] && processes[i].arrivingTime < nextArrival) {
                    nextArrival = processes[i].arrivingTime;
                }
            }
            currentTime = nextArrival;
            continue;
        }

        // 找到运行时间最短的进程
        int shortest = available[0];
        for (int idx : available) {
            if (processes[idx].runningTime < processes[shortest].runningTime) {
                shortest = idx;
            }
        }

        // 执行该进程
        processes[shortest].startTime = currentTime;
        processes[shortest].endTime = currentTime + processes[shortest].runningTime;
        processes[shortest].waitingTime = currentTime - processes[shortest].arrivingTime;
        processes[shortest].turnAroundTime = processes[shortest].endTime - processes[shortest].arrivingTime;
        currentTime += processes[shortest].runningTime;
        completed[shortest] = true;
        completedCount++;

        totalWaitingTime += processes[shortest].waitingTime;
        totalTurnAroundTime += processes[shortest].turnAroundTime;
    }

    for (const auto& p : processes) 
    {
        cout << "Process " << p.id << ": Start = " << p.startTime
             << ", End = " << p.endTime << ", Waiting = " << p.waitingTime
             << ", Turnaround = " << p.turnAroundTime << endl;
    }

    int n_process = processes.size();
    cout << "Average Waiting Time = " << (double)totalWaitingTime / n_process << endl;
    cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n_process << endl;
}

// Round Robin 调度
void RR(vector<Process>& processes, int timeQuantum) 
{
    // 初始化 remainingTime 和 startTime
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
            p->remainingTime -= execTime;
            currentTime += execTime;

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
void MLFQ(vector<Process>& processes, int numQueues, vector<int> timeQuantums) 
{
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
        p.currentQueueLevel = 0; // 初始放在最高优先级队列
    }

    // 定义多个就绪队列
    vector<queue<Process*>> queues(numQueues, queue<Process*>());

    int processIndex = 0; // 当前处理的进程索引

    // 定义一个调度顺序记录向量
    vector<pair<int, int>> scheduleLog; // 每个元素是 (队列号, 进程号)

    while (completedCount < n) {
        // 将所有到达的进程加入最高优先级队列
        while (processIndex < n && processes[processIndex].arrivingTime <= currentTime) {
            queues[0].push(&processes[processIndex]);
            processIndex++;
        }

        bool foundProcess = false;
        // 从最高优先级队列开始寻找可执行的进程
        for (int q = 0; q < numQueues; ++q) {
            if (!queues[q].empty()) {
                Process* p = queues[q].front();
                queues[q].pop();

                // 记录调度步骤
                scheduleLog.emplace_back(q, p->id);

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
                    if (q < numQueues - 1) {
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

    // 输出调度顺序
    cout << "\nScheduling Order (Queue, Process):\n";
    for (const auto& entry : scheduleLog) {
        cout << "(" << entry.first << "," << entry.second << ") ";
    }
    cout << endl;

    // 输出平均等待时间和周转时间
    cout << "Average Waiting Time = " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl;
}

int main()
{
    cout << "Number of processes: ";
    int n;
    cin >> n;
    vector<Process> processes(n);
    cout << "Enter processes (id runningTime arrivingTime Priority):\n";
    for(int i = 0; i < n; i++)
    {
        cin >> processes[i].id >> processes[i].runningTime >> processes[i].arrivingTime >> processes[i].priority;
    }

    cout << "Choose the scheduling algorithm:\n1: FIFO\n2: SJF\n3: Priority\n4: RR\n5: MLFQ\n";
    int choice;
    cin >> choice;

    int timeQuantum; // 时间片
    if (choice == 4) 
    {
        cout << "Enter time quantum: ";
        cin >> timeQuantum;
    }

    // 为 MLFQ 动态输入队列数量和各队列时间片
    int numQueues = 0;
    vector<int> timeQuantums;
    if (choice == 5)
    {
        cout << "Enter number of queues for MLFQ: ";
        cin >> numQueues;
        if (numQueues <= 0) {
            cout << "Number of queues must be positive." << endl;
            return 1;
        }
        timeQuantums.resize(numQueues);
        for (int q = 0; q < numQueues; ++q) {
            cout << "Enter time quantum for Queue " << q;
            cin >> timeQuantums[q];
            if (timeQuantums[q] <= 0) {
                cout << "Time quantum must be positive." << endl;
                return 1;
            }
        }
    }

    switch (choice) {
        case 1:
            FIFO(processes); // 调用 FIFO 调度
            break;
        case 2:
            SJF(processes); // 调用 SJF 调度
            break;
        case 3:
            // priorityScheduling(processes); // 调用优先级调度（未实现）
            cout << "Priority Scheduling not implemented yet.\n";
            break;
        case 4:
            RR(processes, timeQuantum); // 调用 Round Robin 调度
            break;
        case 5:
            MLFQ(processes, numQueues, timeQuantums); // 调用多级反馈队列调度
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
