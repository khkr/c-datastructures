#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
int c=0;
void add(int num)
{
	struct node *right,*temp ;

	temp =(struct node*)malloc(sizeof(struct node));
	temp->data=num;
		if(head==NULL)
	{
		temp->next=head;
		right = head;
		head =temp;
		c++;
	}
	else
	{
		right=head;
		while(right->next!=NULL)
		{
			right=right->next;
		}
		right->next=temp;
		temp->next=NULL;
		c++;

	}


} 
void display()
{
	struct node *right;

	if(head==NULL)
	{
		printf("linked list is empty");

			printf("\n");
	}
	else
	{
		right=head;
		for(int i=1;i<=c;i++)
		{
			printf("%d\t",right->data);
			right=right->next;
		}

			printf("\n");
	}

}
void delete()
{
	if(c!=0){
	c--;
	struct node *right;
	right=head;
	for(int i=1;i<c;i++)
	{
		right=right->next;
	}
	right->next=NULL;
}
	else 
		if(c==0)
	{
		head=NULL;
		printf("linked list is empty");	

	}




}
int main()
{
	int num,choice=1;
	do
	{ 
	printf("1.add \n2.display\n3.exit\n4.delete\n");

		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			scanf("%d",&num);
			add(num);
			break;

			case 2:
			printf("\n");
			display();
			break;

			case 3:
			break;

			case 4:
			delete();
			break;

			default:
			printf("Enter a valid number");
			break;
		}
	}while(choice!=3);





}