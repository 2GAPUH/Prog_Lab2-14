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
	int max, min;
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
			max = -1, min = 10;
			while (getchar() != '\n');
			printf_s("Enter your number: ");
			while ((tmp = getchar()) != '\n')
			{
				tmp -= '0';
				if (tmp > max)
					max = tmp;
				if (tmp < min)
					min = tmp;
				PushToStack(&stack, tmp);
			}
			if(max != -1)
				printf_s("max = %d\t min = %d\n", max, min);
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