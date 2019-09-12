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
void insertl(char);
void display();
void split();
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
	printf("\nenter new information");
       fflush(stdin);
	scanf("%c",&x);
	insertl(x);
	printf("\nto insert new node press \'Y\' else any character");
	fflush(stdin);
	scanf("%c",&c);
}while(c=='Y'||c=='y');
display();
printf("\nAFTER REVERSE\n");
display();
split();
printf("\n\nAFTER SPLIT\n");
display();
printf("\n\n");
display1();}
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
void insertl(char x)
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
void split()
{
	NODE t,p;
	int i;
	for(t=s,p=s,i=0;i<size()/2;i++,p=t,t=t->next);
	s1=t;
	p->next=NULL;
}
void display1()
{
	NODE t;
	if(s1!=NULL)
	{
		for(t=s1;t!=NULL;t=t->next)
		printf("%c\t",t->info);
}}
