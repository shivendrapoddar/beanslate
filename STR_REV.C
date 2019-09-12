#include<stdio.h>
#include<conio.h>
#define MAX 10

struct STACK
{
	char st[MAX];
	int top;
}s;
void init();
void push(char);
char pop();

void main()
{
	int i;
	char str[20];
	clrscr();
	printf("enter string \n");
	gets(str);
	//s.init();
	for(i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
	printf(" REVERSED STRING IS:\n");
	for(i=s.top; i>-1;i--)
	{
		printf("%c",pop());
	}
	getch();
}

void init()
{
	s.top=-1;
}

void push(char x)
{
	if(s.top==(MAX-1))
	{
		printf("\nSTACK OVERFLOW\n");
	}
	else
	{
		s.st[++s.top]=x;
	}
}

char pop()
{
	if(s.top==-1)
	{
		printf("\n STACK UNDERFLOW");
	}
	else
	{
		char y;
		y=s.st[s.top];
		s.top--;
		return y;
	}
}