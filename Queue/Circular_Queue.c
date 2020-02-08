#include<stdio.h>
#include<stdlib.h>
#define N 10

void insert(int q[], int *f, int *r, int val)
{
    if(((*r)+1)%N == *f)
    {
        printf("Queue Full\n");
        exit(-1);
    }

    (*r) = ((*r)+1)%N;
    q[*r] = val;

    if((*f) == -1)
        (*f)=0;
}

int delete(int q[], int *f, int *r)
{
    int val;
    if((*f) == -1)
    {
        printf("Queue Empty");
        exit(-1);
    }

    val = q[*f];

    if((*f) == (*r))
        (*f)=(*r)=-1;

    else
        (*f) = ((*f)+1)%N;

    return val;
}

void main()
{
    int q[N];
    int F,R,i,v;
    F=R=-1;

    for(i=0;i<10;i++)
    {
        insert(q,&F,&R,i*10);
        printf("Inserted %d\n", i*10);
    }

    for(i=0;i<9;i++)
    {
        v = delete(q,&F,&R);
        printf("Deleted %d\n", v);
    }

    for(i=0;i<15;i++)
    {
        insert(q,&F,&R,i*10);
        printf("Inserted %d\n",i*5);
    }
}

/*OUTPUT
Inserted 0
Inserted 10
Inserted 20
Inserted 30
Inserted 40
Inserted 50
Inserted 60
Inserted 70
Inserted 80
Inserted 90
Deleted 0
Deleted 10
Deleted 20
Deleted 30
Deleted 40
Deleted 50
Deleted 60
Deleted 70
Deleted 80
Inserted 0
Inserted 5
Inserted 10
Inserted 15
Inserted 20
Inserted 25
Inserted 30
Inserted 35
Inserted 40
Queue Full*/
