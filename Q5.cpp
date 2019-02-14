#include<stdio.h>
#include<stdlib.h>
int a[100005]={0};
int u=0;

struct node
{
	struct node *left,*right;
};
node *head;
struct node* newnode()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->left=NULL;
	t->right=NULL;
	return t;
}
int power(int x)
{
	if(x==0)
		return 1;
	else
		return 2*power(x-1);
		
}
void insert(int n,node *head)
{
	node *curr=head;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		//printf("%d ",b);
		if(b==0)
		{
			if(!curr->left)
			{
				curr->left=newnode();
			}
			curr=curr->left;
		}
		else
		{
			if(!curr->right)
			{
				curr->right=newnode();
			}
			curr=curr->right;
		}
	}
	//printf("\n");
}
int Xor(int k)
{
	int t=0,i,j;
	struct node *temp=head;
	for(int j=31;j>=0;j--)
	{
		if((1<<j)&k)
		{
			if(j==31)
			{
				if(temp->right!=NULL)
					temp=temp->right;
				else
				{
					u=1;
					temp=temp->left;
				}
				continue;
			}
			if(temp->left!=NULL)
			{
				temp=temp->left;
				t=(t*2)+1;
			}
			else
			{
				temp=temp->right;
				t*=2;
			}
		}
		else
		{
			if(j==31)
			{
				if(temp->left!=NULL)
					temp=temp->left;
				else
				{
					u=1;
					temp=temp->right;
				}
				continue;
			}
			if(temp->right!=NULL)
			{
				temp=temp->right;
				t=(t*2)+1;
			}
			else
			{
				temp=temp->left;
				t*=2;
			}
		}
	}
	return t;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	head=newnode();
	for(int i=0;i<n;i++)
	{
		insert(a[i],head);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d",&k);
		k=Xor(k);
		if(u)
		{
			printf("%d \n",k+power(31));
		}
		else
		{
			printf("%d \n",k);
		}
		u=0;
	}
	return 0;
}
