#include<stdio.h>
#include<stdlib.h>

struct node{
int value;
struct node * nptr;
};

struct node* addempty(struct node*h,int val){
if(h!= NULL)
return h;
struct node * temp=(struct node*)malloc(sizeof(struct node));
temp->value= val;
h=temp;
h->nptr=h;
return h;
}




struct node * insertatfront(struct node*h,int val){
if ( h==NULL)
return addempty(h,val);

struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->value = val;
temp->nptr = h->nptr;
h->nptr=temp;
return h;
}




struct node* insertatend(struct node*h,int val){
if(h==NULL){
return addempty(h,val);
}
struct node * temp= (struct node*)malloc (sizeof(struct node));
temp->value=val;
temp->nptr=h->nptr;
h->nptr=temp;
h=temp;
return h;
}


struct node* insertinorder(struct node* h,int val){
if(h==NULL){
return addempty(h,val);
}
struct node* t;
struct node* temp = (struct node*)malloc(sizeof(struct node));
t=h->nptr;
if(t->value>val){
temp->value=val;
temp->nptr=t;
h->nptr=temp;
return h;
}
while((t->nptr!=h->nptr) && (t->nptr)->value<val)
    t=t->nptr;
temp->value=val;
temp->nptr=t->nptr;
t->nptr=temp;
if(val>h->value){
h=temp;
return h;
}
else{
return h;
}
}


struct node* insertbefore(struct node* h,int val,int v){
if(h==NULL){
return addempty(h,val);
}
struct node* t;
struct node* temp = (struct node*)malloc(sizeof(struct node));
t=h->nptr;
if(t->value>val){
temp->value=val;
temp->nptr=t;
h->nptr=temp;
return h;
}
while(t->nptr!=h->nptr && (t->nptr)->value!=v)
t=t->nptr;
temp->value=val;
temp->nptr=t->nptr;
t->nptr=temp;
return h;
}

void display(struct node * h){
struct node * p;
if(h==NULL)
printf("The List Is Empty\n");

p=h->nptr;
do {
printf("%d\n",p->value);
p=p->nptr;
}while(p!=h->nptr);
}

struct node* delatfront(struct node * h)
{
h->nptr=(h->nptr)->nptr;
return h;
}

struct node * delatlast(struct node * h){
struct node * temp;
temp = h->nptr;
while((temp->nptr)->nptr!=h->nptr)
temp=temp->nptr;
struct node * ntd;
ntd = temp->nptr;
temp->nptr=h->nptr;
h->nptr=NULL;
h=temp;
free(ntd);
return h;
}

struct node* Delete(struct node* H,int val)
{
    struct node* temp,* nodetobedeleted;
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
            H = temp->nptr;
            printf("Deleted value is %d\n",nodetobedeleted->value);
            free(nodetobedeleted);
            return H;
        }
        else
        {   while(temp->nptr!=NULL && (temp->nptr)->value!=val)
                temp = temp->nptr;

            if(temp->nptr == NULL)
            {
                printf("Not Found\n");
                return H;
            }
            else
            {
                nodetobedeleted = temp->nptr;
                temp->nptr = (temp->nptr)->nptr;
                printf("Deleted value is %d\n",nodetobedeleted->value);
                free(nodetobedeleted);
                return H;
            }
        }
    }
}


void main(){
struct node * head = NULL;
head = addempty(head,20);
head = insertatfront(head,10);
head = insertatfront(head,67);
head = insertatend(head,43);
head = delatfront(head);
head = delatlast(head);
head = insertinorder(head,15);
head = insertbefore(head,30,15);
display(head);
}

/*OUTPUT
10
30
15
20
*/
