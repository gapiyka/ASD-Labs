// ASD LAB 1-6 Not correct version
//#include <stdio.h> // default
//#include <windows.h> // library for sleep
//#include <iostream> // std library
//
//
//void print(int A[][120], int N, int M)
//{
//	for (int R = 0; R < N; R++) {
//		for (int C = 0; C < M; C++)
//			std::cout << A[R][C];
//		std::cout << std::endl;
//	}
//}
//
//
//int main()
//{
//    const int lines = 30; // i think my screen extension change default console size 
//    const int columns = 120; // using 120 cuz in one field contains 120(not 80) symbols
//    int A[lines][columns];
//
//    int linStart = lines / 2;
//    int colStart = columns * 2 / 3;
//    bool IsLeft = true;
//    bool isDown = true;
//
//    for (int i = 0;i < lines;i++)
//    {
//        for (int j = 0; j < columns;j++)
//        {
//            A[i][j] = 0;
//        }
//    }
//
//    print(A, lines, columns);
//
//    int y = linStart;
//    int x = colStart;
//    int difx = 0;
//    int dify = 0;
//    for (int time = 0; time < 10; time++)
//    {
//        if (IsLeft)
//        {
//            for (int xk = x + difx; xk > ((x / 2) - difx); xk--)
//            {
//                A[y - 1 - dify][xk - 1] = 5;
//                if (xk - 1 == (x / 2) - difx)
//                {
//                    print(A, lines, columns);
//                    Sleep(2000);
//                    for (int yk = y - dify; yk < y + dify + 3; yk++)
//                    {
//                        A[yk - 1][xk - 1] = 5;
//                    }
//                    print(A, lines, columns);
//                    Sleep(2000);
//                }
//            }
//            IsLeft = false;
//            dify += 3;
//        }
//        else {
//            for (int xk = (x / 2) - difx; xk < x + 8 + difx; xk++)
//            {
//                A[y - 1 + dify][xk] = 5;
//                if (xk + 1 == x + 8 + difx)
//                {
//                    print(A, lines, columns);
//                    Sleep(2000);
//                    if (time != 9)
//                    {
//                        for (int yk = y + dify - 1; yk > y - 1 - dify; yk--)
//                        {
//                            A[yk][xk] = 5;
//                        }
//                        print(A, lines, columns);
//                        Sleep(2000);
//                    }
//                }
//            }
//            IsLeft = true;
//            difx += 8;
//        }
//    }
//
//
//
//    return 1;
//}










// LAB 2-1
//BinarySearchLastPosition(A[0, N - 1], value) {
//    low = -1
//        high = N
//        while (high - low > 1) {
//            mid = (high + low) / 2
//                if (A[mid] <= value)
//                    low = mid
//                else
//                    high = mid
//        }
//    return low
//}

	/*float T;
	int i, j, L, R;
	for (int i = 1; i < n; i++)
	{
		T = B[i];
		L = 1;
		R = i;

		while (L < R)
		{
			j = (L + R) / 2;
			if (B[j] <= T)
			{
				L = j + 1;
			}
			else
			{
				R = j;
			}

			for (int k = i - 1; k > R; --k)
			{
				B[k + 1] = B[k];
			}
			B[R] = T;
		}
	}*/

	/*for (int i = 0; i < n; i++)
	{
		printf_s("%d", B[i]);
	}

	printf_s("\nHello");


	int average_index = 0,
		first_index = 0,
		last_index = n - 1,
	search_value = 4;
	if (last_index == -1) cout << "\narray is empty" << endl;

	while (first_index < last_index)
	{
		average_index = first_index + (last_index - first_index) / 2;
		search_value <= B[average_index] ? last_index = average_index : first_index = average_index + 1;
	}

	if (B[last_index] == search_value)
		cout << "\nvalue is found" << "\nindex = " << last_index << endl;
	else
		cout << "\nvalue is not found" << endl;*/


		/*
		int BinarySearchLastPosition(int C[n], int value)
		{
			int low = -1;
			int high = 11;
			int mid;
			while (high - low > 1) {
				mid = (high + low) / 2;
				if (C[mid] <= value)
					low = mid;
				else
					high = mid;
			}

			return low;
		}
		*/




// LAB 2-2

