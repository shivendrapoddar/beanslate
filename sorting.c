#include<stdio.h>
#define max 10
struct Queue
{
	int q[max];//#include<conio.h>

	int f,r;
}Q;
int size();
void init();
//void Bsort();
//void Ssort();
void Isort();
void display();
void insert(int);
int main()
{
	int i,n,x[max],l,s;
	printf("\nENTER THE SIZE OF QUEUE ");
	scanf("%d",&n);
	init();
	for(i=0;i<n;i++)
	{
		printf("\nENTER THE ELEMENT ");
		scanf("%d",&x[i]);
		insert(x[i]);
	}
	printf("\nELEMENTS BEFORE SORTING ARE\n");
	display();
	//Ssort();
	Isort();
	printf("\nE LEMENTS AFTER SORTING ARE\n");
	display();
	getch();
}
void init()
{
	Q.f=Q.r=-1;
}
void insert(int a)
{
	if(!(Q.r==max-1))
	{
		if(Q.f==-1&&Q.r==-1)
		Q.f=Q.r=0;
		else 
		Q.r++;
		Q.q[Q.r]=a;	
	}	
}	void display()
	{
		int i;
		for(i=Q.f;i<=Q.r;i++)
		printf("\t%d",Q.q[i]);
	}
	int size()
	{
		int i,j;
		if(Q.r!=-1)
			for(i=Q.f,j=0;i<=Q.r;i++,j++);
			return (j);
			
	} 
	//bubble sorting 
/*void Bsort()
{
	int i,j,temp;
	for(i=Q.f;i<=Q.r;i++)
	{
		for(j=Q.f;j<Q.r-i;j++)
		{
			if(Q.q[j]>Q.q[j+1])
			{
				temp=Q.q[j];
				Q.q[j]=Q.q[j+1];
				Q.q[j+1]=temp;
			}
		}
	}
}*/
//selection sort
/*void Ssort()
{
	int i,j,loc,temp,min;
	for(i=Q.f;i<=Q.r;i++)
	{
		loc=i;
		min=Q.q[i];
		for(j=1+i;j<=Q.r;j++)
		{
			if(Q.q[j]<min)
			{
				loc=j;
				min=Q.q[j];
				temp=Q.q[i];
				Q.q[i]=Q.q[loc];
				Q.q[loc]=temp;
			}
		}
	}
}*/
//INSERTION SORTING
void Isort()
{
	int i,j,temp;
	for(i=Q.f;i<=Q.r;i++)
	{
		temp=Q.q[i];
		j=i-1; 
		while(temp<Q.q[j]&&j>=0)
		{
			Q.q[j+1]=Q.q[j];
			j-=1;
			Q.q[j+1]=temp;
		}
	}
}
