#define MAX 10
#include<stdio.h>
#include<conio.h>

struct STACK
{
	int st[MAX];
	int top;
}s;

void init()
{
	s.top=-1;
}

int isFull()
{
	if(s.top==(MAX-1))
	{
		return 1;
	}
	else
		return 0;
}

void push(int x)
{
	if (isFull())
		printf("\n STACK IS OVERFLOW");
	else
	{
		s.top++;
		s.st[s.top]=x;
	}
}

int isEmpty()
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}

int pop()
{
	if(isEmpty())
	{
		printf("\n STACK IS UNDERFLOW");
		return -999;
	}
	else
	{
		int y;
		y=s.st[s.top];
		s.top--;
		return y;
	}
}

void display()
{

	if(isEmpty())
		printf("\n STACK IS EMPTY");
	else
	{
		int i;
		printf("ELEMENTS OF STACK ARE:\n");

		for(i=s.top;i>-1;i--)
		{
			printf("%d \t",s.st[i]);
		}
	}
}

int size()
{
	return(s.top+1);
}

void main()
{
	int ch,x,y;
	do
	{
		printf("------MENU------");
		printf("\n 1.INITIALISATION\n 2.PUSH \n 3.POP\n 4.DISPLAY \n 5.ISeMPTY\n 6.ISfULL\n 7.SIZE\n 8.EXIT\n");
		printf("-----------------\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:init();
			break;
		case 2: printf(" enter value you want to push in the stack \n");
			scanf("%d",&x);
			push(x);
			break;
		case 3: y=pop();
			if(y!=-999)
				printf("\n deleted value is %d\n",y);
			break;
		case 4: display();
			break;
		case 5: y=isEmpty();
			if(y==1)
				printf("\n STACK IS EMPTY");
			else
				printf("\nSTACK IS NOT EMPTY");
			break;
		case 6: y=isFull();
			if(y==1)
				printf("\n STACK IS FULL");
			else
				printf("\nSTACK IS NOT FULL");
			break;
		case 7: y=size();
			printf("\n size of stack is %d",y);
			break;
		case 8: printf("\n exitting from switch");
			break;
		default:printf("\n WRONG CHOICE \n");
		}
	}while(ch!=8);
	getch();
}
