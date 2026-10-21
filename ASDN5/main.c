#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

    char matrixRow = 8;
    char matrixCol = 4;
    char arrayRow = matrixRow;
    double epsilon = 1e-4;

    char numberSign = 2; //змінна для генерування знаку дійсного числа
    unsigned range = 1000; //змінна для генерування цілої частини числа
    unsigned precis = 4; //змінна для генерування знаків після коми
    double multiplication = 1;
    double desiredValueInArray;

    srand(time(NULL));

    double matrix[matrixRow][matrixCol];
    double array [arrayRow];

    for (char i = 0; i < matrixRow; i++) {
        for (char j = 0; j < matrixCol; j++) {
            matrix[i][j] = pow(-1,rand() % numberSign)*(rand() % range)+(rand() % range/pow(10,precis));
            printf("%.4lf ", matrix[i][j]);

            if (matrix[i][j] < 0) {
                multiplication *= matrix[i][j];
            }
        }
        if (multiplication != 1) {
            array[i] = multiplication;
        }
        multiplication = 1;
        printf("\n");
    }
    printf("\n");
    printf("Array of multiplications of elements in matrix rows -->\n");
    printf("\n");
    for (char i = 0; i < arrayRow; i++) {
        printf("%.4lf\n ", array[i]);
    }
    printf("\n");

    printf("Input desired value in array --> ");
    scanf("%lf", &desiredValueInArray);

    //знаходження заданого значення
    for (char i = 0; i < arrayRow; i++) {
        if (fabs((desiredValueInArray - array[i])/array[i]) < epsilon) {
            printf("Your desired value (%.4lf) is on %d place", desiredValueInArray,i+1);
        }
    }
return 0;
}
