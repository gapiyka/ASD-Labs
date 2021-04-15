#include<windows.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
#define N 10

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

wchar_t  ProgName[] = L"Лабораторна робота 3";

struct queue {
    int array[N];
    int front;
    int last;
};

struct queue* init() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->last = -1;
    return q;
}

int isEmpty(struct queue* q) {
    if (q->last == -1)
        return 1;
    else
        return 0;
}

void pushQueue(struct queue* q, int value) {
    if (q->front == -1)
        q->front = 0;
    q->last++;
    q->array[q->last] = value;
}

int popQueue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        item = -1;
    }
    else {
        item = q->array[q->front];
        q->front++;
        if (q->front > q->last) q->front = q->last = -1;
    }
    return item;
}

struct stack {
    int array[N];
    int top;
};

struct stack* initStack() {
    struct stack* stack = malloc(sizeof(struct stack));
    stack->top = 0;
    return stack;
}

void pushStack(struct stack* stack, int value) {
    if (stack->top < N) {
        stack->array[stack->top] = value;
        stack->top++;
    }
}


void flush(struct stack* stack) {
    stack->top--;
}

int top(struct stack* stack) {
    if (stack->top > 0)
        return stack->array[stack->top - 1];
    else return -1;
}

int isEmptyStack(struct stack* stack) {
    if (stack->top == 0)
        return 1;
    else
        return 0;
}

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
        800,
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

void drawEdge(HDC hdc, int B[N][N], int xPos[N], int yPos[N], int start, int end) {
    int xDif = xPos[start] - xPos[end];
    int yDif = yPos[start] - yPos[end];
    if (B[start][end] == 1) {
        if (start == end) {//LOOP check
            MoveToEx(hdc, xPos[end], yPos[end], NULL);
            LineTo(hdc, xPos[end] + 40, yPos[end] + 10);
            LineTo(hdc, xPos[end] + 40, yPos[end] + 40);
            LineTo(hdc, xPos[end] + 10, yPos[end] + 40);
            LineTo(hdc, xPos[end], yPos[end]);
        }
        else {
            MoveToEx(hdc, xPos[start], yPos[start], NULL);
            if (yDif == 0 && abs(xDif) > 300 && end <= 3) {//check on horizntal obstacle
                LineTo(hdc, xPos[end] + xDif / 2, yPos[end] - 35);
                LineTo(hdc, xPos[end], yPos[end]);
            }
            else if (abs(xDif) == 300 && abs(yDif) == 300 && (start == 0 || start == 3)) {//check on diagonal obstacle
                LineTo(hdc, xPos[end] + xDif / 2, yPos[end]);
                LineTo(hdc, xPos[end], yPos[end]);
            }
            else if (abs(xDif) == 300 && abs(yDif) == 300 && ((start == 6 && end == 0) || (start == 7 && end == 3))) {//check on diagonal obstacle
                LineTo(hdc, xPos[end] + xDif / 2, yPos[start]);
                LineTo(hdc, xPos[end], yPos[end]);
            }
            else if (abs(xDif) == 300 && abs(yDif) == 300 && ((start == 6 && end != 2) || (start == 7 && end != 1))) {//check on diagonal obstacle
            }
            else {
                LineTo(hdc, xPos[end], yPos[end]);
            }
        }
    }
}

void drawVertex(HDC hdc, int xPos[N], int yPos[N], char* ellipseName[N], int i) {
    int dtx = 5, radius = 16;
    Ellipse(hdc, xPos[i] - radius, yPos[i] - radius, xPos[i] + radius, yPos[i] + radius);
    TextOut(hdc, xPos[i] - dtx, yPos[i] - 8, ellipseName[i], 1);
}

void printMatrix(HDC hdc, int A[N][N]) {
    char text[11];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sprintf_s(text, 2, "%d", A[i][j]);
            TextOutA(hdc, 5 + 25 * j, 400 + 20 * i, text, 1);
        }
    }
}

//MATRIX SIMETRICAL
void simMatrix(int A[N][N], int* B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 1) {
                B[j][i] = 1;
                B[i][j] = 1;
            }
        }
    }
}

//GENERATE MATRIX
void mulmr(int* matrix[N][N], float k) {
    int element;
    float num;
    srand(0504);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = (rand() / (float)RAND_MAX * 2) * k;
            if (num < 1) element = 0;
            else element = 1;
            matrix[i][j] = element;
        }
    }
}

