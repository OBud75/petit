#include "lib-average.h"

int main(int argc, char const *argv[])
{
    int n=10;
    int scores[n];

    for (size_t i = 0; i < n; i++)
    {
        scores[i] = i;
    }
    printf("Average: %.1f\n", average(n, scores));
}
