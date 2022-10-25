#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};
struct node *create(struct node *head,int i){
struct node *ptr;
ptr=(struct node *) malloc(sizeof(struct node));
printf("Enter data[%d]:",i);
scanf("%d",&ptr->data);
     ptr->next=NULL;
     ptr->prev=NULL;
     struct node *p;
     if(head==NULL){
      head=ptr;
      p=head;
      return head;
}
else{
p->next=ptr;
ptr->prev=p;
p=ptr;
return head;
}
}
struct node *insert_beg(struct node *head){
struct node *ptr;
ptr=(struct node *) malloc(sizeof(struct node));
printf("Enter data for insert a beginning:");
scanf("%d",&ptr->data);
ptr->next=head;
ptr->prev=NULL;
return ptr;
}
struct node *insert_pos(struct node *head){
struct node *ptr;
ptr=(struct node *) malloc(sizeof(struct node));
int i=1,pos;
printf("Enter position for insert data:");
scanf("%d",&pos);
printf("Enter data for insert at given position:");
scanf("%d",&ptr->data);
struct node *p=head;
while(i!=pos){
p=p->next;
i++;
}
ptr->next=p->next;
p->next=ptr;
ptr->prev=p;
return head;
}
struct node *delete_pos(struct node *head){
int i=1,pos;
printf("Enter position for delete data:");
scanf("%d",&pos);
struct node *p=head;
struct node *q=p->next;
while(i!=pos){
p=p->next;
q=p->next;
i++;
}
p->next=q->next;
q->next->prev=p;
free(q);
return head;
}
void print(struct node *ptr){
int i=1;
while(ptr!=NULL){
printf("data at node[%d]:%d\n",i,ptr->data);
ptr=ptr->next;
i++;
   }
}
int main(){
int i;
struct node *head=NULL;
for(i=0;i<3;i++){
head=create(head,i+1);
}
print(head);
head=insert_beg(head);
print(head);

head=insert_pos(head);
print(head);

head=delete_pos(head);
print (head);
return 0;
}