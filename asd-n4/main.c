#include <stdio.h>


double arithmeticMeanOfPositive(double* array, int arraySize) {
    int positiveCount = 0;
    double positiveSum = 0;
        for (int i = 0; i < arraySize; i++) {
            if (array[i] > 0) {
                positiveSum += array[i];
                positiveCount++;
            }
        }
    positiveSum /= positiveCount;
    return positiveSum;
}

double inputArray(double* array, int arrayElementIndex, int arrayCount) {

    printf("Input %d element of array number %d --> ", arrayElementIndex + 1, arrayCount);
    scanf("%lf", &array[arrayElementIndex]);
    return array[arrayElementIndex];
}

void outputArray(double* array, int arraySize, int numberOfArray) {
    for (int i = 0; i < arraySize; i++) {
        printf("%d element of array number %d --> %lf\n", i+1, numberOfArray, array[i]);
    }
    printf("\n");
}

int main(void) {
    int arraySize = 14;
    double array1[arraySize];
    double array2[arraySize];
    double arrayOfSmallest[arraySize];

    for (int i = 0; i < arraySize; i++) {
        array1[i] = inputArray(array1, i, 1);
        array2[i] = inputArray(array2, i, 2);

        // if (array1[i] < array2[i]) {
        //     arrayOfSmallest[i] = array1[i];
        // }
        // else {
        //     arrayOfSmallest[i] = array2[i];
        // }
        arrayOfSmallest[i] = array1[i] < array2[i] ? array1[i] : array2[i];
    }

    
    outputArray(array1, arraySize, 1);
    outputArray(array2, arraySize, 2);
    outputArray(arrayOfSmallest, arraySize,3);

    printf("Arithmetic mean of %d array --> %lf\n", 1, arithmeticMeanOfPositive(array1, arraySize));
    printf("Arithmetic mean of %d array --> %lf\n", 2, arithmeticMeanOfPositive(array2, arraySize));
    printf("Arithmetic mean of %d array --> %lf\n", 3, arithmeticMeanOfPositive(arrayOfSmallest, arraySize));

    return 0;
}
