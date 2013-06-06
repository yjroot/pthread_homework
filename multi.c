#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

#define N 100000000  //10^8
double S[N], A[N], B[N];
int not; //Number of therads

static inline long get_time_ms() {
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void *log_sum(void *argument) {
    int tid = *((int *) argument);

    int i;

    int start = tid * (N / not);
    int end = (tid + 1) * (N / not);
    for(i=start; i<end; i++) {
        S[i] = log(A[i]) + log(B[i]);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int i;

    // initialization
    if (argc<=1) {
        return -1;
    }
    not = atoi(argv[1]);
    if (not<1) {
        return -1;
    }
    for (i=0; i<N; i++) {
        A[i] = i+1;
        B[i] = i+2;
        S[i] = 0;
    }
    pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t)*not);
    int *args = (int*)malloc(sizeof(int)*not);

    // main computation
    long starttime = get_time_ms();
    for (i=0; i<not; ++i) {
        args[i] = i;
        pthread_create(&threads[i], NULL, log_sum, (void *) &args[i]);
    }
    for (i=0; i<not; ++i) {
        pthread_join(threads[i], NULL);
    }
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
