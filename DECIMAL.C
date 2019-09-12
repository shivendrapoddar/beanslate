#include<stdio.h>
#include<conio.h>
#include<string.h>
struct ST
{
long int st[12];
int top;
}s;

void init();

void push(int);

int pop();

int main()
{
int i,r;

int n;
//clrscr();
printf("\nENTER THE DECIMAL NUMBER");
scanf("%d",&n);
//a[12]=c[12];
init();
while(n>0)
{
r=n%2;
n=n/2;
push(r);
}for(i=s.top;i>-1;i--)
printf("%d",pop());
}
void init()
{
s.top=-1;
}

void push(int c)
{
if(s.top==20-1)
printf("\nOVERFLOW\n");
else
{
s.top++;
s.st[s.top]=c;
}}


int pop()
{
if(s.top==-1)
printf("\nEMPTY") ;
else
{
int y;
y=s.st[s.top];
s.top--;
return y;
}
}

