#include <iostream>
#include "Windows.h"
#include <ctime>

using namespace std;
// ������� ��� ���������� ������ ������� ���������� ������� �� 1 �� 36
void fillMatrix1(int matrix[][6], int rows, int cols) {
    srand(time(NULL)); // �������������� ��������� ��������� �����

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1+ rand() % 37 ; // ���������� ��������� ����� �� 1 �� 36
        }
    }
}
// ������� ��� ���������� ������ ������� ���������� ������� �� 1 �� 36
void fillMatrix2(int matrix[][6], int rows, int cols) {
    srand(time(NULL)); // �������������� ��������� ��������� �����

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1 + rand() % 36; // ���������� ��������� ����� �� 1 �� 36
        }
    }
}

// ������� ��� ������ ������� �� �����
void printMatrix(int matrix[][6], int rows, int cols) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            destCoord.X = j * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(matrix + i) + j);
            Sleep(100);
        }
        cout << "\n\n";
    }
}


// ������� ��� ��������� ������ ������� �� ������
void subtractMatrix(int matrix2[][6], int matrix1[][6], int resultMatrix[][6], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
int choise;
const int size_arr = 6;

int randArr() {
    return (rand() % 36) + 1;
}
// ������� ��� ������ �� ������� �������
void printArr(int arr[][size_arr]) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < size_arr; i++) {
        for (int j = 0; j < size_arr; j++) {
            destCoord.X = j * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(arr + i) + j);
            Sleep(100);
        }
        cout << "\n";
    }
}
// ������� ��� ������ �������
void fillSnake(int arr[][size_arr]) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int top = 0, bottom = size_arr - 1, left = 0, right = size_arr - 1;
    while (left <= right && top <= bottom) {
        // ������ ����
        for (int i = top; i <= bottom; i++) {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr();
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
        // ����� �����
        for (int i = bottom; i >= top; i--) {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr();
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
    }
    destCoord.X = 0;
    destCoord.Y = size_arr * 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}
// ������� ��� ������ ��������
void fillSpiral(int arr[][size_arr]) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int num = 0;
    int top = 0, bottom = size_arr - 1, left = 0, right = size_arr - 1;
    while (left <= right && top <= bottom) {
        //������� ������
        for (int i = left; i <= right; i++) {
            destCoord.X = i * 4;
            destCoord.Y = top * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + top) + i) = randArr();
            cout << *(*(arr + top) + i);
            cout.flush();
            Sleep(100);
        }
        top++;
        //������ �������
        for (int i = top; i <= bottom; i++) {
            destCoord.X = right * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + right) = randArr();
            cout << *(*(arr + i) + right);
            cout.flush();
            Sleep(100);
        }
        right--;
        //������ ������
        for (int i = right; i >= left; (i--)) {
            destCoord.X = i * 4;
            destCoord.Y = bottom * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + bottom) + i) = randArr();
            cout << *(*(arr + bottom) + i);
            cout.flush();
            Sleep(100);
        }
        bottom--;
        //����� �������
        for (int i = bottom; i >= top; i--) {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr();
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
    }
    destCoord.X = 0;
    destCoord.Y = size_arr * 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void moveBlocs(int arr[][size_arr]) {
    cout << "�������� ������ �����\n " <<
        "1. �� ������� �������\n" <<
        "2. �� ���������\n" <<
        "3. ����/���\n" <<
        "4. �����/����\n";
       
    cin >> choise;
    // �� ������� �����
    if (choise == 1) {
        for (int i = 0; i < (size_arr / 2); i++) {
            for (int j = 0; j < size_arr; j++) {
                swap(*(*(arr + i + (size_arr / 2)) + j), *(*(arr + i) + j));
            }
        }
        for (int i = 0; i < (size_arr / 2); i++) {
            for (int j = 0; j < (size_arr / 2); j++) {
                swap(*(*(arr + i + (size_arr / 2)) + j + (size_arr / 2)), *(*(arr + i) + j));
            }
        }
    }
    // �� ��������� �����
    else if (choise == 2) {
        for (int i = 0; i < (size_arr / 2); i++) {
            for (int j = 0; j < size_arr; j++) {
                if (j < (size_arr / 2)) {
                    swap(*(*(arr + i) + j), *(*(arr + i + (size_arr / 2)) + j + (size_arr / 2)));
                }
                else {
                    swap(*(*(arr + i) + j), *(*(arr + i + (size_arr / 2)) + j - (size_arr / 2)));
                }
            }
        }
    }
    // ������� � ������ �����
    else if (choise == 3) {
        for (int i = 0; i < (size_arr / 2); i++) {
            for (int j = 0; j < size_arr; j++) {
                swap(*(*(arr + i) + j), *(*(arr + i + (size_arr / 2)) + j));
            }
        }
    }
    // ������ � ����� �����
    else if (choise == 4) {
        for (int i = 0; i < size_arr; i++) {
            for (int j = 0; j < (size_arr / 2); j++) {
                swap(*(*(arr + i) + j), *(*(arr + i) + j + (size_arr / 2)));
            }
        }
    }
    
}

