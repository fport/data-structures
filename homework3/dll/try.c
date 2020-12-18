#include<stdlib.h>
#include<stdio.h>
 
struct node
{
	struct node *prev_node;
	int info;
	struct node *next_node;
};
 
struct node *create_list(struct node *begin);
void display(struct node *begin);
struct node *addtoemptylist(struct node *begin,int data_element);
struct node *addatbeglist(struct node *begin,int data_element);
struct node *addatendlist(struct node *begin,int data_element);
struct node *addafterlist(struct node *begin,int data_element,int item_pos);
struct node *addbeforelist(struct node *begin,int data_element,int item_pos);
struct node *deletenode(struct node *begin,int data_element);
struct node *reverselist(struct node *begin);
 
int main()
{
	int option,data_element,item_pos;
	struct node *begin=NULL;
	while(1)
	{
		printf("\n1.Create A New Doubly Linked List\n");
		printf("2.Display the Doubly Linked List\n");
		printf("3.Add to an Empty Doubly Linked List\n");
		printf("4.Add at Starting of the Doubly Linked List\n");
		printf("5.Add at Ending\n");
		printf("6.Add After a Node\n");
		printf("7.Add Before a Node\n");
		printf("8.Delete a Node\n");
		printf("9.Reverse the Doubly Linked List\n");
		printf("10.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&option);
		switch(option)
		{
		 case 1:
			begin=create_list(begin);
			break;
		 case 2:
			display(begin);
			break;
		 case 3:
			printf("Enter the element:");
			scanf("%d",&data_element);
			begin=addtoemptylist(begin,data_element);
			break;
		 case 4:
	        		printf("Enter the element:");
			scanf("%d",&data_element);
			begin=addatbeglist(begin,data_element);
			break;
		 case 5: 
			printf("Enter the element:");
			scanf("%d",&data_element);
			begin=addatendlist(begin,data_element);
			break;
		 case 6:
			printf("Enter the element:");
			scanf("%d",&data_element);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item_pos);
			begin=addafterlist(begin,data_element,item_pos);
			break;
		 case 7:
			printf("Enter the element: ");
			scanf("%d",&data_element);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item_pos);
			begin=addbeforelist(begin,data_element,item_pos);
			break;
		 case 8:
			printf("Enter the element to be Deleted : ");
			scanf("%d",&data_element);
			begin=deletenode(begin,data_element);
	   		break;
		 case 9:
		 	begin=reverselist(begin);
			break;
		 case 10:
			exit(1);
		 default:
			printf("Wrong option\n");
	}
   }
}
 
struct node *create_list(struct node *begin)
{
	int i,n,data_element;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	begin=NULL;
	if(n==0)
		return begin;
	printf("Enter the element: ");
	scanf("%d",&data_element);
	begin=addtoemptylist(begin,data_element);
		
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data_element);
		begin=addatendlist(begin,data_element);	
	}
	return begin;
}
 
void display(struct node *begin)
{
	struct node *p;
	if(begin==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=begin;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next_node;
	}
	printf("\n");
}
 
struct node *addtoemptylist(struct node *begin,int data_element)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data_element;
	temp->prev_node=NULL;
	temp->next_node=NULL;
	begin=temp;
	return begin;
}
 
struct node *addatbeglist(struct node *begin,int data_element)
{
if(begin==NULL)
	{
		printf("List is empty\n");
		return;
	}
 
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info=data_element;
	temp->prev_node=NULL;
	temp->next_node=begin;
	begin->prev_node=temp;
	begin=temp;
	return begin;
}
 
struct node *addatendlist(struct node *begin,int data_element)
{
	if(begin==NULL)
	{
		printf("List is empty\n");
		return;
	}
 
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data_element;
	p=begin;
	while(p->next_node!=NULL)
		p=p->next_node;
	p->next_node=temp;
	temp->next_node=NULL;
	temp->prev_node=p;
	return begin;
}
 
struct node *addafterlist(struct node *begin,int data_element,int item_pos)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data_element;
	p=begin;
	while(p!=NULL)
	{
		if(p->info==item_pos)
		{
			temp->prev_node=p;
			temp->next_node=p->next_node;
			if(p->next_node!=NULL) 
				p->next_node->prev_node=temp;
			p->next_node=temp;
			return begin;	
		}
		p=p->next_node;
	}
	printf("%d not present in the list\n\n",item_pos);
	return begin;
}
 
struct node *addbeforelist(struct node *begin,int data_element,int item_pos)
{
	struct node *temp,*q;
	if(begin==NULL )
	{
		printf("List is empty\n");
		return begin;
	}
	if(begin->info==item_pos)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info=data_element;
		temp->prev_node=NULL;
		temp->next_node=begin;
		begin->prev_node=temp;
		begin=temp;
		return begin;
	}
	q=begin;
	while(q!=NULL)
	{
		if(q->info==item_pos)
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=data_element;
			temp->prev_node=q->prev_node;
			temp->next_node = q;
			q->prev_node->next_node=temp;
			q->prev_node=temp;
			return begin;
		}	
		q=q->next_node;
	}
	printf("%d not present in the list\n",item_pos);
	return begin;
}	
 
struct node *deletenode(struct node *begin,int data_element)
{
	struct node *temp;
	if(begin==NULL)
	{
		printf("List is empty\n");
		return begin;
	}
	if(begin->next_node==NULL)	
		if(begin->info==data_element) 
		{
			temp=begin;
			begin=NULL;
			free(temp);
			return begin;
		}
		else
		{
			printf("Element %d not found\n",data_element);
			return begin;
		}
	
	if(begin->info==data_element)
	{
		temp=begin;
		begin=begin->next_node;  
		begin->prev_node=NULL;
		free(temp);
		return begin;
	}
 
	temp=begin->next_node;
	while(temp->next_node!=NULL )
	{
		if(temp->info==data_element)     
		{
			temp->prev_node->next_node=temp->next_node;
			temp->next_node->prev_node=temp->prev_node;
			free(temp);
			return begin;
		}
		temp=temp->next_node;
	}
 
	if(temp->info==data_element)
	{
		temp->prev_node->next_node=NULL;
		free(temp);
		return begin;
	}
	printf("Element %d not found\n",data_element);
	return begin;
}
 
struct node *reverselist(struct node *begin)
{
	if(begin==NULL)
	{
		printf("List is empty\n");
		return begin;
	}
 
	struct node *p1,*p2;
	p1=begin;
	p2=p1->next_node;
	p1->next_node=NULL;
	p1->prev_node=p2;
	while(p2!=NULL)
	{
		p2->prev_node=p2->next_node;
		p2->next_node=p1;
		p1=p2;
		p2=p2->prev_node; 
	}
	begin=p1;
	printf("List reverselistd\n");
	return begin;
}