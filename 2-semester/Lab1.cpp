#include <stdio.h>
#define x 0.1



//TASK 1
float RecurseSum(int length, float prevF, float sum, int i) {
	i++;
	sum += prevF;
	prevF = -prevF * x * (3 * i - 5) / (3 * i - 3);
	if (length + 1 != i) {
		sum = RecurseSum(length, prevF, sum, i);
	}
	return sum;
}
int main()
{
	float F = 1;
	int input;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &input);
	sum = RecurseSum(input, F, sum, 1);
	printf_s("Sum of range equal: ( %f )\n", sum);
}


//TASK 2
float RecurseSum(float prevF, float* sum, int i) {
	if (i > 1) {
		prevF = RecurseSum(prevF, sum, i - 1);
		prevF = -(prevF)*x * (3 * i - 5) / (3 * i - 3);
		*sum += prevF;
	}
	else *sum = prevF;

	return prevF;
}
int main()
{
	float F = 1;
	int i = 1;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &i);
	F = RecurseSum(F, &sum, i);
	printf_s("Sum of range equal: ( %f )\n", sum);
}


//TASK 3
float RecurseSum(int length, float prevF, float sum, int i) {
	float tempF = prevF;
	if (length > i) {
		i++;
		prevF = -(prevF)* x * (3 * i - 5) / (3 * i - 3);
		sum =  RecurseSum(length, prevF, sum, i);
	}
	sum += tempF;
	return sum;
}
int main()
{
	float F = 1;
	int input;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &input);
	sum = RecurseSum(input, F, sum, 1);
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