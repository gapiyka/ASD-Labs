#include <stdio.h>
#include <iostream>

const int n = 10;
int A[n][n] = { { 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };

int BiSearch(int answer)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (answer == A[mid][mid])
		{
			printf_s("This number located at index:( %d , %d )", mid, mid);
			return 1;
		}
		else if (answer < A[mid][mid])
			low = mid + 1;
		else if (answer > A[mid][mid])
			high = mid - 1;
		else
			return 0;
	}
}

void print(int A[][10], int N, int M)
{
	for (int R = 0; R < N; R++) {
		for (int C = 0; C < M; C++)
			std::cout << A[R][C];
		std::cout << std::endl;
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
		return BiSearch(answer);
	}
}
