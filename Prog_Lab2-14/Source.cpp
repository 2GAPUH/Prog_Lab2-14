#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Stack.h"



void StackLoop()
{
	mainStack stack = {NULL, NULL, NULL};
	int userChoice = NULL;
	double tmp;
	bool loop = 1;



	printf_s("1 - Add new element \n2 - Pop element \n3 - Peek element \n4 - Clear \n5 - Task \n6 - Exit \n");

	while (loop)
	{
		printf_s("Your choice: ");
		scanf_s("%d", &userChoice);

		switch (userChoice)
		{
		case 1:
			printf_s("Entrer your number: ");
			scanf_s("%lf", &tmp);
			PushToStack(&stack, tmp);
			break;

		case 2:
			if ((tmp = PopStack(&stack)) != LONG_MAX)
				printf_s("You pop %.2lf\n", tmp);
			break;

		case 3:
			if ((tmp = PeekStack(&stack)) != LONG_MAX)
				printf_s("You peek %.2lf\n", tmp);
			break;

		case 4:
			ClearStack(&stack);
			break;

		case 5:
			break;

		case 6:
			loop = 0;
			break;

		default:
			printf_s("Invalid value! Try again.\n");
			break;
		}

		PrintStack(&stack);
	}

	if(stack.array)
		DestroyStack(&stack);
}


int main()
{
	StackLoop();

	return 0;
}