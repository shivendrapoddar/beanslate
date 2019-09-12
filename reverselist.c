#include<stdio.h>
#include<stdlib.h>
struct node
{
	char info;
	struct node *next;
};
typedef struct node *NODE;
NODE s=NULL;
void init();
void insertl(char);
void display();
void reverse();
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
reverse();
printf("\nAFTER REVERSE\n");
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
void reverse()
{
	NODE t,p;
	int l=size()-1;

	int i,j;
	char temp;
	for(t=s,i=0;i<=l/2;t=t->next,i++)
	{
		for(p=s,j=0;j<l-i;j++,p=p->next);
		temp=p->info;
		p->info=t->info;
		t->info=temp;
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

