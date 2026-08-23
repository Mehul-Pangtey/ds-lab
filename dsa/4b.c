#include <stdio.h> 
#define max 20
void push(int arr[], int *top, int val, int step) {
    *top += step; 
    arr[*top] = val; 
}
int pop(int arr[],int *top,int step){
    if(step==1) return arr[(*top)--];
    else return arr[(*top)++];
} 

int main() {

    int arr[max]={0};
    int top = -1;    
    int top1 = max;
    int ch;
    while(ch!=6){
        printf("\n1.push to stack1\n2.push to stack2\n3.pop from 1\n4.pop from 2\n5.display\n6.exit\n");
        scanf("%d",&ch);
        int val;
        switch(ch){
            case 1:printf("enter value:");
            scanf("%d",&val);
            push(arr, &top, val, 1); 
            break;

            case 2:printf("enter valueL:");
            scanf("%d",&val);
            push(arr, &top1, val, -1);
            break;

            case 3:printf("value poped:%d",pop(arr,&top,1));
            break;
            case 4:printf("value popped:%d",pop(arr,&top1,-1));
            break;
            case 5:  printf("Full Array Content: ");
             for (int i = 0; i < max; i++) {
                printf("%d ", arr[i]);
                }
                break;
            case 6:ch=5;exit(1);
        }
    }    
  

    return 0;
}

