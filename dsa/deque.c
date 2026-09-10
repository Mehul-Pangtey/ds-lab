#include <stdio.h>
#define max 100
int dq[max];
int front=-1,rear=-1;
void enqfront(int value);
void enqrear(int value);
void deqfront();
void deqrear();
void isfull();
void isempty();
void dispfront();
void disprear();
int main(){
    int ch,x;
    while(ch!=9){
        printf("\n1.enque from front\n2.Enque from rear\n3.deque from Front");
        printf("\n4.Delete from rear\n5.dispplay from front\n6.display frm rear\n7.is empty\n8.isfull\n9.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter value to ener in front:");
            scanf("%d",&x);
            enqfront(x);break;

            case 2:printf("enter value to enter in rear:");
            scanf("%d",&x);
            enqrear(x);break;

            case 3:deqfront();break;

            case 4:deqrear();break;

            case 5:dispfront();break;

            case 6:disprear();break;

            case 7:isempty();break;

            case 8:isfull();break;
            case 9:printf("exiting...");

            default:printf("invalid choice");
        }
    }
}
void enqrear(int value){
    if(rear==max-1)printf("full");
    
    if(front==-1)front=rear=0;
    else rear++;
    dq[rear]=value;
}
void enqfront(int value){
    if((front == 0 && rear ==max-1)){printf("full");return;}
    if(front==0){printf("cant write at oth index");return;}
    if(front==-1)front=rear=0;
    else front--;
    dq[front]=value;
}
void deqfront(){
    if(front==-1)printf("empty");
    printf("element removed:%d",dq[front]);
    if(front==rear)front=rear=-1;
    else front++;
}
void deqrear(){
    if(rear==-1)printf("empty");
    printf("element removed:%d",dq[rear]);
    if(rear==front)front=rear=-1;
    else rear--;
}
void dispfront(){
    if(front==-1){printf("empty");return;}
    int i;
    i=front;
    while(i<=rear){printf("%d ",dq[i]);
        i++;}}

void disprear(){
    if(rear==-1)printf("empty");
    int i=rear;
    while(i>=front){printf("%d ",dq[i]);
    i--;}
}
void isfull(){
    if((front==0&&rear==max-1)||(front==rear+1))
    printf("full");
    else printf("not full");
}
void isempty(){
    if(front==-1)printf("empty");
    else printf("not empty");
}
