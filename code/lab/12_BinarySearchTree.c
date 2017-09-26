#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertNode(int, NODEPTR);

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
					root = insert(iItem,root);
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
