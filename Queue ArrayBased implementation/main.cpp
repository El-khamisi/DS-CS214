#include "queue.h"


using namespace std;

void print(QueueEntry e)
{
    cout<<e<<"\t";
}
int main() {

    Queue q;
    initqueue(&q);
    QueueEntry E=0;

    if (!queuefull(&q))
        append(10,&q);
    if (!queuefull(&q))
        append(20, &q);
    if (!queuefull(&q))
        append(30, &q);
    if (!queuefull(&q))
        append(40, &q);

if (!queueempty(&q))
{cout<<"Current Elements is  ";traversqueu(&q, print);cout<<endl;}

    if (!queueempty(&q))
        serve(&E, &q);
    cout<<"Element has been served "<<E<<"\t";


    cout<<"Queue size is "<<queuesize(&q)<<endl;



clearqueue(&q);
    cout<<"Queue size After clearing is "<<queuesize(&q)<<endl;



    return 0;
}
