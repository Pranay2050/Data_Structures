#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
    int value;
    struct Node* ptr;
};
//Insert at front
struct Node* insertatfront(struct Node* H,int val)
{
    struct Node* new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        printf("Malloc Failed\n");
        exit(-1);
    }

    if(H == NULL)
    {
        new_node->value = val;
        new_node->ptr = NULL;
        H = new_node;
        printf("Entered value is %d\n",H->value);
        return H;
    }
    else
    {
        new_node->value = val;
        new_node->ptr = H;
        H = new_node;
        printf("Entered value is %d\n",H->value);
        return H;
    }

}
//Insert at end
struct Node* insertatend(struct Node* H,int val)
{
    struct Node* new_node,* temp;
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        printf("Malloc Failed\n");
        exit(-1);
    }
    if(H == NULL)
    {
        new_node->value = val;
        new_node->ptr = NULL;
        H = new_node;
        printf("Entered value is %d\n",H->value);
        return H;
    }
    temp = H;
    while(temp->ptr!=NULL)
        temp = temp->ptr;
    new_node->value = val;
    new_node->ptr = NULL;
    temp->ptr = new_node;
    printf("Entered value is %d\n",new_node->value);
    return H;
}
//Insert in order
struct Node* insertinorder(struct Node* H,int val)
{
    struct Node* new_node,* temp;
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        printf("Malloc Failed\n");
        exit(-1);
    }

    if(H == NULL || val<(H->value))
    {
        new_node->value = val;
        new_node->ptr = H;
        H = new_node;
        printf("Entered value is %d\n",H->value);
        return H;
    }
    temp = H;
    while(temp->ptr!=NULL &&((temp->ptr)->value)<val)
        temp = temp->ptr;

    new_node->value = val;
    new_node->ptr = temp->ptr;
    temp->ptr = new_node;
    printf("Entered value is %d\n",new_node->value);
    return H;
}
//Insert before node with value v
struct Node* insertbefore(struct Node* H,int val,int v)
{
    struct Node* new_node,* temp;
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        printf("Malloc Failed\n");
        exit(-1);
    }
    temp = H;
    if(temp->value == v)
    {
        new_node->value = val;
        new_node->ptr = temp;
        H = new_node;
        printf("Entered value is %d\n",H->value);
        return H;
    }
    while((temp->ptr)->value!=v && temp->ptr != NULL)
        temp = temp->ptr;
    if(temp->ptr == NULL)
    {
        printf("The node with value %d not found\n",v);
        exit(-1);
    }
    else
    {
        new_node->value = val;
        new_node->ptr = temp->ptr;
        temp->ptr = new_node;
        printf("Entered value is %d\n",new_node->value);
        return H;
    }
}
//Insert after node with value v
struct Node* insertafter(struct Node* H,int val,int v)
{
    struct Node* new_node,* temp;
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        printf("Malloc Failed\n");
        exit(-1);
    }
    temp = H;
    while(temp->ptr != NULL && temp->value != v)
        temp = temp->ptr;
    if(temp->value != v)
    {
        printf("The node with value %d not found\n",v);
        exit(-1);
    }
    else if(temp->value == v)
    {
        new_node->value = val;
        new_node->ptr = NULL;
        temp->ptr = new_node;
        printf("Entered value is %d\n",new_node->value);
        return H;
    }
    else
    {
        new_node->value = val;
        new_node->ptr = temp->ptr;
        temp->ptr = new_node;
        printf("Entered value is %d\n",new_node->value);
        return H;
    }
}
//Display function
int Display(struct Node* H)
{
    struct Node* temp;
    if(H == NULL)
    {
        printf("\nList is empty\n");
        return 0;
    }
    else
    {
        temp = H;
        printf("\nThe list elements are:\n");
        while(temp->ptr!=NULL)
        {
            printf("%d\n",temp->value);
            temp = temp->ptr;
        }
        printf("%d\n",temp->value);
        return 0;
    }
}
//Delete at front
struct Node* Deleteatfront(struct Node* H)
{
    struct Node* nodetobedeleted;
    if(H == NULL)
    {
        printf("List is empty\n");
        return H;
    }
    else
    {
        nodetobedeleted = H;
        printf("Deleted value is %d\n",nodetobedeleted->value);
        if(H->ptr!=NULL)
        {
            H = H->ptr;
            free(nodetobedeleted);
            return H;
        }
        else
        {
            free(nodetobedeleted);
            H = NULL;
            return H;
        }

    }
}
//Delete at end
struct Node* Deleteatend(struct Node* H)
{
    struct Node* temp,* nodetobedeleted;
    if(H == NULL)
    {
        printf("List is empty\n");
        return H;
    }
    else
    {
        temp = H;
        if(temp->ptr == NULL)
        {
            nodetobedeleted = temp;
            H = NULL;
            printf("Deleted value is %d\n",nodetobedeleted->value);
            free(nodetobedeleted);
            return H;
        }
        while((temp->ptr)->ptr!=NULL)
            temp = temp->ptr;
        nodetobedeleted = temp->ptr;
        temp->ptr = NULL;
        printf("Deleted value is %d\n",nodetobedeleted->value);
        free(nodetobedeleted);
        return H;
    }
}
//Delete node with value val
struct Node* Delete(struct Node* H,int val)
{
    struct Node* temp,* nodetobedeleted;
    if(H == NULL)
    {
        printf("List is empty\n");
        return H;
    }
    else
    {
        temp = H;
        if(temp->value == val)
        {
            nodetobedeleted = temp;
            H = temp->ptr;
            printf("Deleted value is %d\n",nodetobedeleted->value);
            free(nodetobedeleted);
            return H;
        }
        else
        {   while(temp->ptr!=NULL && (temp->ptr)->value!=val)
                temp = temp->ptr;

            if(temp->ptr == NULL)
            {
                printf("Not Found\n");
                return H;
            }
            else
            {
                nodetobedeleted = temp->ptr;
                temp->ptr = (temp->ptr)->ptr;
                printf("Deleted value is %d\n",nodetobedeleted->value);
                free(nodetobedeleted);
                return H;
            }
        }
    }
}
int main()
{
    struct Node* Head;
    Head = NULL;

    Head = insertatfront(Head,10);
    Head = insertatfront(Head,20);
    Head = insertatfront(Head,8);
    Head = insertatfront(Head,99);
    Head = insertatfront(Head,35);
    Head = insertatfront(Head,30);
    Head = insertatend(Head,101);
    Head = insertinorder(Head,100);
    Head = insertbefore(Head,38,10);
    Head = insertafter(Head,50,101);

    //Display(Head);

    Head = Delete(Head,20);
    Head = Deleteatfront(Head);
    Head = Deleteatfront(Head);

    //Display(Head);

    Head = Deleteatend(Head);
    Head = Deleteatend(Head);

    Display(Head);
}

/*OUTPUT

Entered value is 10
Entered value is 20
Entered value is 8
Entered value is 99
Entered value is 35
Entered value is 30
Entered value is 101
Entered value is 100
Entered value is 38
Entered value is 50
Deleted value is 20
Deleted value is 30
Deleted value is 35
Deleted value is 50
Deleted value is 101

The list elements are:
99
8
38
10
100
*/
