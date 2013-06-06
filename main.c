#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define N 100000000  //10^8
double S[N], A[N], B[N];

static inline long get_time_ms() {
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main(void) {
    int i;

    // initialization
    for (i=0; i<N; i++) {
        A[i] = i+1;
        B[i] = i+2;
        S[i] = 0;
    }

    long starttime = get_time_ms();
    // main computation
    for (i=0; i<N; i++)
        S[i] = log(A[i]) + log(B[i]);
    long endtime = get_time_ms();

    // accumulation of S[]
    double sum = 0;
    for (i=0; i<N; i++) 
        sum += S[i];

    // printing out the final sum
    printf("sum = %lf\n", sum);
    printf("execution time = %ld\n", endtime-starttime);

    return 0;
}
