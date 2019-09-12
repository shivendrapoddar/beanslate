#include<stdio.h>
#include<conio.h>
#define max 10
void initdqi();
void insertdqi(int);
int isfulldqi();
int deletedqifront();
int deletedqirear();
int isemptydqi();
void displaydqi();
int sizedq();
struct DIQueue
{
int dqi[max];
int rear,front;
}q;
	void main()
	{
	int ch,x,y;
	do
	{
	printf("\n|____MENU_____");
	printf("\n1.initilization:\n2.INSERT LQ:\n3.DELETE LQ FROM FRONT:\n4.DELETE LQ FROM REAR:\n5.display LQ:\n6.isfull \n7.isempty:\n8.sieof:\n9.exit");
	printf("\n enter your choice");
	scanf("%d",& ch);
	switch(ch)
	{
	case 1:initdqi();
		break;
	case 2:printf("\n enter the value to insert in queue");
		scanf("%d",&x);
		insertdqi(x);
		break;
	case 3:y=deletedqifront();
		if(y!=-999)
		printf("the deleted value is\t%d\n",y);
		break;
	case 4:y=deletedqirear();
		if(y!=-999)
		printf("the deleted value is\t%d\n",y);
		break;
	case 5:displaydqi();
		break;
	case 6: y=isfulldqi();
		if(y==1)
		printf("queue is full");
		else
		printf("not full");
		break;
	case 7:y=isemptydqi();
		if(y==1)
		printf("empty");
		else
		printf("stack is not full");
		break;
	case 8: y=sizedqi();
		printf("\n the size%d",y);
		break;
	case 9:exit(0);
	default:printf("you have given a wrong choice");
	}}
	while (ch!=9);
	getch();
	}
void initdqi()
{
q.rear=q.front=-1;
}
	void insertdqi(int x)
	{
	if(isfulldqi())
	printf("\nqueue is overflow");
	else
	{
	if(isemptydqi())
	q.rear=q.front=0;
	else if(q.rear==max-1)
	q.rear=0;
	else
	q.rear++;
	q.dqi[q.rear]=x;

	}
	}
int isfulldqi()
{
if((q.front==(q.rear+1))||(q.front==0&&q.rear==(max-1)))
return 1;
else
return 0;
}
	int isemptydqi()
	{
	if(q.front==-1/*||q.front==(q.rear-1)*/)
	return 1;
	else
	return 0;
	}
int deletedqifront()
{
if (isemptydqi())
{
printf("\n underflow queue");
}
else
{
int y;
y=q.dqi[q.front];
if(q.rear==q.front)
initdqi();
else
q.front=(q.front+1)%max;
//q.front++;
return y;
}}
	void displaydqi()
	{
	if(!isemptydqi())
	{
	int i;
	for (i=q.front;i<=q.rear;i++)
	printf("%d\n",q.dqi[i]);
	}}
int sizedqi()
{
if(!isemptydqi())
{
int length=q.rear-q.front+1;
return (length);
}
}
	int deletedqirear()
{
if (isemptydqi())
{
printf("\n underflow queue");
}
else
{
int y;
y=q.dqi[q.rear];
if(q.rear==q.front)
initdqi();
else
q.rear--;
return y;
}}










