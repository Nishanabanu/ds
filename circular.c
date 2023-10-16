#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int que[SIZE];
int front=0,rear=0;
void main()
{
void enque(int);
int deque();
int search(int),ans;
int option,item;
do
{
printf("\n 1.insert\n");
printf("\n 2.delete\n");
printf("\n 3.search\n");
printf("\n 4.exit\n");
printf("option:");
scanf("%d",&option);
switch(option)
{
 case 1:printf("item:");
         scanf("%d",&item);
         enque(item);
         break;
 case 2:item=deque();
        printf("item=%d",item);
        break;
 case 3:printf("item to search:");
        scanf("%d",&item);
        ans=search(item);
        if(ans != 0)
        printf("%d found at %d\n",item,ans);
        else
        printf("%d not found\n",item);
        break;
 case 4:exit(0);
 }
 }
 while(1); 
 }
 //function to insert an item in circular queue
 void enque(int item)
 {
 int t;
 t=(rear+1)%SIZE;
 if(t==front)
 {
 printf("queue is full");
 printf("\n");
 exit(1);
 }
 else
 {
 rear=t;
 que[rear]=item;
 }
 }
 
//function to delete an item
int deque()
{
if(front==rear)
{
printf("que is empty");
printf("\n");
exit(2);
}
front=(front+1)%SIZE;
return que[front];
}
//function to search an item
int search(int item)
{
int t1,t2;
t1=front,t2=rear;
t1=(t1+1)%SIZE;
while(t1 != t2 && que[t1] != item)
t1=(t1+1)%SIZE;
if(que[t1]==item)
return t1;
else
return 0;
}
