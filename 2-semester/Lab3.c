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
        1200,
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

void arrow(int px, int py, int dx, int dy, HDC hdc) {
    int lx, ly=py, rx=px, ry;
    if (dx == 0) return;
    else lx = px + (dx / abs(dx)) * 15;
    if (dy == 0) {
        ly = py - 15;
        ry = py + 15;
        lx = px + (15 * dx / abs(dx));
        rx = lx;
    }
    else ry = py + (dy / abs(dy)) * 15;
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
        int xPos[10];
        int yPos[10];
        int dtx = 5, radius = 16, startX = 100, divine = 1, divine2 = -1, dx, dy, xDif, yDif;
        float koef;
        int OrientGraph = 0;// 1 - Oriented Graph | 0- Not oriented
        HPEN BluePen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));

        SelectObject(hdc, BlackPen);
        //vertex coords
        for (int vertex = 0; vertex < N; vertex++) {

            if(vertex < 4){
                xPos[vertex] = startX + vertex * 300;
                yPos[vertex] = 50;
            }
            else if (vertex < 6) {
                startX = 550;
                xPos[vertex] = startX + divine2 * 300;
                yPos[vertex] = 200;
                divine2 = -divine2;
            }
            else if (vertex < 8) {
                xPos[vertex] = startX + divine2 * 150;
                yPos[vertex] = 350;
                divine2 = -divine2;
            }
            else{
                xPos[vertex] = startX + divine2 * 75;
                yPos[vertex] = 500;
                divine2 = -divine2;
            }
        }
        //draw graph
        for (int start = 0; start < N;start++) {
            for (int end = 0; end < N;end++) {
                if (A[start][end] == 1) {
                    xDif = xPos[start] - xPos[end];
                    yDif = yPos[start] - yPos[end];
                    koef = sqrt(xDif * xDif + yDif * yDif) / radius;
                    dx = xDif / koef;
                    dy = yDif / koef;
                    if (start == end) {
                        MoveToEx(hdc, xPos[end], yPos[end], NULL);
                        LineTo(hdc, xPos[end] + 40, yPos[end] + 10);
                        LineTo(hdc, xPos[end] + 40, yPos[end] + 40);
                        LineTo(hdc, xPos[end] + 10, yPos[end] + 40);
                        LineTo(hdc, xPos[end], yPos[end]);
                        if(OrientGraph)arrow(xPos[end] + 2, yPos[end] + 13, 2, 13, hdc);
                    }
                    else if (A[start][end] == 1 && A[end][start] == 1) {
                        MoveToEx(hdc, xPos[start], yPos[start], NULL);
                        LineTo(hdc, xPos[end] + xDif / 2 + (20*divine), yPos[end] + yDif/2 + (20 * divine));
                        LineTo(hdc, xPos[end], yPos[end]);
                        if (OrientGraph)arrow(xPos[end] + dx, yPos[end] + dy, dx, dy, hdc);
                        divine = -divine;
                    }
                    else {
                        MoveToEx(hdc, xPos[start], yPos[start], NULL);
                        if (yDif == 0 && abs(xDif) > 300 && end <= 3) {
                            LineTo(hdc, xPos[end] + xDif / 2, yPos[end] - 35);
                            dx = xDif / 2 / koef;
                            dy = (yDif-35) / koef;
                        }
                        else if (abs(xDif) == 300 && abs(yDif) == 300 && (end == 0 || end == 3)) {
                            LineTo(hdc, xPos[end] + xDif / 2, yPos[end] + yDif / 1);
                            dx = xDif / 2 / koef;
                            dy = yDif / koef;
                        }
                        LineTo(hdc, xPos[end], yPos[end]);
                        if (OrientGraph)arrow(xPos[end] + dx, yPos[end] + dy, dx, dy, hdc);
                    }
                }
            }
        }
        SelectObject(hdc, BluePen);
        for (int i = 0;i < N;i++) {
            Ellipse(hdc, xPos[i] - radius, yPos[i] - radius, xPos[i] + radius, yPos[i] + radius);
            TextOut(hdc, xPos[i] - dtx, yPos[i] - 8, ellipseName[i], 1);
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