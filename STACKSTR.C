#include<stdio.h>
#include<conio.h>
#define max 10
struct stack
{
	char st[10][max];
	int top;
};
struct stack s;
void init()
{
	s.top=-1;
}
int isfull()
{
	if(s.top==(max-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(char x[])
{
//	char x[10];
 //	int i;
	if(isfull())
		printf("\nstack is full");
	else
	{
		s.top++;
		strcpy(s.st[s.top],x);
	}
}
int isempty()
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}
void pop()
{
	char y[10];
//	int i;
	if(isempty())
	{
		printf("\nstack is empty");
	}
	else
	{
		strcpy(y,s.st[s.top]);
		s.top--;
		printf("element poppd is %s",y);
	}
}
void display()
{
	auto int i;
	for(i=s.top;i>=0;i--)
	{
		printf("\n elemnt = %s",s.st[i]);
	}
}
int size()
{
	return(s.top+1);
}
void main()
{
	int ch,z;
	char str[10];
	clrscr();
	do
	{
		printf("\t MENU ");
		printf("\n 1: Initialization \n 2: Push \n 3: Pop");
		printf("\n 4: Display \n 5: Check isfull \n 6: Check isempty");
		printf("\n 7: Check size \n 8: Exit");
		printf("\nEnter your choice = ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: init();
				break;
			 case 2:fflush(stdin);
				gets(str);
				push(str);
				break;
			case 3: pop();
				break;
			case 4: display();
				break;
			case 5: z=isempty();
				if(z==1)
					printf("\nStack is empty\n");
				else
					printf("\nStack is not empty\n");
				break;
			case 6: z=isfull();
				if(z==1)
					printf("\nStack is full\n");
				else
					printf("\nStack is not full\n");
				break;
			case 7: z=size();
				printf("\nSize is %d",z);
				break;
			case 8: printf("\nExiting from the program");
				break;
			default : printf("\nWrong choice");
				break;
		}
	}while(ch!=8);
	getch();
}