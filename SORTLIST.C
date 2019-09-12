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
void display();
void sort();
int size();
int main()
{
	char c;
	int x,l,s;
	do
	{
		printf("\nenter new information");
		scanf("%d",&x);
		insertl(x);
		printf("\nto insert new node press \'Y\' else any character");
		fflush(stdin);
		scanf("%c",&c);
	}while(c=='Y'||c=='y');
	printf("\nELEMENTS BEFORE SORTING\n");
	display();
	sort();
	printf("\nELEMENTS AFTER SORTING\n");
	display();

}
void display()
{
	if(s!=NULL)
	{
		NODE t;
		//printf("\nLIST IS AS\n\t");
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
void sort()
{
	NODE t,p;
	int temp;
	if(s!=NULL)
	{
		for(t=s;t->next!=NULL;t=t->next)
		for(p=t;p!=NULL;p=p->next)
		{
			if(t->info<p->info)
			{
				temp=t->info;
				t->info=p->info;
				p->info=temp;
			}
		}
	}
}
