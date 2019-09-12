#include<stdio.h>
#include<conio.h>
# define max 10
struct STACK
{
 float st[max];
 int top;
 }s;
 void init();
 void push(float);
 float pop();
  void main()
  {
    char post[20],ch;
    int i;
    float   e1,e2;
    float temp;
    clrscr();
    init();
    printf("\n enter valid postfix expression");
   // scanf("%c",&post);
   gets(post);
    for(i=0;post[i]!='\0';i++)
    {
    ch=post[i];
    if(isalpha(ch))
    {
     printf("enter the value of %c",ch);
     scanf("%f",&temp);
     push(temp);
     }
     else
    {
     e1=pop();
     e2=pop();
     switch(ch)
     {
       case '+' :push(e2+e1);
		 break;
       case '-' :push(e2-e1);
		 break;
       case '*' :push(e2*e1);
		 break;
       case '/' :push(e2/e1);
		 break;
       case '^' :push(pow(e2,e1));
		 break;

	}
    }
   }
   printf("\n the resultant of postfix expression is %f",pop());
					     getch();

  }
     void init()
   {
     s.top=-1;
   }
     void push(float x)
     {
       if(s.top==(max-1))
       printf("\n unable to show the value in stack");
       else
       s.st[++s.top]=x;
      }
       float pop()
       {
       if(s.top==-1)
       printf("\n stack is empty");
       else
       {
	float y;
	y=s.st[s.top];
	s.top--;
	return y;
	}
    }
   // void init()
   // {
    //s.top=-1;
    //}