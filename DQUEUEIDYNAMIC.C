#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *next;
};
typedef struct node *NODE;
NODE f=NULL,r=NULL;
void enqueue(int);
int dequeueF();
int dequeueR();
int size();
void display();
void init();
int main()
{
	int c,x;
	do
	{
	printf("\n1.INITALIZATION\n2.ENQUEUE\n3.DEQUEUE FROM FRONT\n4.DEQUEUE FROM REAR\n5.SIZE\n6.DISPLAY\n7.EXIT\nENTER YOUR CHOICE");
	scanf("%d",&c);
	switch(c)
	{
		case 1:init();
			break;
		case 2:printf("\nENTER THE INFORMATION");
			scanf("%d",&x);
			enqueue(x);
			break;
		case 3:x=dequeueF();
			printf("\nDELETED ELEMRNT FROM FRONT IS %d",x);
			break;
		case 4:x=dequeueR();
			printf("\nDELETED ELEMRNT FROM REAR %d",x);
			break;
		case 5:printf("\nSIZE OF STACK IS %d",size());
			break;
		case 6:printf("\nTSACK IS AS\n");
				display();
				break;
		case 7:exit(0);
		default:printf("\nWRONG CHOICE TRY AGAIN\n");
	}}while(c!=7);
	}
void init()
{
	f=r=NULL;
}
void display()
{
	if(r!=NULL)
	{
		NODE t;
		printf("\nLIST IS AS\n\t");
		for(t=f;t!=NULL;t=t->next)
		printf("%d\t",t->info);
	}
}
int size()
{
	if(r!=NULL)
	{
		NODE t;
		int i;
		for(t=f,i=0;t!=NULL;t=t->next,i++);
		return(i);
		
	}
}
int dequeueF()
{
	if(r!=NULL)
	{
		int x;
		NODE temp;
		temp=f;
		f=temp->next;
		x=temp->info;
		free(temp);
		return(x);
	}
}
void enqueue(int x)
{
	NODE temp,t;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("\nINSERTION NOT POSSIBLE\n");
	else
	{
		temp->info=x;
		temp->next=NULL;
		if(r==NULL)
		r=f=temp;
		else
		{
			for(t=f;t->next!=NULL;t=t->next);
			t->next=temp;
			r=temp;
		
		}
	}
}
int dequeueR()
{
	if(!(r==NULL))
	{
		int x;
		NODE t,temp;
		if(r==f)
		{
		temp=r;
		r=f=NULL;
		}
		else
		{
			for(t=f;t->next!=r;t=t->next);
			temp=t->next;
			r=t;
			r->next=NULL;
		}
		x=temp->info;
		return(x);
		free(t);
	}
}
