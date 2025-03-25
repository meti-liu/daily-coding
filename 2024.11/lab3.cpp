#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define MAX_CAPACITY 5  // 停车场最大容量
#define NUM_VEHICLES 10 // 车辆数目

// 全局变量
int parking_lot = 0;  // 当前停车场的车辆数
pthread_mutex_t mutex; // 互斥锁
pthread_cond_t full;   // 条件变量 - 停车场已满
pthread_cond_t empty;  // 条件变量 - 停车场有空位

// 车辆线程
void* vehicle_entry(void* arg) {
    int vehicle_id = *(int*)arg;
    
    // 进入停车场
    wait_mutex();
    park_vehicle(vehicle_id);
    signal_mutex();

    // 模拟停留
    int stay_time = rand() % 5 + 1; // 1 到 5 秒之间
    sleep(stay_time);
    
    // 离开停车场
    wait_mutex();
    leave_vehicle(vehicle_id);
    signal_mutex();

    return NULL;
}

// 获取锁
void wait_mutex() {
    pthread_mutex_lock(&mutex);
}

// 释放锁
void signal_mutex() {
    pthread_mutex_unlock(&mutex);
}

// 车辆进入停车场
void park_vehicle(int vehicle_id) {
    if (parking_lot == MAX_CAPACITY) {
        std::cout << "Vehicle " << vehicle_id << " waiting: Parking lot full." << std::endl;
        pthread_cond_wait(&full, &mutex);
    }
    parking_lot++;
    std::cout << "Vehicle " << vehicle_id << " entered. Parking lot count: " << parking_lot << std::endl;
}

// 车辆离开停车场
void leave_vehicle(int vehicle_id) {
    parking_lot--;
    std::cout << "Vehicle " << vehicle_id << " left. Parking lot count: " << parking_lot << std::endl;

    if (parking_lot < MAX_CAPACITY) {
        pthread_cond_signal(&empty); // 有空位了，通知其他车辆
    }
}

// 主程序，创建车辆线程
int main() {
    srand(time(NULL));
    pthread_t vehicles[NUM_VEHICLES];
    int vehicle_ids[NUM_VEHICLES];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    // 创建车辆线程
    for (int i = 0; i < NUM_VEHICLES; i++) {
        vehicle_ids[i] = i;
        pthread_create(&vehicles[i], NULL, vehicle_entry, &vehicle_ids[i]);
    }

    // 等待所有线程结束
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }

    // 销毁锁和条件变量
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}
