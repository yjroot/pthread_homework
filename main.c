#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000000  //10^8
double S[N], A[N], B[N];

int main(void) {
    int i;

    // initialization
    for (i=0; i<N; i++) {
        A[i] = i+1;
        B[i] = i+2;
        S[i] = 0;
    }
    // main computation
    for (i=0; i<N; i++)
        S[i] = log(A[i]) + log(B[i]);

    // accumulation of S[]
    double sum = 0;
    for (i=0; i<N; i++) 
        sum += S[i];

    // printing out the final sum
    printf("sum = %lf\n", sum);

    return 0;
}
