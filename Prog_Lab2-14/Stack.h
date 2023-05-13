#pragma once

struct mainStack
{
	double* array;
	double* top;
	int elementsCount;
};

void InitStack(mainStack* stack, double number);
void PrintStack(mainStack* stack);
void DestroyStack(mainStack* stack);
void PushToStack(mainStack* stack, double number);
double PopStack(mainStack* stack);
double PeekStack(mainStack* stack);
void ClearStack(mainStack* stack);