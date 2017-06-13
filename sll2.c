#include <stdio.h>
#include <stdlib.h>
int c=0;
struct node
{
    int data;
    struct node *next;

}*head=NULL;
void add(int num)
{
    struct node *temp,*right,*left;
    temp=(struct node *)malloc(sizeof(struct node));

	//We are defining the temp to alleviate any errors in future so we are also mentioning that temp->next = null;
    temp->data=num;
    temp->next= NULL;

	//if head is null temp is going to be the first element
    if(head==NULL)
    {
        head=temp;
        c++;
    }
	//in this case if we have only one element i.e head and we want to add other element
	//eg: existing: 5, input:3
    else if (num<head->data)
    {
        temp->next = head;
        head = temp;
        c++;
    }

    else
    {
        left = head;
        right = head->next;

        while(right!=NULL&&num>right->data)
        {
            left = right;
            right = right->next;
        }
	    //if after checking right happened to be null
	    //it happens in scenarios like
	    //existing: 1 2 3 , input : 5
        if(right==NULL)
        {
            left->next=temp;

        }

	    //This is for the rest of the scenarios like existing: 1 3 , input: 2

        else{
            temp->next = right;
            left->next = temp;

        }
	    //we have to add it for every input
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
		int i;
		for( i=1;i<=c;i++)
		{
			printf("%d\t",right->data);
			right=right->next;
		}

			printf("\n");
	}
}
void deleteByValue(int value)
{
	if(head==NULL)
	{
		printf("linked list is empty.Unable to delete");

			printf("\n");
	}
	else
	{

	struct node *right,*t,*left;
	int confirm=0;
	if( head->data == value)
	{
		t=head;
		head=head->next;
		free(t);
		confirm=1;
		c--;
		printf("%d is deleted successfully\n",value);
	}
	else
	{
		right=head;

		while(right->next!=NULL)
		{
			left=right;
			right=right->next;
			if(right->data==value)
			{
				t=right;
				left->next=right->next;
				free(t);
				t=NULL;
                printf("%d is deleted successfully\n\n",value );
                confirm=1;
                c--;
                break;
			}
		}
	}
	if(confirm==0)
		printf("\n%d didn't found\n\n",value);
	}

}

void deleteByPosition(int position)
{
	if(head==NULL)
	{
		printf("linked list is empty.Unable to delete\n");
		return;
	}

	if(position ==1)
	{
		struct node *t;
		t=head;
		head=head->next;
		printf("%d is deleted successfully\n",t->data);
		free(t);
		c--;
		return;
	}


	struct node *right,*left;
	right=head;
	int i;

	for( i=1;i<position;i++)
	{
		left=right;
		right=right->next;
	}
	printf("%d is deleted\n",right->data);
	left->next=right->next;
	free(right);
	c--;
    return;
}
int main()
{
	int num,choice=1;
	do
	{
	printf("1.add \n2.display\n3.exit\n4.delete by value\n5.Delete by position\n");

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
			printf("Enter a number to delete\n");
			scanf("%d",&num);
			deleteByValue(num);
			break;

			case 5:
                printf("Enter the position to delete\n");
                scanf("%d",&num);
                deleteByPosition(num);
                break;

			default:
			printf("Enter a valid number");
			break;
		}
	}while(choice!=3);





}
