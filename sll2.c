#include<stdio.h>
#include<stdlib.h>
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
    temp->data=num;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
        c++;
    }
    else if(head->next==NULL)
    {
        if(head->data<=num)
        {
            temp->next=NULL;
            head->next=temp;
            c++;
        }
        else
        {
            head->next=NULL;
            right=head;
            head=temp;
            head->next=right;
            c++;
        }

    }
    else
    {
        right=head;
        while(right->data<num&&right->next!=NULL)
        {
            printf("")
            left=right;
            right=right->next;
        }
        left->next=temp;
        temp->next=right;
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
int main()
{
	int num,choice=1;
	do
	{
	printf("1.add \n2.display\n3.exit\n");

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

			/*case 4:
			delete();
			break;*/

			default:
			printf("Enter a valid number");
			break;
		}
	}while(choice!=3);





}
