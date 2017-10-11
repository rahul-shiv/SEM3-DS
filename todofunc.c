#include "todohead.h"

void display(struct node* temp, int cutoff, int stat){
    if(temp==NULL){
        printf("NO WORK TO DO! GO HAVE SOME FUN!!\n");
        return;
    }
    int i=1;
    while (temp!=NULL) {
        if(temp->priority<cutoff && stat==temp->status){
            printf("\nTask Number : %d\n",i);
            printf("Task Name : %s",temp->task);
            printf("Task Priority : %d\n",temp->priority);
            printf("Submission Date : %d/%d/%d\n",(temp->date).tm_wday,(temp->date).tm_mon,(temp->date).tm_year);
        }
        temp=temp->next;
        i+=1;
    }
}

int compare_date(struct node*temp,struct node*curr)
{
  if((temp->date).tm_year>(curr->date).tm_year)
    return 1;
  else if((temp->date).tm_year<(curr->date).tm_year)
    return 0;
  if((temp->date).tm_mon>(curr->date).tm_mon)
    return 1;
  else if((temp->date).tm_mon<(curr->date).tm_mon)
    return 0;
  if((temp->date).tm_wday>(curr->date).tm_wday)
    return 1;
  else if((temp->date).tm_wday<(curr->date).tm_wday)
    return 0;
  if(temp,curr)
    return 0;
}
int date_equal(struct node *temp,struct node *curr)
{
  if((temp->date).tm_year==(curr->date).tm_year)
    return 1;
  if((temp->date).tm_mon==(curr->date).tm_mon)
    return 1;
  if((temp->date).tm_wday==(curr->date).tm_wday)
    return 1;
  return 0;
}
void insert(struct node** list)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->next=NULL;
  printf("Enter the following details! \n");
  char name[100];
  printf("Name of your task : ");
  scanf("\n");
  fgets(name,100,stdin);
  int priority;
  printf("Priority in 1-5 : ");
  scanf("%d",&priority);
  struct tm date;
  printf("Date in DD MM YYYY format : ");
  scanf("%d%d%d",&date.tm_wday,&date.tm_mon,&date.tm_year );
  strcpy(temp->task,name);
  temp->priority=priority;
  temp->date=date;
  temp->status=0;


  if(*list==NULL)
  {
    *list=temp;
    return;
  }
  struct node *curr;
  struct node *prev;
  prev=NULL;
  curr=*list;
  while((curr!=NULL)&&(compare_date(temp,curr)))
  {
    prev=curr;
    curr=curr->next;
  }
  if(date_equal(temp,prev))
  {
      curr=prev;
      while((curr!=NULL)&&date_equal(temp,curr)&&(curr->priority<=temp->priority))
      {
        prev=curr;
        curr=curr->next;
      }
  }
    if(curr==NULL)
  {
    prev->next=temp;
    return;
  }
  else
  {
    if(prev==NULL)
    {
      temp->next=curr;
      *list=temp;
    }
    else
    {
      prev->next=temp;
      temp->next=curr;
    }

}
}


void delete_task(struct node ** first)
{
  char a,name[20];
  struct node *current,*prev;
  prev=NULL;
  current=*first;
  printf("\nEnter the name of the task you wish to delete: ");
  scanf("\n");
  fgets(name,100,stdin);
  while((current!=NULL)&&(strcmp(current->task,name)!=0))
  {
    prev=current;
    current=current->next;
  }
  if(current==NULL)
    printf("This task does not exist\n");

else{
    printf("Task Name : %s",current->task);
    printf("Task Priority : %d\n",current->priority);
    printf("Submission Date : %d/%d/%d\n",(current->date).tm_wday,(current->date).tm_mon,(current->date).tm_year);
    printf("\nDo you wish to delete above task (y/n) : ");
    scanf("%c",&a);
    if (a=='y'||a=='Y'){
          if(prev==NULL)
            *first=current->next;
          else
            prev->next=current->next;
          free(current);
      }
  }
}

void task_completed(struct node**first)
{
  struct node *n=*first;
  char name[100];
  printf("\nEnter name of task completed : ");
  scanf("\n");
  fgets(name,100,stdin);
  while(n!=NULL&&strcmp(n->task,name)!=0)
  {
    n=n->next;
  }
  if(n!=NULL)
  {
    if(strcmp(n->task,name)==0){
      n->status=1;
     printf("Congrats on completing a task.\n");
    }
  }

  if (n->status!=1){
      printf("This task does not exist\n");
  }
}
