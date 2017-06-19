#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp =  (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \t", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
	if (key < node->key)
		node->left  = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);   

    /* return the (unchanged) node pointer */
	return node;
}

// void delete(struct node* root,int key)
// {
// 	if(root!=NULL)
// 	{
// 		if(root->data==key)
// 		{

// 		}
		
// 	}
	

// }


int main()
{
	struct node *root = NULL;
	
	int choice =1, key;


	do
	{
		printf("Select a function \n1. Insert\n2. Inorder\n3. Exit\n");

		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("Enter a number\n");
			scanf("%d",&key); 
			if(root==NULL)
				root = insert(root, key);
			else
				insert(root,key);
			break;

			case 2: inorder(root);
			printf("\n");
			break;

			case 3: break;

			default: break;
		}
	}while(choice!=3);

}





