#include <stdio.h>
#include <time.h>

int main(){

    int start_time = clock();

    //  Open Input File
    freopen( "input.txt", "r", stdin );

    //  Open Output File
    freopen( "nonparallel_output.txt", "w", stdout );

    //  Get input
    int N, i, sum = 0;
    scanf( "%d", &N );
    
    int numbers[N];
    for( i = 0; i < N; i++ ){
        scanf( "%d", &numbers[i] );
    }

    //  Calculate the sum of the numbers
    for( i = 0; i < N; i++ ){
        sum += numbers[i];
    }    

    int end_time = clock();

    //  Print Results
    printf( "Non-Parallel Results\n" );
    printf( "N : %d\n", N );
    printf( "Sum : %d\n", sum );
    printf( "Average : %d\n", sum / N );
    printf( "Time : %d\n", end_time - start_time );

    return 0;
}