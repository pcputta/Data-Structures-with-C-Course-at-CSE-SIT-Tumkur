#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

struct node
{
	int Info;
	struct node *llink;
	struct node *rlink;
};

typedef struct node* NODE;


NODE getnode()
{
	NODE newborn;
	newborn = (NODE)malloc(sizeof(struct node));

	if(newborn == NULL)
	{
		printf("\nMemory Overflow");
		exit(0);
	}
	return newborn;
}

void freenode(NODE x)
{
	free(x);
}

NODE insert(int item,NODE root)
{
	NODE temp,prev,cur;

	temp = getnode();
	temp->Info = item;
	temp->llink = NULL;
	temp->rlink = NULL;

	if(root == NULL)
	return temp;

	prev = NULL;
	cur = root;

	while(cur != NULL)
	{
		prev = cur;

		if(item == cur->Info)
		{
			printf("\nDuplicate items not allowed\n");
			freenode(temp);
			return root;
		}

		cur = (item < cur->Info)? cur->llink: cur->rlink;
	}

	if(item < prev->Info)
	prev->llink = temp;
	else
	prev->rlink = temp;

	return root;

}

void preorder(NODE root)
{
	if(root != NULL)
	{
		printf("%d\t",root->Info);
		preorder(root->llink);
		preorder(root->rlink);
	}
}

void inorder(NODE root)
{
	if(root != NULL)
	{
		inorder(root->llink);
		printf("%d\t",root->Info);
		inorder(root->rlink);
	}
}

void postorder(NODE root)
{
	if(root != NULL)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d\t",root->Info);
	}
}

void display(NODE root,int i)
{
	int j;
	if(root != NULL)
	{
		display(root->rlink,i+1);
		for(j=1;j<=i;j++)
		printf(" ");

		printf("%d",root->Info);

		display(root->llink,i+1);
	}
}


main()
{
	NODE root = NULL;
	int ch,item,flag;
//	clrscr();

	for(;;)
	{
		printf("\n1.Insert\n2.Inorder traversal\n3.Preorder traversal");
		printf("\n4.Postorder traversal\n5.Display\n6.Exit\n");
		printf("\nEnter your choice");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter the item to be inserted \n");
					scanf("%d",&item);
					root = insert(item,root);
					break;

			case 2: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nInorder Traversal is :\n");
						inorder(root);
						printf("\n");
					}
					break;

			case 3: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nPreorder Traversal is :\n");
						preorder(root);
						printf("\n");
					}
					break;

			case 4: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nPostorder Traversal is :\n");
						postorder(root);
						printf("\n");
					}
					break;

			case 5: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nThe given Tree is:\n");
						display(root,1);
					}
					break;

			case 6: exit(0);

			default: printf("Wrong choice\n");
					 break;

		}

	}

}
