#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(){

    int start_time = clock();

    //  Open Input File
    freopen( "input.txt", "r", stdin );

    //  Open Output File
    freopen( "parallel_output.txt", "w", stdout );

    //  Set the number of threads to maximum
    int num_threads = omp_get_max_threads();
    omp_set_num_threads( num_threads );

    //  Get input
    int N, i, sum = 0;
    scanf( "%d", &N );

    int numbers[N];
    for( i = 0; i < N; i++ ){
        scanf( "%d", &numbers[i] );
    }

    //  Calculate the sum of the numbers
    int thread_sum[num_threads];
    int chunk = N / num_threads;
    #pragma omp parallel
    {
        int i_private;
        int threadId = omp_get_thread_num();
        int start = threadId * chunk;
        int end = start + chunk;

        thread_sum[threadId] = 0;
        for( i_private = start; i_private < end; i_private++ ){
            thread_sum[threadId] += numbers[i_private];
        }
    }

    //  Calculate the average
    for( i = 0; i < num_threads; i++ ){
        sum += thread_sum[i];
    }

    int end_time = clock();

    //  Print Results
    printf( "Parallel Results\n" );
    printf( "Number of Threads : %d\n", num_threads );
    printf( "N : %d\n", N );
    printf( "Sum : %d\n", sum );
    printf( "Average : %d\n", sum / N );
    printf( "Time : %d\n", end_time - start_time );

    return 0;
}

// gcc -fopenmp averagepx.c -o averagepx