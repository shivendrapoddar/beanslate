#include<stdio.h>
//#include<conio.h>
#define max 10
struct Queue
{
	int q[max];
	int f,r;
}Q;
int size();
void init();
int Bsearch(int);
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
	printf("\nELEMENTS ARE\n");
	display();
	printf("\nENTER THE ELEMENT YOU WANT TO SEARCH ");
	scanf("%d",&s);
	l=Bsearch(s);
	if(l==-1)
	printf("\n\nELEMENT NOT FOUND");
	else 
	printf("\n\nELEMENT IS AT POSITION  %d",l);
	//printf("\n%d\tis the size of queue",size());	
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
}//linear search
/*int search(int k)
{
	int i,j=-1,p=-1;
	for(i=Q.f,j=0;i<=Q.r;i++,j++)
	{
		if(Q.q[i]==k)
		return(j);
		
	}
	
	return(p);
	}*/
	void display()
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
	//binary search
int Bsearch(int k)
{
	int lb=0,ub=size()-1,mid,f=0;
	mid=(lb+ub)/2;
	while(ub>=lb&&f==0)
	{
		if(Q.q[mid]==k)
		{
			f=1;
			return(mid+1);
		}
		else
		{
	
			if(Q.q[mid]<k)
			lb=mid+1;
			else
			ub=mid-1;
			mid=(lb+ub)/2;
		}
	}
	if(f==0)
	return(-1);
}


