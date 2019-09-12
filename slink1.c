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
int deletel();
int deletef();
int deletesp(int);
void display();
int size();
int main()
{
	int a,c,l;
	do
	{
	printf("\n1.INITALIZATION\n2.INSERT FIRST\n3.DELETE FIRST\n4.DELETE LAST\n5.DELETE SPECIFIED\n6.DISPLAY\n7.SIZE\n8.EXIT");
	printf("\nENTER YOUR CHOICE");
	scanf("%d",&c);
	switch(c)
	{
		case 1:init();
			   break;
		case 2:printf("\nENTER THE ELEMENT TO INSERT");
			   scanf("%d",&a);
			   insertl(a);
			   break;
		case 3:printf("\nDELETED NODE IS %d",deletef());
			   break;
		case 4:printf("\nDELETED NODE IS %d",deletel());
			   break;
		case 5:printf("\nENTER THE POSITION YOU WANT TO DELETE");
					scanf("%d",&l);
					printf("\nDELETED ELEMENT IS %d",deletesp(l));
					break;
		case 6:display();
			   break;
		case 7:printf("\nSIZE OF LIST IS %d",size());
				break;
		case 8:exit(0);
		default:printf("\n\n\tWRONG CHOICE TRY AGAIN");
	}
}while(c!=8);
	
}
void init()
{
	s=NULL;
}
void display()
{
	if(s!=NULL)
	{
		NODE t;
		printf("\nLIST IS AS\n\t");
		for(t=s;t!=NULL;t=t->next)
		printf("%d\t",t->info);
	}
}
int size()
{
	if(s!=NULL)
	{
		NODE t;
		int i;
		for(t=s,i=0;t!=NULL;t=t->next,i++);
		return(i);
		
	}
}
int deletef()
{
	if(s!=NULL)
	{
		int x;
		NODE temp;
		temp=s;
		s=temp->next;
		x=temp->info;
		free(temp);
		return(x);
	}
}
int deletel()
{
	NODE t,temp;
	int i,x;
	if(!(s==NULL))
	{
		if(s->next==NULL)
		{
			temp=s;
			s=NULL;
			x=temp->info;
			free(temp);
			return(x);
		}
		else
		{
			for(t=s,i=1;i<size()-1;t=t->next,i++);
			temp=t->next;
			t->next=NULL;
			x=temp->info;
			free(temp);
			return(x);
		}
		
	}
}

int deletesp(int pos)
{
	int l=size(),x,i;
	NODE temp,t;
	if(s!=NULL)
	{
		if(pos==1)
		return(deletef());
		if(pos==l)
		return(deletel());
		if(pos<=0||pos>l)
		{
		printf("\nDELETION NOT POSSIBLE");
		return;
		}if(pos>1&&pos<l)
		{
			for(t=s,i=1;i<pos-1;i++,t=t->next);
			temp=t->next;
			t->next=temp->next;
			x=temp->info;
			free(temp);
			return(x);
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
		s=temp;
		else
		{
			for(t=s;t->next!=NULL;t=t->next);
			t->next=temp;
		
		}
	}
}
