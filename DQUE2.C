//OUTPUT RESTRICTED
#include<stdio.h>
#include<conio.h>
#define max 3
void initdqo();
void insertdqorear(int);
int isfulldqo();
void insertdqofront(int);
int deletedqo();
int isemptydqo();
void displaydqo();
int sizedq();
struct DOQueue
{
int dqo[max];
int rear,front;
}q;
	void main()
	{
	int ch,x,y;
	do
	{
	printf("\n|____MENU_____");
	printf("\n1.initilization:\n2.INSERT LQ FROM REAR:\n3.INSERT LQ FROM FRONT:\n4.DELETE LQ:\n5.display LQ:\n6.isfull \n7.isempty:\n8.sieof:\n9.exit");
	printf("\n enter your choice");
	scanf("%d",& ch);
	switch(ch)
	{
	case 1:initdqo();
		break;
	case 2:printf("\n enter the value to insert in queue");
		scanf("%d",&x);
		insertdqorear(x);
		break;
	case 3: printf("\n enter the value to insert in queue");
		scanf("%d",&x);
		insertdqofront(x);
		break;
	case 4:y=deletedqo();
		if(y!=-999)
		printf("the deleted value is\t%d\n",y);
		break;
	case 5:displaydqo();
		break;
	case 6: y=isfulldqo();
		if(y==1)
		printf("queue is full");
		else
		printf("not full");
		break;
	case 7:y=isemptydqo();
		if(y==1)
		printf("empty");
		else
		printf("stack is not full");
		break;
	case 8: y=sizedqo();
		printf("\n the size%d",y);
		break;
	case 9:exit(0);
	default:printf("you have given a wrong choice");
	}}
	while (ch!=9);
	getch();
	}
void initdqo()
{
q.rear=q.front=-1;
}
	void insertdqorear(int x)
	{
	if(isfulldqo())
	printf("\nqueue is overflow");
	else
	{
	if(isemptydqo()) 	q.rear=q.front=0;
	else             	q.rear++;
	q.dqo[q.rear]=x;
	}
	}
int isfulldqo()
{
if(q.rear==(max-1))
return 1;
else
return 0;
}
	int isemptydqo()
	{
	if(q.front==-1)
	return 1;
	else
	return 0;
	}
int deletedqo()
{
if (isemptydqo())
{
printf("\n underflow queue");
}
else
{
int y;
y=q.dqo[q.front];
if(q.rear==q.front)
initdqo();
else
//q.front=(q.front+1)%max;
q.front++;
return y;
}}
	void displaydqo()
	{
	if(!isemptydqo())
	{
	int i;
	for (i=q.front;i<=q.rear;i++)
	printf("%d=%d\n",i,q.dqo[i]);
	}}
int sizedqo()
{
if(!isemptydqo())
{
int length=q.rear-q.front+1;
return (length);
}
}
void insertdqofront(int x)
{
//if(!isfulldqo())
if(!q.front<=0)
{
q.front--;
q.dqo[q.front]=x;
}
}










