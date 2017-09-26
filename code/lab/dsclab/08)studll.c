#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int Id;
	char Name[30];
	int Sem;
	struct node *link;
};

typedef struct node* NODE;

NODE getnode(void)
{
	NODE x;
	x = ( NODE ) malloc (sizeof(struct node));
	if(x == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE ins_front(char name[],int id,int sem,NODE first)
{
	NODE temp;
	temp = getnode();
	strcpy(temp->Name,name);
	temp->Sem = sem;
	temp->Id = id;
	temp->link = first;
	first = temp;
	return first;

}

NODE ins_rear(char name[],int id,int sem,NODE first)
{
	NODE temp,cur;
	temp = getnode();
	strcpy(temp->Name,name);
	temp->Sem = sem;
	temp->Id = id;
	temp->link = NULL;

	if(first == NULL)
	return temp;

	cur = first;
	while(cur->link != NULL)
	{
		cur = cur->link;
	}

	cur->link = temp;
	return first;
}

NODE ins_pos(char name[],int id,int sem,int pos,NODE first)
{
	NODE temp,prev,cur;
	int count;

	temp = getnode();
	strcpy(temp->Name,name);
	temp->Sem = sem;
	temp->Id = id;
	temp->link = NULL;

	if(first == NULL && pos == 1)
	return temp;

	if(first == NULL)
	{
		printf("\nInvalid Position");
		return first;
	}

	if(pos == 1)
	{
		temp->link = first;
		return temp;
	}


	count = 1;
	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = temp;
		temp->link = cur;
		return first;
	}

	printf("\nInvalid Position");
	return first;
}

NODE del_std(int id, NODE first)
{
	NODE prev,cur;

	if(first == NULL)
	{
		printf("\nNo students in the class\n");
		return NULL;
	}

	prev = NULL;
	cur = first;

	while(cur != NULL && id != cur->Id)
	{
		prev = cur;
		cur = cur->link;
	}

	if(cur == NULL)
	{
		printf("\nStudent id not found\n");
		return first;
	}

	if(prev == NULL)
		first = first->link;
	else
		prev->link = cur->link;


	free(cur);
	return first;

}

void search_upd(int id,NODE first)
{
	NODE cur;

	if(first == NULL)
	{
		printf("\n No students in the Class\n");
		return;
	}

	cur = first;
	while(cur != NULL && id != cur->Id)
	{
		cur = cur->link;
	}

	if(cur == NULL)
	{
		printf("\nStudent with id %d is not found\n",id);
		return;
	}
	printf("Student found with following information\n");
	printf("=========================================\n");
	printf("Name: %s \tId: %d \tSem: %d\n",cur->Name,cur->Id,cur->Sem);
}

void display(NODE first)
{
	NODE temp;

	if(first == NULL)
	{
		printf("\nNo students in the Organisation\n");
		return;
	}

	printf("\nStudent Name Student Id Semester\n");
	printf("==================================\n");
	for(temp = first; temp != NULL; temp = temp->link)
	printf("%10s	%4d	%4d\n",temp->Name,temp->Id,temp->Sem);
	printf("\n\n");

}

main()
{
	NODE first = NULL;
	int ch, id, sem, pos;
	char name[30];

//	clrscr();

	for(;;)
	{
		printf("\n1.Insert_front\n2.Insert_rear\n3.Insert at Position");
		printf("\n4.Delete\n5.Search\n6.Display");
		printf("\n7.Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		if(ch==1 || ch==2 || ch==3)
		{
			printf("\nName : ");
			scanf("%s",name);
			printf("\nId : ");
			scanf("%d",&id);
			printf("\nSem : ");
			scanf("%d",&sem);
		}

		switch(ch)
		{
			case 1: first = ins_front(name,id,sem,first);
				break;

			case 2: first = ins_rear(name,id,sem,first);
				break;

			case 3:
			printf("\nEnter the Position to insert the entry\n");
			scanf("%d",&pos);
			first = ins_pos(name,id,sem,pos,first);
				break;

			case 4:
			printf("\n Enter Student ID to delete\n");
			scanf("%d",&id);
			first = del_std(id,first);
				break;

			case 5:
			printf("\nSearch with Id\n");
			scanf("%d",&id);
			search_upd(id,first);
				break;

			case 6:
			display(first);
			break;

			case 7: exit(0);
		}
	}
}











