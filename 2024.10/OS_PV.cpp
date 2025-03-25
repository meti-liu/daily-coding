struct semaphore
{
    int value;//可用资源数
    struct process* list;//等待队列
};

void wait(semaphore s)//P
{
    s.value--;//占用资源，可用资源数减少
    if(s.value<0)
    {
        //将进程P加入s->list
        block(s.list);//阻塞队列进程
    }
}

void signal(semaphore s)//V
{
    s.value++;//释放资源，可用资源数增加
    if(s.value<=0)//有其他进程在等待
    {
        //将 进程P 从 s->list移除
        wake(s.list);//唤醒队头进程
    }
}