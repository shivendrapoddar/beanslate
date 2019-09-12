#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node *next;
};
typedef struct node *NODE;
NODE top=NULL;
void push(int);
int pop();
int size();
void display();
void init();
int main()
{
	int c,x;
	do
	{
	printf("\n1.INITALIZATION\n2.PUSH\n3.POP\n4.SIZE\n5.DISPLAY\n6.EXIT\nENTER YOUR CHOICE");
	scanf("%d",&c);
	switch(c)
	{
		case 1:init();
			break;
		case 2:printf("\nENTER THE INFORMATION");
			scanf("%d",&x);
			push(x);
			break;
		case 3:x=pop();
			printf("\nDELETED ELEMRNT IS %d",x);
			break;
		case 4:printf("\nSIZE OF STACK IS %d",size());
			break;
		case 5:printf("\nTSACK IS AS\n");
				display();
				break;
		case 6:exit(0);
		default:printf("\nWRONG CHOICE TRY AGAIN\n");
	}}while(c!=6);
	}
void init()
{
	top=NULL;
}
void push(int x)
{
		NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("\nINSERTION NOT POSSIBLE\n");
	else
	{
		temp->info=x;
		temp->next=NULL;
		if(top==NULL)
		top=temp;
		else
		{
			temp->next=top;
			top=temp;
		}
	}

}
void display()
{
	if(top!=NULL)
	{
		NODE t;
		printf("\nLIST IS AS\n\t");
		for(t=top;t!=NULL;t=t->next)
		printf("%d\t",t->info);
	}
}
int size()
{
	if(top!=NULL)
	{
		NODE t;
		int i;
		for(t=top,i=0;t!=NULL;t=t->next,i++);
		return(i);
		
	}
}
int pop()
{
	if(top!=NULL)
	{
		int x;
		NODE temp;
		temp=top;
		top=temp->next;
		x=temp->info;
		free(temp);
		return(x);
	}
}

