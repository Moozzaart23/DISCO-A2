#include<stdio.h>
 int nodes;
	
	int adj[100][100];
	int visited[100005] = { 0 };
	//int x=0;
    void dfs(int s,int x) {
        visited[s] = 1;
        if(s==x)return;
        for(int i = 0;i < nodes;++i)    {
        	
         if(adj[s][i] == 1 && visited[i]==0)
			dfs(i,x);
        }
    }

    

    int main()
	 {
        int  edges, x, y, connectedComponents = 0;int m=0;
        scanf("%d",&nodes);                      
        scanf("%d",&edges);                       
        for(int i = 0;i < edges;++i) {
         scanf("%d %d",&x,&y);     
     
         adj[x-1][y-1]=1;
		 adj[y-1][x-1]=1;                  
        }

        
	
        for(int i=0;i<nodes;i++)
        {
        	int connectedComponents=0;
	    	for(int j=0;j<nodes;j++)
        	{
        		if(i==j)
        			continue;
        		if(!visited[j])
        		{
        			dfs(j,i);
        			connectedComponents++;
        		}
			}
			for(int j=0;j<=nodes;j++)visited[j]=0;
			if(connectedComponents>1)
				{
					printf("%d ",i);m++;
				}
		}
		if(m==0)
			printf("-1");
        return 0;
   
    }
