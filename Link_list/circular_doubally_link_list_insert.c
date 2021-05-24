//Name: Aniket Sinha Roy
// CSE 2nd year
//Assignment: 11
//Roll: 60
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* next;
	struct node* previous;
};
struct node *top;
void insert_node(int n)
{
	int i,b;
	struct node *temp,*d;
	printf("enter the numbers: ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&b);
		temp=(struct node*)malloc(sizeof(struct node));
		if(top==NULL)
		{
			temp->a=b;
			temp->next=temp;
			temp->previous=temp;
			top=temp;
		}
		else
		{
			temp->a=b;
			d=top->previous;
			temp->next=top;
			temp->previous=d;
			d->next=temp;
			top->previous=temp;
		}	
	}
	printf("Doubled Link list created\n");
}
void insert_b(int n)
{
	struct node *temp,*d;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		temp->a=n;
		temp->next=temp;
		temp->previous=temp;
		top=temp;
	}
	else
	{
		temp->a=n;
		temp->previous=top->previous;
		d=top->previous;
		d->next=temp;
		temp->next=top;
		top->previous=temp;
		top=temp;
	}
	printf("Inserted at the beginning.\n");
}
void insert_e(int n)
{
	struct node *temp,*d;
	temp=(struct node*)malloc(sizeof(struct node));
	if(top==NULL)
	{
		temp->a=n;
		temp->next=temp;
		temp->previous=temp;
		top=temp;
	}
	else
	{
		d=top->previous;
		temp->a=n;
		temp->next=top;
		d->next=temp;
		temp->previous=d;
		top->previous=temp;
	}
	printf("Inserted at the end.\n");
}
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		temp=top;
		while(temp->next!=top)
		{
			printf("%d\n",temp->a);
			temp=temp->next;
		}
		if(temp->next==top)
			{
				printf("%d\n",temp->a);
		    }
	}		
}
int main()
{
	char c;
	do
	{
		int i,n,m;
		printf("what do you want to do?\n");
		printf( " 1)create a circular doubly linked list\n 2)insert a node at the beginning\n 3)insert a node at the end\n 4)display the list\n 5) exit\n");
	    scanf("%d",&i);
	    printf("\n");
		switch(i)
		{
			case 1:
				{
					printf("enter how many nodes do you want to inserted: \n");
					scanf("%d",&n);
					insert_node(n);
					break;
				}
			case 2:
			    {
			    	printf("enter the number: \n");
			    	scanf("%d",&n);
				    insert_b(n);
				    break;
			    }	
			case 3:
			    {
			    	printf("enter the number : \n");
			    	scanf("%d",&n);
			    	insert_e(n);
			    	break;
				}  
            case 4:
            	{
            		display();
					break;
				}
			case 5:
			    {
			    	printf("Exit\n");
					break;
				}	
			default :
				{
					printf("please enter a correct choice.\n");
					break;
				}
		}	
		printf("want to do again(y/n): \n");
		scanf(" %c",&c);
	}
	while((c=='y') || (c=='Y'));
	return 0;
}
