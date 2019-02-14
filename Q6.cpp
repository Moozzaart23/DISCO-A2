#include<stdio.h>
/*int possibleOrNot(int source,int target,int steps)
{
	int z=steps;
	while(z--)
	{
		if(source==target)
			return 1;
		if(!(target%2))
			target/=2;
		else
		{
			target-=1;
			if(target%10!=0)
			{
			//	printf("Lol \n");
				return 0;
			}
			else
			{
				target/=10;
			}
		}
	/*	if(target==source)
			return 1;
	}
//	printf("%d %d \n",target,source);
	if(target==source)
		return 1;
	//	printf("Lol \n");
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int source,target,steps;
		scanf("%d",&source);
		scanf("%d",&target);
		scanf("%d",&steps);
		int x=possibleOrNot(source,target,steps);
		if(x==1)
			printf("Yes");
		else
			printf("No");
	}
}*/




#include<stdio.h>
#include<stdlib.h>
int source,target,steps;
int flag=0;
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;
void insert(node **head,int target,int ctr,int steps)
{
	if((*head)->data==target)
	{
		if(ctr>steps)
		{
			return;
		}
		else
		{
			flag=1;
			return;
		}
	}
	if(((*head)->data)>target ||(((*head)->data)<0) )
	{
		return;
	}
	if((*head)->left==NULL)
	{
		node *ptr=(node *)malloc(sizeof(node));
		ptr->data=(2*((*head)->data));
		(*head)->left=ptr;
		ptr->left=NULL;
		ptr->right=NULL;
		
		node *ptr1=(node *)malloc(sizeof(node));
		ptr1->data=(10*((*head)->data))+1;
		(*head)->right=ptr1;
		ptr1->left=NULL;
		ptr1->right=NULL;
	}
	insert(&((*head)->left),target,ctr+1,steps);
	insert(&((*head)->right),target,ctr+1,steps);
}
int main()
{
	
	int z;
	scanf("%d",&z);
	while(z--){
		flag=0;
	scanf("%d %d %d",&source,&target,&steps);
	node *root=(node *)malloc(sizeof(node));
	root->data=source;
	
	node *temp=root;
	temp->left=NULL;
	temp->right=NULL;
	insert(&temp,target,0,steps);
	if(flag==0)
	{
		printf("No");
	}
	else
	{
		printf("Yes");
	}
}
}
