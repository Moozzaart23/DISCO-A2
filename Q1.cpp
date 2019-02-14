#include<stdio.h>
int nodes;
int adj[100][100];
int minnode(int n,int keyval[],int vis[])
{
	int mini=99999;
	int mini_index;
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0 && keyval[i]<mini)
		{
			mini=keyval[i];
			mini_index=i;
		}
	}
	return mini_index;
}
void findCost()
{
	int parent[10005];
	int keyval[10005];
	int visited[100005];
	for(int i=0;i<nodes;i++)
	{
		keyval[i]=99999;
		visited[i]=0;
	}
	parent[0]=-1;
	keyval[0]=-1;
	for(int i=0;i<nodes-1;i++)
	{
		int u=minnode(nodes,keyval,visited);
		visited[u]=1;
		for(int v=0;v<nodes;v++)
		{
			if(adj[u][v] && visited[v]==0 && adj[u][v]<keyval[v])
			{
				keyval[v]=adj[u][v];
				parent[v]=u;
			}
		}
	}
	int cost=0;
	for(int i=1;i<nodes;i++)
		cost+=adj[parent[i]][i];
	printf("%d \n",cost);
}
int main()
{
	int edges;
	scanf("%d",&nodes);
	scanf("%d",&edges);
	for(int i=0;i<edges;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		adj[x][y]=z;
		adj[y][x]=z;
	}
	findCost();
	return 0;
}
