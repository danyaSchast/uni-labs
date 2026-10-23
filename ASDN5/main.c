#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// initialising the matrix with random elements
void matrixInitialising(int matrixRow, int matrixCol, double matrix[matrixRow][matrixCol]) {
    srand(time(NULL));
    char numberSign = 2; // variable for generating number's sign (+/-)
    unsigned range = 1000; // variable for generating integer part of the number
    unsigned precis = 4; // variable for generating floating part of number

    for (int i = 0; i < matrixRow; i++) {
        for (int j = 0; j < matrixCol; j++) {
            matrix[i][j] = pow(-1,rand() % numberSign)*(rand() % range)+(rand() % range/pow(10,precis));
        }
    }
}
// initialising the array, every element in which, is a multiplication of negative elements in each matrix's rows(8)
void arrayInitialising(int matrixRow, int matrixCol, double array[matrixRow], double matrix[matrixRow][matrixCol]) {
    double multiplication = 1;// variable for calculation the multi of negative elements
    for (int i = 0; i < matrixRow; i++) {
        for (int j = 0; j < matrixCol; j++) {
             if (matrix[i][j] < 0) {
                 multiplication *= matrix[i][j];
             }
        }
        if (multiplication != 1) {
            array[i] = multiplication;
        }
        multiplication = 1;
    }
}

void matrixOutput(int matrixRow, int matrixCol, double matrix[matrixRow][matrixCol]) {
    for (int i = 0; i < matrixRow; i++) {
        for (int j = 0; j < matrixCol; j++) {
            printf("%.4lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// sorting elements in matrix's columns in ascending order
void matrixColumnsBubbleSort(int matrixRow,  int matrixCol, double matrix[matrixRow][matrixCol]) {
    double temp;
    for (int i = 0; i < matrixCol; i++) {
        for (int j = 0; j < matrixRow; j++) {
            for (int k = 1; k < matrixRow; k++) {
                if (matrix[k-1][i] > matrix[k][i]) {
                    temp = matrix[k-1][i];
                    matrix[k-1][i] = matrix[k][i];
                    matrix[k][i] = temp;
                }
            }
        }
    }
}

// lineal search in array of multiplication of negative matrix's rows's elements
void arrayLinearSearch(int arrayValue, double array[arrayValue],double desiredValueInArray,double epsilon) {
    for (char i = 0; i < arrayValue; i++) {
        if (fabs((desiredValueInArray - array[i])/array[i]) < epsilon) { // <-- relative epsilon comparison
            printf("Your desired value (%.4lf) is on %d place\n", desiredValueInArray,i+1);
        }
    }
}

int main(void) {

    char matrixRow = 8;
    char matrixCol = 4;
    char arrayRow = matrixRow;
    double epsilon = 1e-4;
    double desiredValueInArray;

    double matrix[matrixRow][matrixCol];
    double array [arrayRow];

    matrixInitialising(matrixRow, matrixCol, matrix);

    matrixOutput(matrixRow, matrixCol, matrix);

    printf("\n");
    printf("Array of multiplications of elements in matrix rows -->\n");
    arrayInitialising(matrixRow, matrixCol, array, matrix);
    printf("\n");
    for (char i = 0; i < arrayRow; i++) {
        printf("%.4lf\n ", array[i]);
    }
    printf("\n");

    printf("Input desired value in array --> ");
    scanf("%lf", &desiredValueInArray);

    arrayLinearSearch(matrixRow, array, desiredValueInArray, epsilon);
    printf("\n");
    matrixColumnsBubbleSort(matrixRow, matrixCol, matrix);
    printf("\n");


    printf("Matrix with sorted elements in columns --> \n");
    printf("\n ");
    matrixOutput(matrixRow, matrixCol, matrix);
return 0;
}
