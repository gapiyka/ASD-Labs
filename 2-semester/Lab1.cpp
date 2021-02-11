#include <stdio.h>
#define x 0.1



//TASK 1
void RecurseSum(int length, float* prevF, float* sum, int i) {
	if (length + 1 != i) {
		i++;
		*sum += *prevF;
		*prevF = -(*prevF) * x * (3 * i - 5) / (3 * i - 3);
		RecurseSum(length, prevF, sum, i);
	}
}
int main()
{
	float F = 1;
	int input;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &input);
	RecurseSum(input, &F, &sum, 1);
	printf_s("Sum of range equal: ( %f )\n", sum);
}


//TASK 2
float RecurseSum(float prevF, float* sum, int* i) {
	if (*i > 1) {
		*i -= 1;
		prevF = RecurseSum(prevF, sum, i);
	}
	*i += 1;
	*sum += prevF;
	prevF = -prevF * x * (3 * (*i) - 5) / (3 * (*i) - 3);
	return prevF;
}
int main()
{
	float F = 1;
	int i;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &i);
	F = RecurseSum(F, &sum, &i);
	printf_s("Sum of range equal: ( %f )\n", sum);
}


//TASK 3
float RecurseSum(int length, float prevF, float* sum, int i) {
	float tempF = prevF;
	if (length > i) {
		i++;
		prevF = -(prevF)* x * (3 * i - 5) / (3 * i - 3);
		prevF =  RecurseSum(length, prevF, sum, i);
	}
	*sum += tempF;
	return prevF;
}
int main()
{
	float F = 1;
	int input;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &input);
	F = RecurseSum(input, F, &sum, 1);
	printf_s("Sum of range equal: ( %f )\n", sum);
}


//FOR-CHECK
int main()
{
	float sum = 1;
	float F = 1;
	int input;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &input);
	for (int i = 2; i <= input; i++) {
		F = -F * 0.1 * (3 * i - 5) / (3 * i - 3);
		sum += F;
	}
	printf_s("Sum of range equal: ( %f )\n", sum);
}