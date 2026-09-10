#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void insert(struct node**head){
    struct node*p;
    struct node**q;
    int x;

    printf("Enter value: ");
    scanf("%d",&x);

    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;

    q=head;

    while(*q!=NULL&&(*q)->data<x){
        q=&(*q)->next;
    }

    p->next=*q;
    *q=p;
}

void display(struct node*head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node*head=NULL;
    int ch;

    while(1){
        printf("\n1.Insert\n");
        printf("2.Display\n");
        printf("3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                insert(&head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
