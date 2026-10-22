#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

    char matrixRow = 8;
    char matrixCol = 4;
    char arrayRow = matrixRow;
    double epsilon = 1e-4;

    char numberSign = 2; //variable for generating number's sign (+/-)
    unsigned range = 1000; //variable for generating integer part of the number
    unsigned precis = 4; //variable for generating floating part of number
    double multiplication = 1;//variable for calculation the multi of negative elements
    double temp;//variable for sorting
    double desiredValueInArray;


    double matrix[matrixRow][matrixCol];
    double array [arrayRow];

    srand(time(NULL));

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

    //lineal search for inputted value
    for (char i = 0; i < arrayRow; i++) {
        if (fabs((desiredValueInArray - array[i])/array[i]) < epsilon) { //relative epsilon comparison
            printf("Your desired value (%.4lf) is on %d place\n", desiredValueInArray,i+1);
        }
    }

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


    for (int i = 0; i < matrixRow; i++) {
        for (int j = 0; j < matrixCol; j++) {
            printf("%.4lf ", matrix[i][j]);
        }
        printf("\n");
    }
return 0;
}
