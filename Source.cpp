#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *link;
}*top = NULL;				//struct Node *top = NULL

void push(int num);
int pop();
void display();
void bubbleSort();

void main()
{
	int choice, num;
	while (1)
	{
		printf("\n1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Bubble Sort \n");
		printf("5. Exit \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a number to be inserted : ");
			scanf("%d", &num);
			push(num);
		//	while (1)				//for stack overflow condition
		//		push(10);			//for stack overflow condition

			break;
		case 2:
			num = pop();
			break;
		case 3:
			display();
			break;
		case 4:
			bubbleSort();
			break;
		case 5:
			exit(1);
		default:
			printf("Invalid Input");
		}
	}
}
void push(int num)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
	{
		printf("Stack overflow \n");
		return;
	}
	temp->data = num;
	temp->link = top;
	top = temp;
}
int pop()
{
	int num;
	if (top == NULL)
	{
		printf("Stack underflow \n");
		return -1;
	}
	struct Node *temp = top;
	num = top->data;
	top = top->link;
	free(temp);
	printf("Deleted : %d \n", num);
	return num;
}
void display()
{
	if (top == NULL)
	{
		printf("Stack underflow \n");
		return;
	}
	printf("\nStack is \n");
	struct Node *temp = top;
	while (temp != NULL)
	{
		printf("%d \n", temp->data);
		temp = temp->link;
	}
}

void bubbleSort()
{
	int n = 0;
	struct Node *ptr = top;
	while (ptr != NULL)
	{
		ptr = ptr->link;
		n++;
	}

	for (int i = 0; i < n - 1; i++)
	{
		struct Node *top_ref = top;

		int flag = 0;

		for (int j = 0; j < n - i - 1; j++)
		{
			if ( top_ref->data < top_ref->link->data )
			{
				int temp = top_ref->data;
				top_ref->data = top_ref->link->data;
				top_ref->link->data = temp;

				flag = 1;			// if swapping happens update flag to 1
			}
			top_ref = top_ref->link;
		}
		// if value of flag is zero after all the iterations of inner loop then break out
		if (flag == 0)
		{
			break;
		}
	}
}
