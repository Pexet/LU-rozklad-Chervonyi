#include <iostream>


int main(int argc, char* argv[])
{
    int i, j, k, n = 3;
    float sum;

    float** A = new float* [n];
    float** L = new float* [n];
    float** U = new float* [n];

    for (int i = 1; i <= n; i++) {
        A[i] = new float[n];
        L[i] = new float[n];
        U[i] = new float[n];
    }

    std::cout << "A matr \n";

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {

            std::cout << "\na[" << i << "][" << j << "] = ";
            std::cin >> A[i][j];
            L[i][j] = 0;
            U[i][j] = 0;
            L[i][i] = 1;
            std::cout << A[i][j] << "  ";
        }std::cout << "\n";
    }

    /////////// L і U матриці


    for (j = 1; j <= n; j++) {
        U[1][j] = A[1][j];
    }
    for (j = 2; j <= n; j++) {
        L[j][1] = A[j][1] / A[1][1];
    }


    for (i = 2; i <= n; i++) {
        for (j = i; j <= n; j++)
        {
            sum = 0;
            for (k = 1; k < i; k++) { sum = sum + L[i][k] * U[k][j]; }
            U[i][j] = A[i][j] - sum;
        }
        for (j = i + 1; j <= n; j++)
        {
            sum = 0;
            for (k = 1; k < i; k++) { sum = sum + L[j][k] * U[k][i]; }
            L[j][i] = (A[j][i] - sum) / U[i][i];
            L[i][i] = 1;
        }
    }



    std::cout << "L matr \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            std::cout << L[i][j] << "  ";
        }std::cout << "\n";
    }

    std::cout << "U matr \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            std::cout << U[i][j] << "  ";
        }std::cout << "\n";
    }
    system("pause");
    return 0;
}
