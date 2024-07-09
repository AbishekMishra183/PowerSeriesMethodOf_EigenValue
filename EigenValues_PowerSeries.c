#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float tol ,maxError;
    int i, j, iteration = 0;
    int n;

    printf("Enter the order of Matrix:\n");
    scanf("%d", &n);
    int A[n][n];
    float X0[n]; // Adjusted size of X0 to n
    float X1[n]; // To store the result of multiplication
    float absError[n]; // To store the absolute error between X1 and X0
    float maxAbsValue;

    printf("Enter the values of the Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the Tolerance:\n");
    scanf("%f", &tol);

    // Assuming you want to input initial values for X0
    printf("Enter the initial values for vector X0 (size %d):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &X0[i]);
    }

    // Printing the matrix to verify input
    printf("Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Printing the tolerance to verify input
    printf("Tolerance: %f\n", tol);

    // Printing the initial vector X0 to verify input
    printf("Initial vector X0:\n");
    for (i = 0; i < n; i++) {
        printf("%f ", X0[i]);
    }
    printf("\n");

    // Repeat the process until the maximum absolute error is within tolerance
    do {
        // Matrix-vector multiplication
        for (i = 0; i < n; i++) {
            X1[i] = 0;
            for (j = 0; j < n; j++) {
                X1[i] += A[i][j] * X0[j];
            }
        }

        // Finding the largest absolute value in X1
        maxAbsValue = fabs(X1[0]);
        for (i = 1; i < n; i++) {
            if (fabs(X1[i]) > maxAbsValue) {
                maxAbsValue = fabs(X1[i]);
            }
        }
         printf("The largest absolute value in X1 is: %f\n", maxAbsValue);

        // Normalizing X1 by dividing each element by maxAbsValue
        for (i = 0; i < n; i++) {
            X1[i] = X1[i] / maxAbsValue;
        }

        // Calculating the absolute error between X1 and X0
        for (i = 0; i < n; i++) {
            absError[i] = fabs(X1[i] - X0[i]);
        }

        // Finding the maximum absolute error
        float maxError = fabs(absError[0]);
        for (i = 0; i < n; i++) {
            if (fabs(absError[i]) > maxError) {
                maxError = fabs(absError[i]);
            }
        }

        printf("Iteration %d - Max Error: %f\n", ++iteration, maxError);

        // Update X0 with X1 for the next iteration
        for (i = 0; i < n; i++) {
            X0[i] = X1[i];
        }

        // Check if the maximum error is within the tolerance
    } while (  maxError > tol);

    // Printing the final normalized vector X1
    printf("The final normalized values of X1 are:\n");
    for (i = 0; i < n; i++) {
        printf("%f ", X1[i]);
    }
    printf("\n");



    return 0;
}
