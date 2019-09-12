#include<stdio.h>
#include<conio.h>
#define MAX 10
#include<string.h>
struct STACK
{
	char st[MAX];
	int top;
}s;
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
void init()
{
	s.top=-1;
}


void main()
{
	int i,j=0,k;
	char in[20],post[20],ch;
	clrscr();
	init();
	 printf("enter string\n");
	gets(in);
	for(i=0;in[i]!='\0';i++)
	{
		ch=in[i];
		if(isalpha(ch))
			post[j++]=ch;
		else
		{
			for(k=s.top;k>-1;k--)
				if(prcd(ch)<=prcd(s.st[k]))
					post[j++]=pop();
			push(ch);
		}
	}
	while(s.top>-1)
	{
		post[j++]=pop();
	}
	post[j]='\0';
	puts(post);
}

int prcd(char x)
{
	if(x=='^')
		return 9;
	else if(x=='*'||x=='/')
		return 7;
	else if(x=='+'||x=='-')
		return 5;
}