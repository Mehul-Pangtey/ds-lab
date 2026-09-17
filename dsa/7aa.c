#include <stdlib.h>
#include <stdio.h>

typedef struct list{
    int data;
    struct list *next;
}sl;

sl *f=NULL,*r=NULL;

// create a single node
sl* create(int val){
    sl *p=(sl*)malloc(sizeof(sl));

    if(p==NULL)
        return NULL;

    p->data=val;
    p->next=NULL;

    return p;
}

// insert front
void innsert_l(int val){
    sl *p=create(val);

    if(p==NULL)
        return;

    if(f==NULL){
        f=r=p;
    }
    else{
        p->next=f;
        f=p;
    }
}

// insert end
void insert_r(int val){
    sl *p=create(val);

    if(p==NULL)
        return;

    if(f==NULL){
        f=r=p;
    }
    else{
        r->next=p;
        r=p;
    }
}

// insert anywhere
void insert_a(int pos,int val){
    if(pos<=0)
        return;

    if(pos==1){
        innsert_l(val);
        return;
    }

    sl *temp=f;

    for(int i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL)
        return;

    sl *p=create(val);

    if(p==NULL)
        return;

    p->next=temp->next;
    temp->next=p;

    if(p->next==NULL)
        r=p;
}

// delete front
void delete_f(){
    if(f==NULL){
        printf("List Empty\n");
        return;
    }

    sl *temp=f;
    f=f->next;
    free(temp);

    if(f==NULL)
        r=NULL;
}

// delete end
void delete_r(){
    if(f==NULL){
        printf("List Empty\n");
        return;
    }

    if(f==r){
        free(f);
        f=r=NULL;
        return;
    }

    sl *temp=f;

    while(temp->next!=r)
        temp=temp->next;

    free(r);
    r=temp;
    r->next=NULL;
}

// delete anywhere
void delete_a(int pos){
    if(f==NULL || pos<=0)
        return;

    if(pos==1){
        delete_f();
        return;
    }

    sl *temp=f;

    for(int i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL || temp->next==NULL)
        return;

    sl *p=temp->next;
    temp->next=p->next;

    if(p==r)
        r=temp;

    free(p);
}

// size
int size(){
    int c=0;
    sl *temp=f;

    while(temp!=NULL){
        c++;
        temp=temp->next;
    }

    return c;
}

// isempty
void isempty(){
    if(f==NULL)
        printf("List is Empty\n");
    else
        printf("List is Not Empty\n");
}

// find middle
void middle(){
    if(f==NULL){
        printf("List Empty\n");
        return;
    }

    sl *slow=f,*fast=f;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    printf("Middle = %d\n",slow->data);
}

// display
void display(){
    sl *temp=f;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int ch=0,pos,val;

    while(ch!=11){

        printf("\n1.Insert Front");
        printf("\n2.Insert End");
        printf("\n3.Insert Anywhere");
        printf("\n4.Delete Front");
        printf("\n5.Delete End");
        printf("\n6.Delete Anywhere");
        printf("\n7.Size");
        printf("\n8.IsEmpty");
        printf("\n9.Find Middle");
        printf("\n10.Display");
        printf("\n11.Exit\n");

        scanf("%d",&ch);

        switch(ch){

        case 1:
            printf("Enter data: ");
            scanf("%d",&val);
            innsert_l(val);
            display();
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d",&val);
            insert_r(val);
            display();
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
            printf("Enter data: ");
            scanf("%d",&val);
            insert_a(pos,val);
            display();
            break;

        case 4:
            delete_f();
            display();
            break;

        case 5:
            delete_r();
            display();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d",&pos);
            delete_a(pos);
            display();
            break;

        case 7:
            printf("Size = %d\n",size());
            break;

        case 8:
            isempty();
            break;

        case 9:
            middle();
            break;

        case 10:
            display();
            break;

        case 11:
            printf("Exiting...");
            break;
        }
    }
}
