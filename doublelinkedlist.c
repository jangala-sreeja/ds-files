#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int e;
	struct node *next;
};
int length(struct node *head)
{
	struct node *temp=head;
	int c=0;
	if(temp==NULL)
	{
		return c;
	}
	while(temp!=NULL)
	{
		temp=temp->next;
		c=c+1;	
	}	
	return c;
}
struct node * printList(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->e);
			temp=temp->next;	
		}
	}
	return head;
}
struct node * insert_at_head(struct node *head)
{
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		int ele;
		printf("enter the element to insert");
		scanf("%d",&ele);
		head->e=ele;
		head->prev=NULL;
		head->next=NULL;
	}
	else
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		int ele;
		printf("enter the element to insert");
		scanf("%d",&ele);
		temp->e=ele;
		temp->next=head;
		temp->prev=NULL;
		head->prev=temp;
		head=temp;
	}
	return head;
}
struct node * insert_at_pos(struct node *head)
{
	int pos,ele,len;
	printf("enter the position");
	scanf("%d",&pos);
	len=length(head);
	if(pos>len)
	{
		printf("the limit is exceeded");
		return head;	
	}
	else
	{
		if(pos==1)
		{
			head=insert_at_head(head);
		}
		else
		{
			struct node *temp=head;
			struct node *temp1;
			temp1=(struct node *)malloc(sizeof(struct node));
			printf("enter the element");
			scanf("%d",&ele);
			temp1->e=ele;
			int i;
			for(i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
			temp1->next=temp->next;
			temp1->prev=temp;
			temp->next->prev=temp1;
			temp->next=temp1;
		}
		return head;
	}
}
struct node * insert_at_end(struct node *head)
{
	if(head==NULL)
	{
		head=insert_at_head(head);
	}
	else
	{
		struct node *temp,*temp1;
		temp1=(struct node *)malloc(sizeof(struct node));
		int ele;
		printf("enter the element");
		scanf("%d",&ele);
		temp1->e=ele;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;	
		}
		temp->next=temp1;
		temp1->prev=temp->next;
		temp1->next=NULL;
		
	}
	return head;	
}
struct node * delete_at_first(struct node *head)
{
	if(head==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		struct node *temp=head;
		if(temp->next==NULL)
		{
			head=NULL;
		}
		else
		{
			head=temp->next;
			temp->next->prev=NULL;
		}
	}
	return head;
}

struct node * delete_at_end(struct node *head)
{
	if(head==NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		struct node *temp=head;
		if(temp->next==NULL)
		{
			head=NULL;
		}
		else
		{
			struct node *temp1;
			while(temp->next!=NULL)
			{
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=NULL;
		}
	}
	return head;
}

struct node * delete_at_pos(struct node *head)
{
	int pos,len;
	len=length(head);
	printf("enter the position to delete");
	scanf("%d",&pos);
	if(pos>len)
	{
		printf("the position limit is exceeded");
	}
	else
	{
		if(pos==1)
		{
			head=delete_at_first(head);
		}
		else if(pos==len)
		{
			head=delete_at_end(head);
		}
		else
		{
			struct node *temp=head;
			int i=1;
			while(i<pos-1)
			{
				temp=temp->next;
				i=i+1;
			}
			temp->next->next->prev=temp;
			temp->next=temp->next->next;
		}
	}
	return head;
}
struct node * search_in_dlink(struct node *head)
{
	struct node *temp=head;
	int ele,flag=0;
	printf("enter the element");
	scanf("%d",&ele);
	if(head==NULL)
	{
		printf("there are no elements to search");
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->e==ele)
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag==1)
		{
			printf("the element is found in double linked list");
		}
		else
		{
			printf("the element not found in the double linked list");
		}
	}
	return head;	
}
struct node * insert_before_or_after(struct node * head)
{
	int pos,len,ba;
	printf("enter the postion");
	scanf("%d",&pos);
	if(pos>len)
	{
		printf("the limit is exceeded");
		return head;	
	}
	printf("do u want to insert before or after the postion \n 1-Before and 2 for after");
	scanf("%d",&ba);
	if(ba==1)
	{
		pos=pos-1;
	}
	else
	{
		if(ba==2)
		{
			pos=pos+1;
		}	
	} 
	len=length(head);
	if(pos>len)
	{
		printf("the limit is exceeded");
		return head;	
	}
	else
	{
		if(pos==1)
		{
			head=insert_at_head(head);
		}
		else if(pos==0)
		{
			printf("cannot insert at zero th position");
		}
		else
		{
			int ele;
			struct node *temp=head;
			struct node *temp1;
			temp1=(struct node *)malloc(sizeof(struct node));
			printf("enter the element");
			scanf("%d",&ele);
			temp1->e=ele;
			int i;
			for(i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
			temp1->next=temp->next;
			temp1->prev=temp;
			temp->next->prev=temp1;
			temp->next=temp1;
		}
		return head;
	}	
}
void main()
{
	struct node *head;
	head=NULL;
	int op;
	printf("Welcome to the dOuble linked list ");
	do
	{
		printf("\n the options are :\n 1-insert at head \n 2-insert at position \n 3-insert at end \n 4-delete at first \n 5-delete at position \n 6-delete at end \n 7-to search in double linked list \n 8-to insert at before or after \n 0-exit \n enter ur option :");
		scanf("%d",&op);
		switch(op)
		{
			case 0:
				break;
			case 1:
				head=insert_at_head(head);
				printList(head);
				break;
			case 2:
				head=insert_at_pos(head);
				printList(head);
				break;
			case 3:
				head=insert_at_end(head);
				printList(head);
				break;
			case 4:
				head=delete_at_first(head);
				printList(head);
				break;
			case 5:
				head=delete_at_pos(head);
				printList(head);
				break;
			case 6:
				head=delete_at_end(head);
				printList(head);
				break;
			case 7:
				search_in_dlink(head);
				break;
			case 8:
				head=insert_before_or_after(head);
				printList(head);
				break;
			default:
				printf("invalid option\n");		
		}	
	}while(op!=0);
}
