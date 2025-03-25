semaphore bridge=1;
semaphore mutex=1;
int countZ=0;
int countL=0;

void Zcross()//一个赵村人想上桥
{
    wait(mutex);//确保下面两行操作原子进行，不中断

    if(countZ==0) wait(bridge);//赵村全部开始上桥，占用桥资源
    countZ++;//赵村人上桥

    signal(mutex);


    cross();//临界区，过桥


    wait(mutex);//确保下面两行操作原子进行，不中断

    countZ--;//赵村人下桥
    if(countZ==0) wait(bridge);//赵村全部下桥，释放桥资源

    signal(mutex);


}

void Lcross()//一个李村人想上桥
{
    wait(mutex);//确保下面两行操作原子进行，不中断

    if(countL==0) wait(bridge);//李村上桥，占用桥资源
    countL++;//李村人上桥

    signal(mutex);

    
    cross();//临界区，过桥


    wait(mutex);//确保下面两行操作原子进行，不中断

    countZ--;//李村人下桥
    if(countZ==0) wait(bridge);//李村全部下桥，释放桥资源

    signal(mutex);
}