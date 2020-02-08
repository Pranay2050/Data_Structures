#include<stdio.h>
int count = 0;
void hanoi(char F, char T, char U, int N)
{
    count ++;
    if(N == 1)
    {
        printf("Move %d : %c to %c\n",N,F,T);
    }

    else
    {
    hanoi(F,U,T,N-1);
    printf("Move %d : %c to %c\n",N,F,T);
    hanoi(U,T,F,N-1);
    }
}

void main()
{
    int p;
    printf("Enter the count of platters : ");
    scanf("%d",&p);
    hanoi('A','C','B',p);
    printf("Number of calls to Hanoi are : %d\n",count);
}

/*
OUTPUT
Enter the count of platters : 4
Move 1 : A to B
Move 2 : A to C
Move 1 : B to C
Move 3 : A to B
Move 1 : C to A
Move 2 : C to B
Move 1 : A to B
Move 4 : A to C
Move 1 : B to C
Move 2 : B to A
Move 1 : C to A
Move 3 : B to C
Move 1 : A to B
Move 2 : A to C
Move 1 : B to C
Number of calls to Hanoi are : 15 */
