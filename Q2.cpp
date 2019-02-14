#include<stdio.h>
int nodes;
int adj[100][100];
int min=100005;
int path[10005];
int visited[100005]={0};
int cost=0;
int k=0;
int b[100005]={0};




void dfs(int i)
{
    int j;
    for(j=0;j<nodes;j++)
    {
        if(adj[i][j])
        {
            if(j==2)
            {
                //cost+=adj[i][j];
                b[k]=j;
                /*if(cost<min)
                {
                    min=cost;
                    for(int p=0;p<nodes;p++)
                    {
                        path[p]=b[p];
                    }
                }*/
                printf("2 ");
			    for(int i=0;i<k;i++)
			    {
			        printf("%d ",b[i]);
			    }
			    printf("\n");
                //cost-=adj[i][j];
                visited[j]=0;
                break;
            }
            else if((!visited[j])&&(j!=2))
            {
                //cost+=adj[i][j];
                b[k++]=j;
                visited[j]=1;
                dfs(j);
                //cost-=adj[i][j];
                k--;
                visited[j]=0;
            }
        }
    }
}




int main()
{
	int edges;
	scanf("%d",&nodes);
	scanf("%d",&edges);
	for(int i=0;i<edges;i++)
	{
		int x,y,z;
		scanf("%d %d",&x,&y);
		adj[x][y]=1;
		//adj[y][x]=1;
	}
	for(int i=0;i<nodes;i++)
	{
		if(adj[2][i])
		{
			//cost=adj[0][i];
            b[k++]=i;
            visited[i]=1;
            dfs(i);
            visited[i]=0;
            k=0;
            //cost=0;
		}
	}
	
	
	/*printf("A");
    for(int i=0;i<nodes;i++)
    {
        printf(" => %c",path[i]+65);
    }
    printf("\nCost: %d\n",min);*/
    return 0;
}
