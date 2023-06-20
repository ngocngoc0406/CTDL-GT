#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void matrixAddition(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[i][j] + c[i][j];
        }
    }
}

void matrixMultiplication(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int n) {
    int sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum = 0;
            for (int k = 0; k < n; k++) {
                sum += b[i][k] * c[k][j];
            }
            a[i][j] = sum;
        }
    }
}

void matrixTransposition(int a[][MAX_SIZE], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}

int main() {
    int n, option;
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];

    cout << "Enter the size of the matrices: ";
    cin >> n;

    cout << "Enter the first matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    cout << "Enter the second matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    cout << "Select an option:\n";
    cout << "1. Matrix addition\n";
    cout << "2. Matrix multiplication\n";
    cout << "3. Matrix transposition\n";
    cin >> option;

    switch (option) {
        case 1:
            matrixAddition(a, b, c, n);
            cout << "The result of the addition is:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 2:
            matrixMultiplication(a, b, c, n);
            cout << "The result of the multiplication is:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            break;
              cout << "The transposed matrix is:\n";
                 matrixTransposition(b, n);
                 for (int i = 0; i < n; i++) {
                 for (int j = 0; j < n; j++) {
                   cout << b[i][j] << " ";
                   }
                 cout << endl;
                       }
                        break;
                    }}
