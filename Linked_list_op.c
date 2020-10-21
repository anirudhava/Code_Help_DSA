#include<stdio.h>
#include<stdlib.h>

struct List
{
	struct Node*head;
	struct Node*tail;
	int count;
};

struct Node
{
	int key;
	struct Node* link;
};

struct List* init(struct List* list)
{
	list=(struct List*)malloc(sizeof(struct List));
	list->head=NULL;
	list->tail=NULL;
	list->count=0;
	return list;
}

struct Node* create_node(struct Node* temp,int k)
{
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->key=k;
	temp->link=NULL;
	return temp;
}

void insert_begin(struct List* list,struct Node* temp)
{
	if(list->head==NULL)//list is empty
	{
		list->tail=list->head=temp;
	}
	else
	{	
		temp->link=list->head;
		list->head=temp;
	}
	list->count+=1;
}
	
void insert_end(struct List* list,struct Node* temp)
{
	list->tail->link=temp;
	list->tail=temp;
	list->count+=1;		
}

void insert(struct List* list,int k,int pos)
{
	if(pos > list->count)
	{
		printf("Invalid pos\n");
		return;
	}	

	struct Node*temp;
	temp=create_node(temp,k);
	
	if(pos==0)
	{
		insert_begin(list,temp);
		return;
	}
	if(pos==list->count)
	{
		insert_end(list,temp);
		return;
	}
	else//insert in the middle
	{
		struct Node*p;
		struct Node*q;
			
		p=list->head;
		q=NULL;

		int i=1;
	
		while(i<=pos)//traversing
		{
			q=p;
			p=p->link;
			i++;
		}
		
		//inserting

		q->link=temp;
		temp->link=p;
		list->count+=1;
	}
}

void delete(struct List* list,int element)
{	
	if(list->head==NULL)
	{
		printf("empty list\n");
		return;
	}
	
	if(list->count==1)
	{
		if(list->head->key==element)
		{	
			list->head=list->tail=NULL;
			list->count=0;
			return;
		}	
		else
		{
			printf("Element Not present in list\n");
			return;
		}
	}
	
	struct Node*p;
	struct Node*q;
	
	p=list->head;
	q=NULL;

	while(p!=NULL && p->key!=element)//traverse
	{
		q=p;
		p=p->link;
	}

	if(p==NULL)
	{
		printf("Element Not present in list\n");
		return;
	}

	if(q==NULL)//1st element to be deleted
	{
		list->head=list->head->link;
		free(p);
		list->count-=1;
		return;
	}

	if(p->link==NULL)//last element to be deleted
	{
		list->tail=q;
		free(p);
		list->count-=1;
		q->link=NULL;
		return;
	}

	//delete middle element
		
	q->link=p->link;
	p->link=NULL;
	free(p);
	list->count-=1;
}

void display(struct List* list)
{
	struct Node*p;
	p=list->head;	
		
	while(p!=NULL)
	{
		printf("%d ",p->key);
		p=p->link;
	}

	printf("\n");
}

int main()
{
	struct List* list;
	
	list=init(list);

	while(1)
	{
		printf("Enter\n1.Insert\n2.Delete\n3.display list\n4.exit\n");
		int op;
		scanf("%d",&op);

		switch(op)
		{
			case 1:
			{
				printf("Enter key\n");
				int k;
				scanf("%d",&k);

				printf("Enter the pos\n");
				int pos;
				scanf("%d",&pos);

				insert(list,k,pos);

				break;
			}
			case 2:
			{
				printf("Enter the element to be deleted\n");
				
				int d;
				scanf("%d",&d);

				delete(list,d);

				break;
			}
			case 3:
			{
				display(list);

				break;
			}
			case 4:
			{
				exit(0);
			}
		}
	}	
}
