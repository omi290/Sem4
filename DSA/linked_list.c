#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *create(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(struct Node **h,int d){
    struct Node *p=create(d);
    if(*h==NULL){
        *h=p;
        return;
    }
   
     if ((*h)->data > d) {  // Insert at the beginning
        p->next = *h;
        *h = p;
        return;
    }

    // General case: find the correct position to insert
    struct Node *temp = *h;
    while (temp->next != NULL && temp->next->data < d) {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
}
void display(struct Node *h){
    struct Node *temp=h;
     while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}




int main(){
    struct Node *head1=NULL;
    insert(&head1,10);
    insert(&head1,5);
    insert(&head1,20);
    insert(&head1,30);
    insert(&head1,25);
    display(head1);
    return 0;
}