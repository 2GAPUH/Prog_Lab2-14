#pragma once

struct stack
{
	double* arr = NULL;
	int length = -1;
	int top = -1;
};

bool InitStack(stack* s);
bool PushStack(stack* s, double v);
double PopStack(stack* s);
double PeekStack(stack* const s);
bool IsEmptyStack(stack* const s);
void ClearStack(stack* s);
void PrintStack(stack* const s);
void DestroyStack(stack* s);

void PrintStackInReverseOrder(stack* s);