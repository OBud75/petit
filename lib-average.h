#include <stdio.h>

float average(int length, int array[]){
    int sum = 0;
    
    for (size_t i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum/length;
}