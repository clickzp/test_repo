#include<iostream>
#include<iomanip>
#include<time.h>
#include<math.h>
using namespace std;
int solution=0;
int k=0;
bool Judge(int n,int* a)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(a[i]-a[j])==abs(i-j))
			{return 0;}
		}
	}
	return 1;
}
void Display(int *a,int n)
{
	cout << "第" << ++solution << "种解：\n";
	for(int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if(a[i]==j)
			{
				cout << i<<"   ";
			}
			else
			{
				cout << "#   ";
			}
		}
		cout << "\n" << endl;
	}
	cout << "-----------------\n";
}
void Arrange(int n,int *a,int m=1)
{
	int b[n+1]={0};
	a[m]=m;
	for(int i=1;i<=m;i++)
	{
		b[i]=a[i];
	}
	for(int i=m;i>0;i--)
	{
		
		if(m<n)
				{
					Arrange(n,b,m+1);
				}
				else if(Judge(n,b))
				{
					//Display(b,n);
					
					k++;
				}
		if(i>0)
				{
					b[0]=b[i-1];
					b[i-1]=b[i];
					b[i]=b[0];
				}
	}
}
int main()
{
	clock_t start,finish;
	start=clock();
	int a[13]={0};
	Arrange(12,a);
	cout<<k;
	finish=clock();
	cout<<"代码运行花费时间:"<<fixed<<setprecision(8)
	<<double(finish-start)/CLOCKS_PER_SEC<<"ms"<<endl;
 	return 0;
}
