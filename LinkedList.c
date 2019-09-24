/*
 ============================================================================
 Name        : a9LL.c
 Author      : 23254
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*head;
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;

                temp = temp->next;
            }
        }

        printf("\nSINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;

        printf("\nDATA INSERTED SUCCESSFULLY\n");
    }
}
void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;

        head = newNode;

        printf("\nDATA INSERTED SUCCESSFULLY\n");
    }
}
void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;

            printf("\nDATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
void displayList()
{
	int i=1;
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data %d = %d\n",i, temp->data);
            temp = temp->next;
            i++;
        }
    }
}
void deleteFirstNode()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete);

        printf("\nSUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            secondLastNode->next = NULL;
        }

        printf("\nData deleted = %d\n", toDelete->data);
        free(toDelete);

        printf("\nSUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            printf("\nData deleted = %d\n", toDelete->data);
            free(toDelete);
            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}
void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL;

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;

        printf("\nSUCCESSFULLY REVERSED LIST\n\n");
    }
}

int main(void) {
	int n, data;
	int ch;
	int position;
	int flag=1,f1=1;
	int f=1;
	while(f)
	{
		printf("\n*LINKED LIST OPERATIONS*\n");
		printf("\n1.INSERT THE NODE\n2.DISPLAY THE LIST\n3.DELETE A NODE\n4.REVERSE LINKED LIST\n5.EXIT\n\nENTER YOU CHOICE:- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("ENTER THE NUMBER OF NODES YOU WANT TO CREATE:- ");
				scanf("%d",&n);
				createList(n);
				while(flag)
				{
					printf("\n\n1.INSERT AT THE END\n2.INSERT AT THE BEGINING\n3.INSERT IN THE MIDDLE\n4.BREAK\n\nENTER YOU'RE CHOICE:- ");
					int choice;
					scanf("%d",&choice);
					switch(choice)
					{
						case 1:
							printf("\nEnter data to insert at end of the list: ");
							scanf("%d", &data);
							insertNodeAtEnd(data);
							break;
						case 2:
							 printf("\nEnter data to insert at beginning of the list: ");
							 scanf("%d", &data);
							 insertNodeAtBeginning(data);
							 break;
						case 3:
							printf("\nEnter data to insert in the middle of the list: ");
							scanf("%d",&data);
							printf("\nEnter the position to insert new node: " );
							scanf("%d", &position);
							insertNodeAtMiddle(data, position);
							break;
						case 4:
							flag = 0;
					}

				}
				break;
			case 2:
				 printf("\nData in the list \n");
				 displayList();
				 break;
			case 3:
				while(f1)
				{
					printf("\n\n1.DELETE FIRST NODE\n2.DELETE LAST NODE\n3.DELETE THE NODE AT ANY POSITION\n4.BREAK\n\nENTER YOU'RE CHOICE:- ");
					int choice;
					scanf("%d",&choice);
					switch(choice)
					{
						case 1:
							deleteFirstNode();
							displayList();
							break;
						case 2:
							 deleteLastNode();
							 displayList();
							 break;
						case 3:
							printf("\nEnter the node position you want to delete: ");
							scanf("%d", &position);
						 	deleteMiddleNode(position);
						 	displayList();
						 	break;
						case 4:
							f1=0;
							break;
					}
				}
				break;
			case 4:
				reverseList();
				displayList();
				break;
			case 5:
				f=0;
				break;
		}
	}

	return EXIT_SUCCESS;
}
