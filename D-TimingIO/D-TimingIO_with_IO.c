#include <stdio.h>
#include <time.h>

int main(){

    int start_time = clock();

    for( int i=0; i<1000; i++ ){
        printf("i: %d\n", i);
    }

    printf("Start Time: %d\n", start_time);
    int end_time = clock();
    printf("End Time: %d\n", end_time);
    int total_time = end_time - start_time;
    printf("Total Time: %d\n", total_time);

    return 0;
}