void shakerSort(int* arr, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        for (int i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
        }
        left++;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
    }
}

void insert(int* ptr, int* end) {
    int size = end - ptr + 1;
    shakerSort(ptr, size);
}


void mathActions(int arr[][size_arr]) {
    char sign;
    int number;
    cout << "\n�������� ��������('+', '-', '*', '/') � ������� �����\n";
    cin >> sign >> number;

    if (sign == '+') {
        for (int i = 0; i < size_arr; i++) {
            for (int j = 0; j < size_arr; j++)
                *(*(arr + i) + j) += number;
        }
    }
    else if (sign == '-') {
        for (int i = 0; i < size_arr; i++) {
            for (int j = 0; j < size_arr; j++)
                *(*(arr + i) + j) -= number;
        }
    }
    else if (sign == '*') {
        for (int i = 0; i < size_arr; i++) {
            for (int j = 0; j < size_arr; j++)
                *(*(arr + i) + j) *= number;
        }
    }
    else if (sign == '/') {
        for (int i = 0; i < size_arr; i++) {
            for (int j = 0; j < size_arr; j++)
                *(*(arr + i) + j) /= number;
        }
    }
   
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[size_arr][size_arr];
    int* ptr = *arr, * end = *arr + size_arr * size_arr - 1;
    while (true) {
        cout << "�������� �������:\n" <<
            "1) ���������� ������� ��������/�������\n" <<
            "2) ����� ������ ������� �� �����\n" <<
            "3) ���������� �������\n" <<
            "4) �������� � ��������\n" <<
            "5) ������� �������\n" <<
            "6) ���\n";
        cin >> choise;
        switch (choise) {
        case 1:
            cout << "\n�������� ������ ���������� �������:\n" <<
                "1. �������\n" <<
                "2. ������\n";
            cin >> choise;
            if (choise == 1) {
                fillSpiral(arr);
            }
            else if (choise == 2) {
               fillSnake(arr);
            }
            break;
        case 2:
            printArr(arr);
            moveBlocs(arr);
            printArr(arr);
            break;
        case 3:
            insert(ptr, end);
            printArr(arr);
            break;
        case 4:
            mathActions(arr);
            printArr(arr);
            break;
        case 5:
            printArr(arr);
            break;
        case 6:
            const int rows = 6;
            const int cols = 6;

            int matrix1[rows][cols];
            int matrix2[rows][cols];
            int resultMatrix[rows][cols];

            fillMatrix1(matrix1, rows, cols);
            printMatrix(matrix1, rows, cols);
            
            fillMatrix2(matrix2, rows, cols);
            printMatrix(matrix2, rows, cols);

            subtractMatrix(matrix2, matrix1, resultMatrix, rows, cols);
            printMatrix(resultMatrix, rows, cols);


            break;
       
        }
    }
    return 0;
}