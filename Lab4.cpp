#include <stdio.h>

const int n = 10;
int A[n][n] = { { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 2, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 } };

void BiSearch(int answer)
{
	int low = 0;
	int high = n - 1;
	int coords;
	while (low < high)
	{
		int mid = (high + low) / 2;
		coords = mid;
		if (answer == A[mid][mid])
		{
			printf_s("This number located at index:( %d , %d )\n", mid, mid);
			high = mid;
		}
		else if (answer < A[mid][mid])
			low = mid + 1;
		else if (answer > A[mid][mid])
			high = mid - 1;
	}
	if (answer != A[coords][coords])
		printf_s("This number doesnt exist in matrix");
}

void print(int A[][10], int N, int M)
{
	for (int R = 0; R < N; R++) {
		for (int C = 0; C < M; C++)
			printf_s("%d", A[R][C]);
		printf_s("\n");
	}
}

int main()
{
	print(A, n, n);
	int answer;
	printf("Please input number\n");
	scanf_s("%d", &answer);
	if (answer < 1 || answer > 6)
	{
		printf("Sorry but your number doesnt exist in array\n");
		return 0;
	}
	else
	{
		BiSearch(answer);
		return 1;
	}
}
