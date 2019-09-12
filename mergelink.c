#include<stdio.h>
#include<stdlib.h>
struct node
{
	char info;
	struct node *next;
};
typedef struct node *NODE;
NODE s=NULL,s1=NULL;
void init();
void insertl1(char);
void insertl2(char);
void display1();
void merge();
void display();
//int search(int);
int size();
int main()

{
	char c,x;
int l,s;
//clrscr();
do
{
	printf("\nenter new information for list 1");
       fflush(stdin);
	scanf("%c",&x);
	insertl1(x);
	printf("\nto insert new node press \'Y\' else any character");
	fflush(stdin);
	scanf("%c",&c);
}while(c=='Y'||c=='y');
do
{
	printf("\nenter new information for list 2");
       fflush(stdin);
	scanf("%c",&x);
	insertl2(x);
	printf("\nto insert new node press \'Y\' else any character");
	fflush(stdin);
	scanf("%c",&c);
}while(c=='Y'||c=='y');
printf("\n\nLINK LIST FIRST\n");display();
printf("\n\nLINK LIST SECOND\n");display1();
printf("\nAFTER MERGING\n");
merge();
display();
}
void display()
{
	if(s!=NULL)
	{
		NODE t;
		printf("\nLIST IS AS\n\t");
		for(t=s;t!=NULL;t=t->next)
		printf("%c\t",t->info);
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
void insertl2(char x)
{
	NODE temp,t;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)
	printf("\nINSERTION NOT POSSIBLE\n");
	else
	{
		temp->info=x;
		temp->next=NULL;
		if(s1==NULL)
		s1=temp;
		else
		{
			for(t=s1;t->next!=NULL;t=t->next);
			t->next=temp;

		}
	}
}void insertl1(char x)
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

void display1()
{
	NODE t;
	if(s1!=NULL)
	{
		for(t=s1;t!=NULL;t=t->next)
		printf("%c\t",t->info);
}}
void merge()
{
	NODE t,p;
	for(t=s;t!=NULL;p=t,t=t->next);
	p->next=s1;
}
