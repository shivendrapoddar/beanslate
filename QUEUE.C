#include<stdio.h>
#include<conio.h>
#define max 10
void initlq();
void insertlq(int);
int isfulllq();
int deletelq();
int isemptylq();
void displaylq();
int sizelq();
struct LQueue
{
int lq[max];
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
	case 1:initlq();
		break;
	case 2:printf("\n enter the value to insert in queue");
		scanf("%d",&x);
		insertlq(x);
		break;
		case 3:y=deletelq();
		if(y!=-999)
		printf("the deleted value is\n",y);
		break;
	case 4:displaylq();
		break;
	case 5: y=isfulllq();
		if(y==1)
		printf("queue is full");
		else
		printf("not full");
		break;
	case 6:y=isemptylq();
		if(y==1)
		printf("empty");
		else
		printf("stack is full");
		break;
	case 7: y=sizelq();
		printf("\n the size%d",y);
		break;
	case 8:exit(0);
	default:printf("you have given a wrong choice");
	}}
	while (ch!=8);
	getch();
	}
void initlq()
{
q.rear=q.front=-1;
}
	void insertlq(int x)
	{
	if(isfulllq())
	printf("\nqueue is overflow");
	else
	{
	if(isemptylq())
	q.rear=q.front=0;
	else
	q.rear++;
	q.lq[q.rear]=x;

	}
	}
int isfulllq()
{
if(q.rear==(max-1))
return 1;
else
return 0;
}
	int isemptylq()
	{
	if(q.front==-1)
	return 1;
	else
	return 0;
	}
int deletelq()
{
if (isemptylq())
{
printf("\n underflow queue");
}
else
{
int y;
y=q.lq[q.front];
if(q.rear==q.front)
initlq();
else
q.front++;
return y;
}}
	void displaylq()
	{
	if(!isemptylq())
	{
	int i;
	for (i=q.front;i<q.rear;i++)
	printf("%d\n",q.lq[i]);
	}}
int sizelq()
{
if(!isemptylq())
{
int length=q.rear-q.front;
return (length);
}
}









