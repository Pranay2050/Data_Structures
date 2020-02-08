#include<stdio.h>
#include<stdlib.h>
# define N 10

void insert(int q[], int *f, int *r, int val)
{
    if((*r)+1 >= N)
    {
        printf("Queue Full\n");
        exit(-1);
    }

    (*r)++;
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
        (*f)++;

    return val;
}
void main()
{
    int high[N],mid[N],low[N];
    int F_h = -1, R_h = -1, F_m = -1, R_m = -1, F_l = -1, R_l = -1;
    int val,priority,v,choice,num;
    char ch = 'y';
    num = 1;
    printf("PRIORITY QUEUE\n\n");
    printf("Select the operation : \n1.Insert\n2.Process a single element\n3.Process all\n4.Exit\n");
    while(num)
    {
        printf("\nChoice : ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            while(ch == 'y' || ch == 'Y')
            {
                printf("\nEnter the Value and Priority(0/1/2) : ");
                scanf("%d %d",&val,&priority);

                if(priority == 0)
                    insert(high,&F_h,&R_h,val);

                else if(priority == 1)
                    insert(mid,&F_m,&R_m,val);

                else if(priority == 2)
                    insert(low,&F_l,&R_l,val);

                else
                {
                    printf("Please Enter valid Priority\n\n");
                    continue;
                }
            printf("Do you want to insert other entry? (Y/N) : ");
            scanf(" %c",&ch);
            }
        }

        if(choice == 2)
        {
            if(R_h != -1)
            {
                v = delete(high,&F_h,&R_h);
                printf("%d is processed\n",v);
            }

            else if(R_m != -1)
            {
                v = delete(mid,&F_m,&R_m);
                printf("%d is processed\n",v);
            }

            else if(R_l != -1)
            {
                v = delete(low,&F_l,&R_l);
                printf("%d is processed\n",v);
            }

            else
                printf("All queues are empty\n");
        }

        if(choice == 3)
        {
            printf("Order of Execution\n");

            while(R_h != -1)
            {
                v = delete(high,&F_h,&R_h);
                printf("%d is processed\n",v);
            }

            while(R_m != -1)
            {
                v = delete(mid,&F_m,&R_m);
                printf("%d is processed\n",v);
            }

            while(R_l != -1)
            {
                v = delete(low,&F_l,&R_l);
                printf("%d is processed\n",v);
            }
        }

        if(choice == 4)
        {
            printf("Comment on fairness of implementation :\nThe above queue implementation is unfair for the lower priority queue members as the will never get chance to get processed if the new entries are coming in the higher priority queue.");
            num = 0;
        }
    }
}
/*OUTPUT
PRIORITY QUEUE

Select the operation :
1.Insert
2.Process a single element
3.Process all
4.Exit

Choice : 1

Enter the Value and Priority(0/1/2) : 10 2
Do you want to insert other entry? (Y/N) : y

Enter the Value and Priority(0/1/2) : 7 1
Do you want to insert other entry? (Y/N) : y

Enter the Value and Priority(0/1/2) : 5 0
Do you want to insert other entry? (Y/N) : y

Enter the Value and Priority(0/1/2) : 98 2
Do you want to insert other entry? (Y/N) : y

Enter the Value and Priority(0/1/2) : 23 1
Do you want to insert other entry? (Y/N) : y

Enter the Value and Priority(0/1/2) : 34 0
Do you want to insert other entry? (Y/N) : y

Enter the Value and Priority(0/1/2) : 23 2
Do you want to insert other entry? (Y/N) : n

Choice : 2
5 is processed

Choice : 3
Order of Execution
34 is processed
7 is processed
23 is processed
10 is processed
98 is processed
23 is processed

Choice : 4
Comment on fairness of implementation :
The above queue implementation is unfair for the lower priority queue members as the will never get chance to get processed if the new entries are coming in the higher priority queue.
*/
