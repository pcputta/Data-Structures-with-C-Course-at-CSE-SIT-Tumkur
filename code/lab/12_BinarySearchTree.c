#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node* NODEPTR;

/* FUNCTION PROTOTYPES */
NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertNode(int, NODEPTR);
void fnInOrder(NODEPTR);
void fnPreOrder(NODEPTR);
void fnPostOrder(NODEPTR);
NODEPTR fnDeleteNode(int, NODEPTR);

int main()
{
	NODEPTR root = NULL;
	int iChoice,iItem;
	for(;;)
	{
		printf("\n1.Insert a node\n2.Inorder traversal\n3.Preorder traversal");
		printf("\n4.Postorder traversal\n5.Delete a node\n6.Exit\n");
		printf("\nEnter your choice");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1: printf("Enter the iItem to be inserted \n");
					scanf("%d",&iItem);
					root = fnInsertNode(iItem,root);
					break;

			case 2: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nInorder Traversal is :\n");
						fnInOrder(root);
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
						fnPreOrder(root);
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
						fnPostOrder(root);
						printf("\n");
					}
					break;

			case 5: printf("\nEnter node to be deleted : ");
				    scanf("%d", &iItem);
				    root = fnDeleteNode(iItem, root);
				    break;

			case 6: exit(0);

			default: printf("Wrong choice\n");
					 break;

		}

	}

	return 0;
}

NODEPTR fnGetNode(void)
{
	NODEPTR x;
	x = ( NODEPTR ) malloc (sizeof(struct node));
	if(x == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return x;
}

void fnFreeNode(NODEPTR x)
{
	free(x);
}

NODEPTR fnInsertNode(int iItem,NODEPTR root)
{
	NODEPTR temp,prev,cur;

	temp = getnode();
	temp->Info = iItem;
	temp->lchild = NULL;
	temp->rchild = NULL;

	if(root == NULL)
	return temp;

	prev = NULL;
	cur = root;

	while(cur != NULL)
	{
		prev = cur;

		if(iItem == cur->Info)
		{
			printf("\nDuplicate items not allowed\n");
			freenode(temp);
			return root;
		}

		cur = (iItem < cur->Info)? cur->lchild: cur->rchild;
	}

	if(iItem < prev->Info)
	prev->lchild = temp;
	else
	prev->rchild = temp;

	return root;

}

void fnPreOrder(NODEPTR root)
{
	if(root != NULL)
	{
		printf("%d\t",root->Info);
		fnPreOrder(root->lchild);
		fnPreOrder(root->rchild);
	}
}

void fnInOrder(NODEPTR root)
{
	if(root != NULL)
	{
		fnInOrder(root->lchild);
		printf("%d\t",root->Info);
		fnInOrder(root->rchild);
	}
}

void fnPostOrder(NODEPTR root)
{
	if(root != NULL)
	{
		fnPostOrder(root->lchild);
		fnPostOrder(root->rchild);
		printf("%d\t",root->Info);
	}
}

NODEPTR fnDeleteNode(int iItem, NODEPTR root)
{
	NODEPTR prev, cur, leftChild, newParent;
	
	if(root == NULL)
	{
	    printf("\nBST is empty, cannot delete");
	    return root;
	}
	prev = NULL;
	cur = root;
}
