
#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 100
typedef char QueueElement;
typedef enum{FALSE,TRUE}Boolean;


typedef struct Queue
{
    int qcount;
    int qfront;
    int rear;
    QueueElement item [MAXQUEUE];
}Queue;



void CreateQueue(Queue *q)
{
    q->qcount=0;
    q->qfront=0;
    q->rear=-1;
}


int SizeOfQueue(Queue *q)
{
    return q->qcount;
}



Boolean IsQueueEmpty(Queue *q)
{
    if(q->rear<q->qfront)
    return(TRUE);
    else
    return(FALSE);
}


Boolean IsQueueFull(Queue *q)
{
    if(q->rear==MAXQUEUE-1)
    return(TRUE);
    else
    return(FALSE);
}



void Append(Queue *q,QueueElement x)
{
    if(IsQueueFull(q))
    {
        printf("Queue is full\n");
        exit(1);
    }
    else
    {
        q->item[++(q->rear)]=x;
        q->qcount++;
    }
}



void Serve(Queue *q,QueueElement *x)
{
    if(IsQueueEmpty(q))
    {
        printf("Queue is empty,under low\n");
        exit(1);
    }
    else
    {
        *x=q->item[(q->qfront)++];
        q->qcount--;
    }
}
