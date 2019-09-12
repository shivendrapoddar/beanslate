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
int search(int);
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
display();
printf("\nenter the element to search");
scanf("%d",&s);
l=search(s);
if(l==-1)
printf("\nELEMENT NOT FOUND");
else
printf("\nELEMENT IS AT POSITION %d",l+1);
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
int search(int k)
{
	NODE t;
	int i;
	for(t=s,i=0;t!=NULL;i++,t=t->next)
	if(k==t->info)
	return(i);
	return(-1);
}
