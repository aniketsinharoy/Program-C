#include<stdio.h>
int partition(int a[],int l,int h)
{
	int m,p,t;
	m=(l+h)/2;
	
	t=a[m];
	a[m]=a[l];
	a[l]=t;
	
	p=a[l];
	
	int s=l,e=h;
	while(s<e)
	{
		while(a[s]<=p)
		{
			++s;
		}
		while(a[e]>p) 
		{
			--e;
		}
		if(s<e)
		{
			t=a[s];
			a[s]=a[e];
			a[e]=t;
		}
	}
    t=a[l];
	a[l]=a[e];
	a[e]=t;
	return e;
}
void qsort(int a[],int l,int h)
{
	int d;
	if(l<h)
	{
		d=partition(a,l,h);
		qsort(a,l,d-1);
		qsort(a,d+1,h);
	}
}
int main()
{
	int i,n,a[100],t;
	printf("how many element do u want to enter: ");
	scanf("%d",&n);
	printf("\nenter the numbers: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	qsort(a,0,n-1);
	printf("\n after shorting: ");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	return 0;
}
