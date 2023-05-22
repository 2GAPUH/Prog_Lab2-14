#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Stack.h"

bool InitStack(stack* s)
{
	if (s->length <= 2)
		return 0;
	s->arr = (double*)malloc(sizeof(double) * s->length);
	if (s->arr == NULL)
		return 0;
	
	s->top = -1;
	return 1;
}

bool PushStack(stack* s, double v)
{
	if (s->top + 1 >= s->length)
		return 0;
	s->arr[++s->top] = v;
	return 1;
}

double PopStack(stack* s)
{
	if (s->top < 0)
		return LONG_MAX;
	return s->arr[s->top--];
}

double PeekStack(stack* const s)
{
	if (s->top < 0)
		return LONG_MAX;
	return s->arr[s->top];
}

bool IsEmptyStack(stack* const s)
{
	return s->top == -1;
}

void ClearStack(stack* s)
{
	s->top = -1;
}

void PrintStack(stack* const s)
{
	if (s->length < 1)
		return;

	for (int i = 0; i <= s->top; i++)
		printf_s("%0.2lf\t", s->arr[i]);
	printf_s("\n");
}

void PrintStackInReverseOrder(stack* s)
{
	if (s->length < 1)
		return;

	for (int i = s->top; i >= 0; i--)
		printf_s("%0.0lf\t", s->arr[i]);
	printf_s("\n");
}

void DestroyStack(stack* s)
{
	s->length = -1;
	s->top = -1;
	free(s->arr);
}