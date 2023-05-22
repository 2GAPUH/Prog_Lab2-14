#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Stack.h"

/*Ввести некоторое число и записать его цифры в стек. Вывести
число, у которого цифры идут в обратном порядке. Цифры из
записи числа считывать поочередно (например, с помощью
getch()). Вычислить наименьшую и наибольшую цифры в записи
числа.*/

void StackLoop()
{
	int userChoice = 0;
	double tmp = 0;
	int max, min;
	bool loop = true;
	stack array = { NULL, 0, 0 };

	do {
		printf_s("Enter stack size: ");
		scanf_s("%d", &array.length);
		if (InitStack(&array))
			break;
		printf_s("Invalid value or can't malloc memory!\n");
	} while (true);
	
	printf_s("1 - Add new element \n2 - Get with removing \n3 - Get without removing \n4 - Clear \n5 - Task \n6 - Exit \n");

	while (loop)
	{
		printf_s("Your choice: ");
		scanf_s("%d", &userChoice);

		switch (userChoice)
		{
		case 1:
			printf_s("Enter your element: ");
			scanf_s("%lf", &tmp);
			if(!PushStack(&array, tmp))
				printf_s("Your stack is full!\n");
			break;

		case 2:
			if ((tmp = PopStack(&array)) != LONG_MAX)
				printf_s("Your element: %lf\n", tmp);
			else
				printf_s("Your stack is empty.\n");
			break;

		case 3:
			if ((tmp = PeekStack(&array)) != LONG_MAX)
				printf_s("Your element: %lf\n", tmp);
			else
				printf_s("Your stack is empty.\n");
			break;

		case 4:
			ClearStack(&array);
			break;

		case 5:
			max = -1, min = 10;
			while (getchar() != '\n');
			printf_s("Enter your number: ");
			while ((tmp = getchar()) != '\n')
			{
				tmp -= '0';
				PushStack(&array, tmp);
				if (tmp > max)
					max = tmp;
				if (tmp < min)
					min = tmp;
			}
			if(max != -1)
				printf_s("max = %d\t min = %d\n", max, min);
			PrintStackInReverseOrder(&array);
			break;

		case 6:
			loop = 0;
			break;

		default:

			break;
		}

		PrintStack(&array);
	}

	DestroyStack(&array);
}


int main()
{
	StackLoop();

	return 0;
}