#include <stdio.h>
#include <stdlib.h>

int main(){

    //  Open Output File
    freopen( "input.txt", "w", stdout );

    //  Generate input
    int N = 500000;
    printf( "%d\n", N );
    
    int i;
    for( i = 0; i < N; i++ ){
        printf( "%d\n", rand() % 255 );
    }

    return 0;
}