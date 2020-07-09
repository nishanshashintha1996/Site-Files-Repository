//---------------------------------------------------------------------------//
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAXSTACK 100

//---------------------------------------------------------------------------//

typedef char StackEntry;
typedef struct
{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;

//---------------------------------------------------------------------------//

void CreateStack(Stack *s)
{
    s->top=-1;
}

//---------------------------------------------------------------------------//

int IsStackEmpty(const Stack *s)
{
    if(s->top==-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//---------------------------------------------------------------------------//

int IsStackFull(const Stack *s)
{
    if(s->top==MAXSTACK-1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//---------------------------------------------------------------------------//


void Push(StackEntry item, Stack *s)
{
    if(!IsStackFull(s))
    {
        s->entry[++s->top]=item;
    }
    else
    {
        printf("-------------------stack is full--------------------\n");
    }
}

//---------------------------------------------------------------------------//

void Pop(StackEntry *item, Stack *s)
{
    if(IsStackEmpty(s))
    {
        printf("-------------------This formula is wrong--------------------\n");
    }
    else
    {
        *item = s->entry[s->top--];
    }
}
