#include<stdio.h>
void one_complement(int a[],int m_comp[],int n);
void arithmetic_shift(int a[], int q[], int *q1, int n);
void add_binary(int a[],int b[],int n,int carry);

int main()
{
	int a[50],m[50],q[50],q1=0,count,i,n,m_comp[50];
	
	
	printf("enter the number of bits:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
     	a[i]=0;
	
	
	printf("enter multiplicand:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	
	printf("enter multiplier:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&q[i]);
	}
	count = n;

    while (count > 0)
    {
        if (q[n - 1] == 1 && q1 == 0)
        {
            one_complement(m,m_comp,n);
            add_binary(a, m_comp, n, 1);   // +1 included here
        }
        else if (q[n - 1] == 0 && q1 == 1)
        {
            add_binary(a, m, n, 0);
        }
        arithmetic_shift(a, q, &q1, n);
        count--;
    }
    printf("Answer: ");
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    for (i = 0; i < n; i++)
        printf("%d", q[i]);

    return 0;

}

void add_binary(int a[],int b[],int n,int carry)
	{
		int i,sum[50];
		for(i=n-1;i>=0;i--)
		{
		
		sum[i]=a[i]+b[i]+carry;
		a[i]=sum[i]%2;
		carry=sum[i]/2;
    	}
		
	}
void one_complement(int a[],int m_comp[],int n)
	{
		int i;
		for(i=0;i<n;i++)
		{
		m_comp[i]=(a[i]==0)?1:0;
     	}
		
	}   
void arithmetic_shift(int a[], int q[], int *q1, int n)
    {
    int i;
    *q1 = q[n - 1];
    for (i = n - 1; i > 0; i--)
      {
        q[i] = q[i - 1];
       }
    q[0] = a[n - 1];

    for (i = n - 1; i > 0; i--)
      {

        a[i] = a[i - 1];
       }
    }