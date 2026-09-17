#include <stdio.h>
#include <stdlib.h>
typedef struct doubley
{
    int data;
    struct doubley*prev,*next;
}dl;
dl*head=NULL,*tail=NULL;

dl* create(int val){
    dl *p=NULL;
    p=malloc(sizeof(dl));
    p->next=NULL;p->prev=NULL;
    if(p!=NULL)p->data=val;
    return p;
}
void InsertFront(int val){
    dl*p=create(val);
    if(head==NULL){
        head=tail=p;
        p->prev=NULL;
        p->next=NULL;}
    else{
    p->next=head;
    head->prev=p;
    p->prev=NULL;
    head=p;
}}
void InsertEnd(int val){
    dl*p=create(val);
    if(head==NULL)
    {
        head=tail=p;
        p->prev=NULL;
        p->next=NULL;
    }else{
    p->prev=tail;
    tail->next=p;
    p->next=NULL;
    tail=p;
}}
void display(){
    if(head==NULL){printf("empty");return;}
    dl*t=head;
    while(t){
        printf("%d ",t->data);
        t=t->next;
    }
}
void size(){
    dl*t=head;int c=0;
    while(t){
        c++;
        t=t->next;
    }
    printf("size:%d\n",c);
}
void middle(){
    if(head==NULL){
        printf("empty");return;
    }
    dl*slow=head,*fast=head;
    while (fast != NULL && fast->next != NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("middle:%d",slow->data);
}
void DeleteFront(){
    if(head==NULL){
        printf("empty");
        return;
    }
    dl*t=head;
    head=head->next;
    free(t);
    t=NULL;
}
void DeleteEnd(){
    if(head==NULL){
        printf("empty");
        return;
    }
    dl*t=head;
     if (head->next == NULL) {
        free(head);
        head = NULL;
        tail = NULL; 
        printf("Node deleted from end.\n");
        return;
    }
    while(t->next->next||t->next){
        t=t->next;
    }
    t->next=NULL;
    tail=t;
    t=t->next;
    free(t);  
}
void InsertAny(int val,int pos){
    dl*p=create(val);
    dl*t=head;
    int i=1;
    while(i<pos){
        t=t->next;i++;
    }
    t->next=p;
    p->prev=t;
    p->next=t->next;
    t->next->prev=p;
}
int main() {
    int ch=0,x,pos;
    while(ch!=10){
        printf("\n1.insert node at front\n2.insert node at emd\n3.insert node at specific position\n4.delete from front\n5.delete from end\n6.delete from any specific position\n7.find size\n8.find middle\n9.Display\n10.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter data to enter in front:");
                scanf("%d",&x);  InsertFront(x);
                break;
            case 2:printf("enter data to enter in end:");
                scanf("%d",&x);  InsertEnd(x);
                break;
            case 3:printf("enter data:");scanf("d",&x);
                printf("enter position:");scanf("d",&pos);
                InsertAny(x,pos);
            case 4:DeleteFront();break;
            case 5:DeleteEnd();break;
            case 7:size();break;
            case 8:middle();break;
            case 9:display();break;
            case 10:printf("exiting...");break;
            
        }
        
    }
    return 0;
}