//void insertionSort(int arr[], int length)
//{
//	int temp, item;
//	for (int counter = 1; counter < length; counter++)
//	{
//		temp = arr[counter];
//		item = counter - 1;
//		while (item >= 0 && arr[item] < temp)
//		{
//			arr[item + 1] = arr[item];
//			arr[item] = temp;
//			item--;
//		}
//	}
//}

//void sort_array(int A[], int n)
//{
//	int x, low, high, mid;
//	for (short i = 1; i < n; i++)
//	{
//		if (A[i] < A[i - 1]) {
//			x = A[i];
//			low = 0;
//			high = i - 1;
//			do {
//				mid = (low + high) / 2;
//				if (A[mid] < x)
//					low = mid + 1;
//				else
//					high = mid - 1;
//			} while (low <= high);
//			for (short j = i - 1; j >= low; j--)
//				A[j + 1] = A[j];
//			A[low] = x;
//		}
//	}
//}


// CO_STILLEd cod:
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <windows.h>
//
//#define START1_I 11
//#define START1_J 80
//#define END1_I 0
//#define END1_J 80
//
//#define START2_I 12
//#define START2_J -1
//#define END2_I 23
//#define END2_J 0
//
//int mtx[24][80] = { 0 };
//int cur_i1, cur_j1, cur_i2, cur_j2, cur_direction1, cur_direction2, i, j;
//
//
//void gotoxy(int x, int y) {
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//void printMtx(int i, int j) {
//	gotoxy(j, i);
//	putchar('X');
//}
//
//int main() {
//	int cur_i1 = START1_I;
//	int cur_j1 = START1_J;
//	int cur_i2 = START2_I;
//	int cur_j2 = START2_J;
//	while ((cur_i1 != END1_I  cur_j1 != END1_J) && (cur_i2 != END2_I  cur_j2 != END2_J)) {
//		if (cur_i1 % 2 != 0) { // first half
//			if (cur_j1 != 0) {
//				cur_j1--;
//				printMtx(cur_i1, cur_j1);
//				cur_j2++;
//				printMtx(cur_i2, cur_j2);
//			}
//			else {
//				cur_i1--;
//				printMtx(cur_i1, cur_j1);
//				cur_i2++;
//				printMtx(cur_i2, cur_j2);
//			}
//		}
//		else {
//			if (cur_j1 != 79) {
//				cur_j1++;
//				printMtx(cur_i1, cur_j1);
//				cur_j2--;
//				printMtx(cur_i2, cur_j2);
//			}
//			else {
//				cur_i1--;
//				printMtx(cur_i1, cur_j1);
//				cur_i2++;
//				printMtx(cur_i2, cur_j2);
//			}
//
//		}
//		Sleep(7);
//	}
//	getchar();
//	return 0;
//}


// BI-Search ALOGORYTHM (2-1) for finding first number;
//#include <stdio.h>
//#include <iostream>
//
//const int n = 10;
//int A[n][n] = { { 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//				{ 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 },
//				{ 0, 0, 4, 0, 0, 0, 0, 0, 0, 0 },
//				{ 0, 0, 0, 3, 0, 0, 0, 0, 0, 0 },
//				{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
//				{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
//				{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
//				{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
//				{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
//				{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
//
//void BiSearch(int answer)
//{
//	int low = 0;
//	int high = n - 1;
//	while (low < high)
//	{
//		int mid = (high + low) / 2;
//		if (answer == A[mid][mid])
//		{
//			printf_s("This number located at index:( %d , %d )\n", mid, mid);
//			high = mid;
//		}
//		else if (answer < A[mid][mid])
//			low = mid + 1;
//		else if (answer > A[mid][mid])
//			high = mid - 1;
//		}
//}
//
//void print(int A[][10], int N, int M)
//{
//	for (int R = 0; R < N; R++) {
//		for (int C = 0; C < M; C++)
//			std::cout << A[R][C];
//		std::cout << std::endl;
//	}
//}
//
//int main()
//{
//	print(A, n, n);
//	int answer;
//	printf("Please input number\n");
//	scanf_s("%d", &answer);
//	if (answer < 1 || answer > 6)
//	{
//		printf("Sorry but your number doesnt exist in array\n");
//		return 0;
//	}
//	else
//	{
//		BiSearch(answer);
//		return 1;
//	}
//}
