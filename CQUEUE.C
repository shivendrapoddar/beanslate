#include<stdio.h>
#include<conio.h>
#define max 5
void initcq();
void insertcq(int);
int isfullcq();
int deletecq();
int isemptycq();
void displaycq();
int sizecq();
struct CQueue
{
int cq[max];
int rear,front;
}q;
	void main()
	{
	int ch,x,y;
	do
	{
	printf("\n|____MENU_____");
	printf("\n 1.initilization:\n 2 .INSERT LQ:\n 3DELETE LQ:\n 4.display LQ:\n 5 isfull \n6.isempty:\n7.sieof:\n8.exit");
	printf("\n enter your choice");
	scanf("%d",& ch);
	switch(ch)
	{
	case 1:initcq();
		break;
	case 2:printf("\n enter the value to insert in queue");
		scanf("%d",&x);
		insertcq(x);
		break;
		case 3:y=deletecq();
		if(y!=-999)
		printf("the deleted value is\n",y);
		break;
	case 4:displaycq();
		break;
	case 5: y=isfullcq();
		if(y==1)
		printf("queue is full");
		else
		printf("not full");
		break;
	case 6:y=isemptycq();
		if(y==1)
		printf("empty");
		else
		printf("stack is not full");
		break;
	case 7: y=sizecq();
		printf("\n the size%d",y);
		break;
	case 8:exit(0);
	default:printf("you have given a wrong choice");
	}}
	while (ch!=8);
	getch();
	}
void initcq()
{
q.rear=q.front=-1;
}
	void insertcq(int x)
	{
	if(isfullcq())
	printf("\nqueue is overflow");
	else
	{
	if(isemptycq())
	q.rear=q.front=0;
	else if(q.rear==max-1)
	q.rear=0;
	else
	q.rear++;
	q.cq[q.rear]=x;

	}
	}
int isfullcq()
{
if((q.front==(q.rear+1))||(q.front==0&&q.rear==(max-1)))
return 1;
else
return 0;
}
	int isemptycq()
	{
	if(q.front==-1)
	return 1;
	else
	return 0;
	}
int deletecq()
{
if (isemptycq())
{
printf("\n underflow queue");
}
else
{
int y;
y=q.cq[q.front];
if(q.rear==q.front)
initcq();
else
q.front=(q.front+1)%max;
//q.front++;
return y;
}}
	void displaycq()
	{
	if(!isemptycq())
	{
	int i;
	if(q.rear>=q.front)
	{
	for (i=q.front;i<=q.rear;i++)
	printf("%d\n",q.cq[i]);
	}
	else
	{
	for(i=q.front;i<max;i++)
	printf("%d\n",q.cq[i]);
	for (i=0;i<=q.rear;i++)
	printf("%d\n",q.cq[i]);
	 }
	}}
int sizecq()
{
int length;
if(!isemptycq())
{
if(q.rear>q.front)
 length=q.rear-q.front+1;
else
length=max-q.front+q.rear+1;
return (length);
}
}









