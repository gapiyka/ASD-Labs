#include <stdio.h>  //default library
#include <windows.h> //library for gotoxy and sleep
#include <iostream> // library for cout (std)

int A[24][80] = { 0 }; // supposed size of multidimensional array 
int yStart = 11; // index of middle line
int xStart = 67; // index of start column pos = 80 - 12; index = pos - 1
int length = 57; // 80 - 12 -12

 void print(int A[][80], int N, int M) // print array on screen
{
	for (int R = 0; R < N; R++) {
		for (int C = 0; C < M; C++)
			std::cout << A[R][C];
		std::cout << std::endl;
	}
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // put cursor on x,y pos
}

void draw(int X, int Y) //draw symbol on (X,Y) position
{
	gotoxy(X, Y); // move cursor
	putchar('X'); // put the char
	A[Y][X] = 1; // filling element in array
	Sleep(10); // 10 milliseconds pause
}

int main()
{
	bool IsLeft = true;
	int xPos = xStart;
	int yPos = yStart;

// TEST SIDE
	print(A, 24, 80);
	printf_s("Here is an empty multidimensional array 24x80");
	Sleep(5000);
	system("cls");
// END

// MAIN BODY
	for (int times = 0; times < 24; times++)
	{
		if (IsLeft) // left+down move
		{
			for (int i = xPos; i > xPos - length - times;i--)
			{
				draw(i, yPos);
				if (i - 1 == xPos - length - times)
				{
					for (int j = yPos; j < yPos + times + 1; j++)
					{
						draw(i, j);
					}
				}
			}
			xPos = xPos - length - times + 1; // check here
			yPos = yPos + 1 + times;
			IsLeft = false;
		}
		else { // right+up move
			for (int i = xPos; i < xPos + length + times;i++)
			{
				draw(i, yPos);
				if (i + 1 == xPos + length + times)
				{
					for (int j = yPos; j > yPos - times - 1; j--)
					{
						draw(i, j);
					}
				}
			}
			xPos = xPos + length + times - 1;
			yPos = yPos - 1 - times;
			IsLeft = true;
		}
	}
// END

// FINAL TEST
	gotoxy(0, 25);
	print(A, 24, 80);
	printf_s("Here is a filled multidimensional array");
// END
	
	return 1;
}