void BFS(HDC hdc, int xPos[N], int yPos[N], char* ellipseName[N], int A[N][N], int start) {//breadth
    struct queue* q = init();
    int visited[N] = { 0,0,0,0,0,0,0,0,0,0 };
    int distance[N][N] = {
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 }
    };
    int treeMatrix[N][N] = {
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0 }
    };
    int k = 1, a = 0, dist = 0, curVertex, counter = 0;
    char text[4];
    pushQueue(q, start);
    visited[start] = 1;
    distance[dist][start] = 1;
    drawVertex(hdc, xPos, yPos, ellipseName, start);
    sprintf_s(text, 2, "%d", a);
    TextOutA(hdc, xPos[start] - 20, yPos[start] + 15, text, 1);
    while (!isEmpty(q)) {
        curVertex = popQueue(q);
        for (int i = 0; i < N; i++) {
            if (A[curVertex][i] && visited[i] == 0) {
                k++;
                visited[i] = k;
                pushQueue(q, i);
                drawEdge(hdc, A, xPos, yPos, curVertex, i);
                drawVertex(hdc, xPos, yPos, ellipseName, i);
                system("pause");
                system("cls");
                dist = a + 1;
                distance[dist][i] = 1;
                treeMatrix[curVertex][i] = 1;
                sprintf_s(text, 2, "%d", dist);
                TextOutA(hdc, xPos[i] - 20, yPos[i] + 15, text, 1);
            }
        }
        a++;
    }

    for (int i = 0;i < N; i++) {
        drawVertex(hdc, xPos, yPos, ellipseName, i);
        counter = 0;
        for (int j = 0;j < N; j++) {
            if (distance[i][j]) {
                sprintf_s(text, 3, "L%d", i);
                TextOutA(hdc, 10, 550 + 25 * i, text, 2);
                sprintf_s(text, 2, "%d", j);
                TextOutA(hdc, 30 + 20 * counter, 550 + 25 * i, text, 1);
                counter++;
            }
            sprintf_s(text, 2, "%d", treeMatrix[i][j]);
            TextOutA(hdc, 10 + 10 * j, 200 + 20 * i, text, 1);
        }
    }
}

void DFS(HDC hdc, int xPos[N], int yPos[N], char* ellipseName[N], int A[N][N], int start) {//depth
    int distance[N][N] = {
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 }
    };
    int treeMatrix[N][N] = {
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0 }
    };
    struct stack* s = initStack();
    int visited[N] = { 0,0,0,0,0,0,0,0,0,0 };
    int k = 1, dist = 0, curVertex, counter = 0, checker = 1;
    char text[4];
    pushStack(s, start);
    visited[start] = 1;
    distance[dist][start] = 1;
    drawVertex(hdc, xPos, yPos, ellipseName, start);
    sprintf_s(text, 2, "%d", dist);
    TextOutA(hdc, xPos[start] - 20, yPos[start] + 15, text, 1);
    while (!isEmptyStack(s)) {
        curVertex = top(s);
        for (int i = 0; i < N; i++) {
            if (A[curVertex][i]) {
                if (visited[i] == 0) {
                    k++;
                    dist++;
                    visited[i] = k;
                    distance[dist][i] = 1;
                    treeMatrix[curVertex][i] = 1;
                    pushStack(s, i);
                    drawEdge(hdc, A, xPos, yPos, curVertex, i);
                    drawVertex(hdc, xPos, yPos, ellipseName, i);
                    sprintf_s(text, 2, "%d", dist);
                    TextOutA(hdc, xPos[i] - 20, yPos[i] + 15, text, 1);
                    system("pause");
                    system("cls");
                    break;
                }
            }
            if (i == N - 1) {
                flush(s);
                dist--;
            }
        }
    }
    for (int i = 0;i < N; i++) {
        drawVertex(hdc, xPos, yPos, ellipseName, i);
        counter = 0;
        for (int j = 0;j < N; j++) {
            if (distance[i][j]) {
                sprintf_s(text, 3, "L%d", i);
                TextOutA(hdc, 10, 450 + 25 * i, text, 2);
                sprintf_s(text, 2, "%d", j);
                TextOutA(hdc, 30 + 20 * counter, 450 + 25 * i, text, 1);
                counter++;
            }
            sprintf_s(text, 2, "%d", treeMatrix[i][j]);
            TextOutA(hdc, 10 + 10 * j, 200 + 20 * i, text, 1);
        }
    }

    for (int i = 0;i < N; i++) {
        drawVertex(hdc, xPos, yPos, ellipseName, i);
    }
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;

    switch (messg) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        int A[N][N];
        int B[N][N] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
        };
        int visited[N] = { 0,0,0,0,0,0,0,0,0,0 };
        char* ellipseName[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
        int xPos[10];
        int yPos[10];
        int startX = 100, divine = -1;
        HPEN BluePen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));
        HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(250, 0, 0));

        SelectObject(hdc, BlackPen);


        mulmr(A, (1.0 - 0 * 0.01 - 4 * 0.005 - 0.15));
        simMatrix(A, B);
        //printMatrix(hdc, B);

        //vertex coords
        for (int vertex = 0; vertex < N; vertex++) {
            if (vertex < 4) {
                xPos[vertex] = startX + vertex * 300;
                yPos[vertex] = 50;
            }
            else if (vertex < 6) {
                startX = 550;
                xPos[vertex] = startX + divine * 300;
                yPos[vertex] = 200;
            }
            else if (vertex < 8) {
                xPos[vertex] = startX + divine * 150;
                yPos[vertex] = 350;
            }
            else {
                xPos[vertex] = startX + divine * 75;
                yPos[vertex] = 500;
            }
            divine = -divine;
        }
        //draw graph edges
        for (int start = 0; start < N;start++) {
            for (int end = start; end < N;end++) {
                drawEdge(hdc, B, xPos, yPos, start, end);
            }
        }
        //draw vertex
        SelectObject(hdc, BluePen);
        for (int i = 0;i < N;i++) {
            drawVertex(hdc, xPos, yPos, ellipseName, i);
        }

        //breadth + depth
        SelectObject(hdc, RedPen);
        //BFS(hdc, xPos, yPos, ellipseName, B, 0);

        DFS(hdc, xPos, yPos, ellipseName, B, 7);

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