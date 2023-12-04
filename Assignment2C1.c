#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

char stack[MAX];
int top = -1;

bool isEmpty()
{
	return top == -1;
}

bool isFull()
{
	return top == MAX -1;
}


char peek()
{
	if(!isEmpty())
	{
		return stack[top];
	}
		else
		{
			printf("peek() error. Stack is empty.\n");
			return '\0'; //return null when stack is empty
		}
}


char pop()
{
	if(!isEmpty())
	{
		return stack[top--];
	}
		else
		{
			printf("pop() error. Stack is empty.\n");
			return '\0';
		}
}


void push(char data)
{
	if(!isFull())
	{
		stack[++top] = data;
	}
		else
		{
			printf("\npush() error. Stack is full\n");
		}
}


int main()
{
	char arr[MAX];

	printf("First Last name, abc123\n");
	printf("Enter a string of 6 parentheses then press ENTER to proceed: ");


	for(int i = 0; i < MAX; i++)
	{
		scanf(" %c", &(arr[i]));
	}


	for(int i = 0; i < MAX; i++)
	{
		if(arr[i] == '{')
		{
			push(arr[i]);
		}
			else if(arr[i] == '}')
			{
				if(isEmpty())
				{
					printf("Error. Invalid parenthesis expression\n");
					return 1;
				}
				pop();
			}
			else
			{
				printf("Error. Invalid input.\n");
				return 1;
			}
	}


	if(isEmpty())
	{
		printf("Valid parenthesis expression.\n");
	}
		else
		{
			printf("Invalid parenthesis expression.\n");
		}

	return 0;
}

