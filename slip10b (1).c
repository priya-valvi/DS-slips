

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//To define a structure sll
struct sll
{
	int data;
	struct sll *next;
};
typedef struct sll node;

//To declare functions
node * create(node *);
void display(node*);
void search(node*);

void main()
{
	int ch;
	node*head=NULL; // head is pointer
	
	head=create(head);
	display(head);
	search(head);
	getch();
}

//To create node
node *create(node*head)
{
	node*temp=NULL,*last=NULL;
	int n,i;
	printf("\nEnter how many nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(node*)malloc(sizeof(node)); // allocate memory dynamically
		printf("\nEnter data: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			last=head;
			while(last->next!=NULL)
			{
				last=last->next;
			}
			last->next=temp;
		}
	}     return head;
}

//To display all nodes in sll
void display(node *head)
{
	node*last=NULL;
	if(head==NULL)
	printf("\nempty.");
	else
	{
		printf("\ncontent: ");
		last=head;
		while(last!=NULL)
		{
			printf("%d ",last->data);
			last=last->next;

		}
	}
}

//To search Odd, Even and Zero elements from given Singly Linked List
void search(node*head)
{
	node*last=NULL;

	int count=0,cnt=0,c=0; // count = to count zero elements , cnt=to count even no , c=to count odd //no
	last=head;
	while(last->next!=NULL)
	{
		if(last->data==0)
		{
		    count=count+1;
		    last=last->next;
		}
		else
		{
			if((last->data%2)==0)
			{
			  cnt=cnt+1;
			  last=last->next;
			}
			else
			{
			   c=c+1;
			   last=last->next;
			}

		}
   }
      if(last->data==0)
		{
	
		    count=count+1;
		    last=last->next;
		}
		else
		{
			if((last->data%2)==0)
			{
			  cnt=cnt+1;
			  last=last->next;
			}
			else
			{
			   c=c+1;
			   last=last->next;
			}
		}

	printf("\ntotal zero elements:%d ",count);
	printf("\ntotal even no:%d ",cnt);
	printf("\ntotal odd no:%d ",c);

}