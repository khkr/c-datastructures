#include<stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *right,*left;
}*root=NULL;

void insertrec(struct node *root,int key);

void inorderrec(struct node *root);


void insert(int key)
{
	insertrec(root,key);
}

void insertrec(struct node *root,int key)
{
	if(root==NULL)
	{
		root= (struct node*)malloc(sizeof(struct node));
		root->data=key;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	if(key<root->data)
		insertrec(root->left,key);

	else if(key>root->data)
		insertrec(root->right,key);
}
void inorder()
{
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	inorderrec(root);
	printf("\n");
}

void inorderrec(struct node* root)
{
	if(root!=NULL)
	{
		inorderrec(root->left);

		printf("%d\t",root->data) ;

		inorderrec(root->right);

	}

}

int main()
{
	int choice=1,key;
	do
	{
		printf("Enter your choice\n");
		printf("1.insert\n2.inorder display\n3.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter a number\n" );
			scanf("%d",&key);
			insert(key);
			break;
			case 2:
			inorder();
			break;
			case 3:
			break;
			default:
			printf("Enter a valid number\n");
		}

	}while(choice!=3);
}



