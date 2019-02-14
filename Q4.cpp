#include<stdio.h>
void sort(int f[],int m,int n)
{
	for(int i=m;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(f[j]<f[min])
				min=j;
		}
		int t=f[min];
		f[min]=f[i];
		f[i]=t;
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int gs[100][100];
	int f[100005];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			gs[i][j]=0;
			f[i]=i;
		}
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		gs[x][y]=1;
	}
	int a,b;
	scanf("%d %d",&a,&b);
	int gv[100][100];
	for(int i=0;i<b;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		gv[i][0]=x;
		gv[i][1]=y;
	}
	if((a!=n) || (b!=m))
	{
		printf("No");
		return 0;
	}
	int x=1;
	for(int i=1;i<=n;i++)
	{
		x*=i;
	}
	int p=0;
	for(int u=0;u<x;u++)
	{
		int vg[100][100];
		for(int i=0;i<m;i++)
		{
			vg[i][0]=gv[i][0];
			vg[i][1]=gv[i][1];
		}
		for(int i=0;i<m;i++)
		{
			vg[i][0]=f[vg[i][0]];
			vg[i][1]=f[vg[i][1]];
		}
		int g[100][100];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				g[i][j]=0;
			}
		}
		for(int i=0;i<m;i++)
		{
			g[vg[i][0]][vg[i][1]]=1;
		}
		int st=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(g[i][j]!=gs[i][j])
				{
					st=0;
					break;
				}
			}
			if(st==0)
				break;
		}
		p=st;
		if(p==1)
			break;
		for(int j=n-1;j>=0;j--)
		{
			if(f[j-1]<f[j])
			{
				int min=10,ind=-1;
				for(int k=j;k<n;k++)
				{
					if(f[k]<min && f[k]>f[j-1])
					{
						min=f[k];
						ind=k;
					}
				}
				int t=f[ind];
            	f[ind]=f[j-1];
            	f[j-1]=t;
            	sort(f,j,n);
            	break;
			}
		}
	}
	/*for(int i=0;i<n;i++)
      printf("%d  ",f[i]);*/
    if(p)
      printf("Yes");
    else
      printf("No");
    return 0;
}
