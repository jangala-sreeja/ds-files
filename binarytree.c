#include<stdio.h>
#include<stdlib.h>
struct tree 
{
	struct tree *left;
	int ele;
	struct tree *right;
};

struct que
{
	struct tree *a[20];
	int r;
	int f;
};

void enque(struct que *q,struct tree *ele)
{
	q->r++;
	q->a[q->r]=ele;
}

struct tree * deque(struct que *q)
{
	if(q->r==q->f)
		return NULL;
	else
	{
		q->f++;
		return q->a[q->f];
	}
}

int isempty(struct que *q)
{
	if(q->r==q->f)
		return 1;
	else
		return 0;
}
 
struct tree * insert(struct tree *root,int val)
{
	if(root==NULL)
	{
		root=(struct tree *)malloc(sizeof(struct tree));
		root->left=NULL;
		root->right=NULL;
		root->ele=val;
	}
	else
	{
		struct tree *temp,*temp1;
		temp=(struct tree *)malloc(sizeof(struct tree));
		temp->ele=val;
		temp->left=NULL;
		temp->right=NULL;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp1=deque(q);
			if(temp1->left!=NULL)
				enque(q,temp1->left);
			else{
				temp1->left=temp;
				break;
			}
			if(temp1->right!=NULL)
				enque(q,temp1->right);
			else{
				temp1->right=temp;
				break;
			}
		}
	}
	return root;
}

void print(struct tree *root)
{
	if(root==NULL)
	{
		printf("the tree is empty");
	}
	else
	{
		struct tree *temp1;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp1=deque(q);
			if(temp1->left!=NULL){
				enque(q,temp1->left);
			}
			if(temp1->right!=NULL){
				enque(q,temp1->right);
			}
			printf("%d",temp1->ele);
		}
	}
}	
struct tree * find(struct tree *root,int e)
{
	if(root==NULL)
	{
		printf("the list is empty");
		return root;
	}
	else
	{
		struct tree *temp;
		struct que *q;
		int f=0;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->left!=NULL){
				enque(q,temp->left);
			}
			if(temp->right!=NULL){
				enque(q,temp->right);
			}
			if(temp->ele==e)
			{
				f=1;
				break;	
			}	
		}
		if(f==1){
			printf("the element that u want to delete is %d",temp->ele);
			return temp;
		}
		if(f==0){
			return NULL;
		}
	}
}

struct tree * find_last(struct tree *root)
{
	if(root==NULL)
	{
		printf("THE TREE IS EMPTY");
		return root;
	}
	else
	{
		struct tree *temp1;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp1=deque(q);
			if(temp1->left!=NULL){
				enque(q,temp1->left);
			}
			if(temp1->right!=NULL){
				enque(q,temp1->right);
			}
		}
		return temp1;
	}
}

struct tree * find_parent(struct tree *root,struct tree * temp1)
{
	if(root==NULL)
	{
		printf("EMPTY TREE");
		return root;
	}
	else
	{
		struct tree *temp2;
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp2=deque(q);
			if(temp2->left==temp1)
			{
				return temp2;
			}
			else
			{
				if(temp2->left!=NULL)
				{
					enque(q,temp2->left);
				}	
			}
			if(temp2->right==temp1)
			{
				return temp2;
			}
			else
			{
				if(temp2->right!=NULL)
				{
					enque(q,temp2->right);
				}
			}
		}
		return NULL;	
	}
}

struct tree * delete(struct tree *root,int val)
{
	if(root==NULL)
	{
		printf("EMPTY TREE");
		return root;
	}
	if(root->left==NULL && root->right==NULL)
	{
		if(root->ele==val)
		{
			root=NULL;
			return root;
		}
		else
		{
			printf("NOT FOUND");
			return root;
		}
	}
	if(root->left==NULL || root->right==NULL)
	{
		if(root->left==NULL)
		{
			if(root->right->ele==val)
			{
				root->right=NULL;
			}
			else if(root->ele==val)
			{
				root->ele=root->right->ele;
				root->right=NULL;
			}
			else
			{
				printf("NOT FOUND");
			}
			return root;
		}
		if(root->right==NULL)
		{
			if(root->left->ele==val)
			{
				root->left=NULL;
			}
			else if(root->ele==val)
			{
				root->ele=root->left->ele;
				root->left=NULL;
			}
			else
			{
				printf("NOT FOUND");
			}
			return root;
		}
	}
	struct tree *temp,*temp1,*temp2;
	temp=find(root,val);
	if(temp!=NULL)
	{
		temp1=find_last(root);
		temp2=find_parent(root,temp1);
	}
	else
	{
		printf("NOT FOUND");
		return root;
	}
	if(temp2->left->ele==val || temp2->right->ele==val)
	{
		if(temp2->left->ele==val)
			temp2->left=NULL;
		else
			temp2->right=NULL;
		return root;
	}
	else
	{
		temp->ele=temp1->ele;
		if(temp2->left=temp1)
			temp2->left=NULL;
		else
			temp2->right=NULL;
		return root;
	}
}

void search(struct tree *root,int e)
{
	if(root==NULL)
	{
		printf("the list is empty");
	}
	else
	{
		struct tree *temp;
		struct que *q;
		int f=0,c=0;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->left!=NULL){
				enque(q,temp->left);
			}
			if(temp->right!=NULL){
				enque(q,temp->right);
			}
			c++;
			if(temp->ele==e)
			{
				f=1;
				break;	
			}	
		}
		if(f==1)
			printf("the element %d is present in %d position in the tree",temp->ele,c);
		if(f==0){
			printf("the element is not there in tree");
		}
	}
}

void main()
{
	struct tree *root;
	root=NULL;
	int val,op;
	printf("welcome to the binary tree \n");
	do
	{
		printf("\n1-insert \n 2-delete \n 3-print \n 4-search \n 5-exit \n enter the option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter the element to insert");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			case 2:
				printf("enter the element to delete");
				scanf("%d",&val);
				root=delete(root,val);
				break;
			case 3:
				print(root);
				break;
			case 4:
				printf("enter the element to search");
				scanf("%d",&val);
				search(root,val);
				break;
			case 5:
				break;
		}
	}while(op!=5);
}



