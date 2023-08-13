#include <stdio.h>
#include <stdlib.h>

#define N 5

//  3 Global Variables
int Global_Variable_1;
int Global_Variable_2 = 2;
int Global_Variable_3 = 3;

//  Recursive Function
void Recursive_Function(int number_of_times){

    //  Local Variable
    int local_variable = 0;

    printf("%d : Recursive Function Local Variable Address: %p\n", N - number_of_times, &local_variable);
    
    if( number_of_times == 0 ){
        return;
    }
    Recursive_Function(number_of_times - 1);
}

int main(){

    //  3 Local Variables
    int Local_Variable_1;
    int Local_Variable_2;
    int Local_Variable_3;

    //  Proof that stack grows downwards
    printf("( Downwards ) Stack Variable Addresses:\n");
    printf("Local_Variable_1: %p\n", &Local_Variable_1);
    printf("Local_Variable_2: %p\n", &Local_Variable_2);
    printf("Local_Variable_3: %p\n", &Local_Variable_3);

    //  Recursive Function Call
    printf("Recursive Function Call:\n");
    Recursive_Function(N);

    //  3 Malloc Variables
    int *Malloc_Variable_1 = malloc(sizeof(int));
    int *Malloc_Variable_2 = malloc(sizeof(int));
    int *Malloc_Variable_3 = malloc(sizeof(int));

    //  Proof that heap grows upwards
    printf("\n( Upwards ) Heap Variable Addresses:\n");
    printf("Global_Variable_1: %p\n", &Global_Variable_1);
    printf("Global_Variable_2: %p\n", &Global_Variable_2);
    printf("Global_Variable_3: %p\n", &Global_Variable_3);
    printf("Malloc_Variable_1: %p\n", Malloc_Variable_1);
    printf("Malloc_Variable_2: %p\n", Malloc_Variable_2);
    printf("Malloc_Variable_3: %p\n", Malloc_Variable_3);

    return 0;
}