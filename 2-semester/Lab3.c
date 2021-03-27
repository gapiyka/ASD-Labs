#include<windows.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#define N 10

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

wchar_t  ProgName[] = L"Лабораторна робота 3";
int A[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 1, 0}
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASS w;

    w.lpszClassName = ProgName;
    w.hInstance = hInstance;
    w.lpfnWndProc = WndProc;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hIcon = 0;
    w.lpszMenuName = 0;
    w.hbrBackground = LTGRAY_BRUSH;
    w.style = CS_HREDRAW | CS_VREDRAW; 
    w.cbClsExtra = 0;
    w.cbWndExtra = 0;

    if (!RegisterClass(&w))
        return 0;

    hWnd = CreateWindow(ProgName,
        L"LAB 3. Powered by Gapiy D.E.",
        WS_OVERLAPPEDWINDOW,
        100,
        100,
        800,
        600,
        (HWND)NULL,
        (HMENU)NULL,
        (HINSTANCE)hInstance,
        (HINSTANCE)NULL);

    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&lpMsg, hWnd, 0, 0)) {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return(lpMsg.wParam);
}

void arrow(float fi, int px, int py, HDC hdc) {
    fi = 3.1416 * (180.0 - fi) / 180.0;
    int lx, ly, rx, ry;
    lx = px + 15 * cos(fi + 0.3);
    rx = px + 15 * cos(fi - 0.3);
    ly = py + 15 * sin(fi + 0.3);
    ry = py + 15 * sin(fi - 0.3);
    MoveToEx(hdc, lx, ly, NULL);
    LineTo(hdc, px, py);
    LineTo(hdc, rx, ry);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (messg) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        char* ellipseName[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        int xPos[10] = { 100,300,500,700,200,400,600,300,500,400 };
        int yPos[10] = { 50,50,50,50,200,200,200,350,350,500 };
        int dtx = 5, radius = 16, dx, dy, xDif, yDif;
        float koef;
        HPEN BluePen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));

        SelectObject(hdc, BlackPen);

        for (int start = 0; start < N;start++) {
            for (int end = 0; end < N;end++) {
                if (A[start][end] == 1) {
                    MoveToEx(hdc, xPos[start], yPos[start], NULL);
                    dx = 16, dy = 16;
                    xDif = xPos[start] - xPos[end];
                    yDif = yPos[start] - yPos[end];
                    koef = sqrt(xDif * xDif + yDif * yDif) / radius;
                    if (yDif == 0 && abs(xDif) > 200) {
                        LineTo(hdc, xPos[end] + xDif/2, yPos[end] - 35);
                        MoveToEx(hdc, xPos[end] + xDif / 2, yPos[end] -35, NULL);
                    }
                    else if ((abs(xDif) == 200 && abs(yDif) == 300) || (abs(xDif) == 300 && abs(yDif) == 450)) {
                        LineTo(hdc, xPos[end] + xDif / 3, yPos[end] + yDif / 2);
                        MoveToEx(hdc, xPos[end] + xDif / 3, yPos[end] + yDif / 2, NULL);
                    }
                    LineTo(hdc, xPos[end], yPos[end]);
                    dx = xDif / koef;
                    dy = yDif / koef;
                    //arrow(atan(xDif/yDif), xPos[end] + dx, yPos[end] + dy, hdc);
                }
            }
        }
        SelectObject(hdc, BluePen);
        for (int i = 0;i < N;i++) {
            Ellipse(hdc, xPos[i] - radius, yPos[i] - radius, xPos[i] + radius, yPos[i] + radius);
            TextOut(hdc, xPos[i] - dtx, yPos[i] - dy / 2, ellipseName[i], 1);
        }
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0); 
        break;

    default:
        return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return 0;
}



//MATRIX GENERATION
/*int** randmatrix(float k) {
    srand(0504);
    int matrix[N][N];
    float num;
    int element;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = (rand() / (float)RAND_MAX * 2) * k;
            if (num < 1) element = 0;
            else element = 1;
            matrix[i][j] = element;
            printf("%d ", element);
        }
        printf("\n");
    }
    return matrix;
}

int main() {
    int** A = randmatrix(1.0 - 0 * 0.02 - 4 * 0.005 - 0.25);
    return 0;
}*/