#include<stdio.h>
#include<stdlib.h>
#define N 20
void PUSH(int s[],int *top,int val)
{
    if((*top)<(N-1))
        {   s[++(*top)]=val;
            printf("The value %d is pushed\n",val);
        }
    else
        printf("Stack Overflow\n");
}
int POP(int s[],int *top)
{   char val;
    if((*top)>-1)
        {
            val=s[(*top)--];
            printf("The value %d is poped\n",val);
            return val;
        }
    else
        {
            printf("Stack Underflow\n");
            exit(-1);
        }
}
int READ(int s[],int *top,int i)
{
    if(((*top)-i+1)>=0)
        {
             printf("The value at position %d is %d\n",i,s[(*top)-i+1]);
             return s[(*top)-i+1];
        }
    else
    {
        printf("Stack Underflow\n");
        exit(-1);
    }
}
void CHANGE(int s[],int *top,int i,int val)
{
    if(((*top)-i+1)>=0)
        {
            s[(*top)-i+1]=val;
            printf("The value at position %d from top is changed with %d\n",i,val);
        }
    else
        printf("Stack Underflow\n");
}

int main()
{
    int s[N];
    int top=-1;

    PUSH(s,&top,10);
    PUSH(s,&top,20);
    POP(s,&top);
    READ(s,&top,1);
    CHANGE(s,&top,1,30);
}
/*
OUTPUT
The value 10 is pushed
The value 20 is pushed
The value 20 is poped
The value at position 1 is 10
The value at position 1 from top is changed with 30
*/
