#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Stack.h"


void InitStack(mainStack* stack, double number)
{
	stack->array = (double*)malloc(sizeof(double));
	stack->elementsCount++;
	stack->top = &stack->array[stack->elementsCount - 1];
	stack->array[stack->elementsCount - 1] = number;
}

void PrintStack(mainStack* stack)
{
	if (stack->elementsCount <= 0)
	{
		printf_s("Your stack is empty\n");
		return;
	}

	for (int i = stack->elementsCount - 1; i >= 0; i--)
		printf_s("%.2lf ", stack->array[i]);
	printf_s("\n");
}

void DestroyStack(mainStack* stack)
{
	if (stack->array)
		free(stack->array);
}

void PushToStack(mainStack* stack, double number)
{
	if (stack->elementsCount == NULL)
	{
		InitStack(stack, number);
		if (!stack->array)
		{
			printf_s("Can't allocate memory.\n");
			system("pause");
			exit(1);
		}
		return;
	}

	stack->elementsCount++;
	if (!(stack->array = (double*)realloc(stack->array, sizeof(double) * stack->elementsCount)))
	{
		printf_s("Can't allocate memory.\n");
		stack->elementsCount--;
		return;
	}

	stack->array[stack->elementsCount - 1] = number;
	stack->top = &stack->array[stack->elementsCount - 1];
}

double PopStack(mainStack* stack)
{
	double tmp = LONG_MAX;

	if (stack->elementsCount > 1)
	{
		tmp = *stack->top;
		stack->elementsCount--;
		stack->top = &stack->array[stack->elementsCount - 1];
		return tmp;
	}

	else if (stack->elementsCount == 1)
	{
		tmp = *stack->top;
		stack->elementsCount--;
		stack->top = NULL;
		free(stack->array);
		stack->array = NULL;
		return tmp;
	}

	return tmp;
}

double PeekStack(mainStack* stack)
{
	if (stack->elementsCount > 0)
		return *stack->top;

	return LONG_MAX;
}

void ClearStack(mainStack* stack)
{
	stack->elementsCount = NULL;
	stack->top = NULL;
	if (stack->array != NULL)
		free(stack->array);
	stack->array = NULL;
}