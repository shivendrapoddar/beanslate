#include<stdio.h>
#include<conio.h>
#define max 10
void initpq();
void insertpq(int,int);
int isfullpq();
void deletepq();
int isemptypq();
void displaypq();
int sizepq();
void arrange();
struct PQueue
{
int pq[max][max];
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
	case 1:initpq();
		break;
	case 2:printf("\n enter the value and priotity to insert in queue");
		scanf("%d%d",&x,&y);
		insertpq(x,y);
		break;
		case 3:deletepq();
		break;
	case 4: arrange();
		displaypq();
		break;
	case 5: y=isfullpq();
		if(y==1)
		printf("queue is full");
		else
		printf("not full");
		break;
	case 6:y=isemptypq();
		if(y==1)
		printf("empty");
		else
		printf("stack is full");
		break;
	case 7: y=sizepq();
		printf("\n the size%d",y);
		break;
	case 8:exit(0);
	default:printf("you have given a wrong choice");
	}}
	while (ch!=8);
	getch();
	}
void initpq()
{
q.rear=q.front=-1;
}
	void insertpq(int x,int y)
	{
	if(isfullpq())
	printf("\nqueue is overflow");
	else
	{
	if(isemptypq())
	q.rear=q.front=0;
	else
	q.rear++;
	q.pq[0][q.rear]=x;
	q.pq[1][q.rear]=y;

	}
	}
int isfullpq()
{
if(q.rear==(max-1))
return 1;
else
return 0;
}
	int isemptypq()
	{
	if(q.front==-1)
	return 1;
	else
	return 0;
	}
void deletepq()
{
arrange();
if (isemptypq())
{
printf("\n underflow queue");
}
else
{
int y,x;
x=q.pq[0][q.front];
y=q.pq[1][q.front];
if(q.rear==q.front)
initpq();
else
q.front++;
printf("\n deleted element is %d at priority %d",x,y);
}}
	void displaypq()
	{
	if(!isemptypq())
	{
	int i;
	for (i=q.front;i<=q.rear;i++)
	printf("%d element at priority %d\n",q.pq[0][i],q.pq[1][i]);
	}}
int sizepq()
{
if(!isemptypq())
{
int length=q.rear-q.front+1;
return (length);
}
}
	void arrange()
	{
	int i,j,temp;
	if(q.rear!=q.front)
	{
	for(i=q.front;i<=q.rear;i++)
	{
	for(j=i+1;j<=q.rear;j++)
	{
	if(q.pq[1][i]>q.pq[1][j])
	{
	temp=q.pq[1][i];
	q.pq[1][i]=q.pq[1][j];
	q.pq[1][j]=temp;
	temp=q.pq[0][i];
	q.pq[0][i]=q.pq[0][j];
	q.pq[0][j]=temp;
	}

	}
	}

	}
	}










