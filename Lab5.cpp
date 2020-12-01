#include <stdio.h>

const int n = 10;
int A[n][n] = { { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 9, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 6, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 8, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 7, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 5, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 } };

void print(int A[][10], int N, int M)
{
	for (int R = 0; R < N; R++) {
		for (int C = 0; C < M; C++)
			printf_s("%d", A[R][C]);
		printf_s("\n");
	}
}

void sortWithBin(int A[][10], int n)
{
	int x, low, high, mid;
	for (int i = 1; i < n; i++)
	{
		if (A[i][i] > A[i - 1][i - 1]) {
			x = A[i][i]; 
			low = 0;
			high = i - 1; 
			do {
				mid = (low + high) / 2; 
				if (A[mid][mid] > x) 
					low = mid + 1; 
				else  
					high = mid - 1;
			} while (low <= high);
			for (int j = i - 1; j >= low; j--){
				A[j + 1][j + 1] = A[j][j];
			}
			A[low][low] = x;
		}
	}
}

int main(){
	print(A, n, n);
	sortWithBin(A, n);
	printf("\n");
	print(A, n, n);
	return 1;
}
