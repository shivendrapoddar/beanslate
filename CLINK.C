#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *NODE;
NODE s=NULL;
void init();
void insertl(int);
void insertf(int);
void insertsp(int,int);
void display();
int size();
int main()
{
	int a,c,l;
	do
	{
	printf("\n1.INITALIZATION\n2.INSERT FIRST\n3.INSERT LAST\n4.INSERT SPECIFIED\n5.DISPLAY\n6.SIZE\n7.EXIT");
	printf("\nENTER YOUR CHOICE");
	scanf("%d",&c);
	switch(c)
	{
		case 1:init();
			   break;
		case 2:printf("\nENTER THE ELEMENT TO INSERT");
			   scanf("%d",&a);
			   insertf(a);
			   break;
		case 3:printf("\nENTER THE ELEMENT TO INSERT");
			   scanf("%d",&a);
			   insertl(a);
			   break;
		case 4:printf("\nENTER THE ELEMENT TO INSERT AND POSITION WHERE TO INSERT");
			   scanf("%d%d",&a,&l);
			   insertsp(a,l);
			   break;
		case 5:display();
			   break;
		case 6:printf("\nSIZE OF LIST IS %d",size());
				break;
		case 7:exit(0);
		default:printf("\n\n\tWRONG CHOICE TRY AGAIN");
	}
}while(c!=7);
	
}
void init()
{
	s=NULL;
}
void insertf(int x)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("\nINSERTION NOT POSSIBLE\n");
	else
	{
		temp->info=x;
		temp->next=NULL;
		if(s==NULL)
		{
			s=temp;
			temp->next=s;
		}		
		else
		{
			temp->next=s;
			s=temp;
		}
	}
}
void insertl(int x)
{
	NODE temp,t;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("\nINSERTION NOT POSSIBLE\n");
	else
	{
		temp->info=x;
		temp->next=NULL;
		if(s==NULL)
		{
			s=temp;
			temp->next=s;	
		}
		else
		{
			for(t=s;t->next!=s;t=t->next);
			temp->next=s;
			t->next=temp;
			}
	}
}
void insertsp(int x,int pos)
{
	int l=size();
	NODE temp;
	if(pos==1)
	{
		insertf(x);
		return;
	}
	if(pos==1+l)
	{
		insertl(x);
		return;
	}
	if(pos<=0||pos>l+1)
	{
		printf("\nINSERTION NOT POSSIBLE");
		return;
	}
	if(pos>1&&pos<l+1)
	{
		int i;
		NODE temp,t;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("\nINSERTION NOT POSSIBLE\n");
	else
	{
		temp->info=x;
		temp->next=NULL;
		for(t=s,i=1;i<pos-1;i++,t=t->next);
			temp->next=t->next;
			t->next=temp;
		
		
	}
		
	}
}
void display()
{
	if(s!=NULL)
	{
		int i;
		NODE t=NULL;
		t=s;
		printf("\nLIST IS AS\n\t");
		//for(t=s,i=0;i<size();t=t->next,i++)
		do
		{
			printf("%d\t",t->info);
			t=t->next;
	}while(t!=s);
	}
}
int size()
{
	if(s!=NULL)
	{
		NODE t=NULL;
		t=s;
		int i=0;
		//for(t=s,i=0;t->next!=s;t=t->next,i++);
		do
		{
			i=i+1;
			t=t->next;
		}while(t!=s);
		
		return(i+1);
		
	}
}
