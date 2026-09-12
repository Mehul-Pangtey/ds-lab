#include <stdlib.h>
#include <stdio.h>
typedef struct list{
    int data;struct list* next;}sl;
sl *f=NULL,*r=NULL;
// create a single node
sl* create(int val){
    sl *p = (sl*)malloc(sizeof(sl));

    if(p == NULL)
        return NULL;

    p->data = val;
    p->next = NULL;

    return p;
}

// insert front
void innsert_l(int val){
    sl *p = create(val);

    if(p == NULL)
        return;

    if(f == NULL){
        f = r = p;
    }
    else{
        p->next = f;
        f = p;
    }
}

// insert right
void insert_r(int val){
    sl *p = create(val);

    if(p == NULL)
        return;

    if(f == NULL){
        f = r = p;
    }
    else{
        r->next = p;
        r = p;
    }
}

// insert anywhere
void insert_a(int pos, int val){
    if(pos <= 0)
        return;

    if(pos == 1){
        innsert_l(val);
        return;
    }

    sl *temp = f;

    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    sl *p = create(val);

    if(p == NULL)
        return;

    p->next = temp->next;
    temp->next = p;

    if(p->next == NULL)
        r = p;
}

//display
void display(){
    sl *temp = f;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main(){
int ch=0,pos;int val;
while(ch!=11){
    printf("\n1.insert from front\n2.insert from end\n3.insert anywhere\n4.delete front\n5.delete end\n6.delete anywhere\n7.sizr\n8.isempty\n9.find middle\n10.display\n11.exit\n");
    scanf("%d",&ch);
    switch(ch){   
        case 1:printf("enter data:");
            scanf("%d",&val);
            innsert_l(val);break;
        case 2:printf("enter data:");
            scanf("%d",&val);
            insert_r(val);break;
        case 3:
            printf("enter position:");scanf("%d",&pos);
            printf("enter data:");
            scanf("%d",&val);
            insert_a(pos,val);break;
        case 4:break;
        case 5:break;
        case 6:break;
        case 7:break;
        case 8:break;
        case 9:break;
        case 10:display();break;
        case 11:printf("exitng..");break;
    }

}
}
