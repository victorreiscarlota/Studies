#include <stdio.h>
#include <stdlib.h>

void findTwoSum(int array[], int size, int sum, int result[][2]);
/*
* EXERCISE: Given an array of numbers and an isolated number,
return all combinations of numbers in the array whose sum is equal to the isolated number. */

// Attempt to use Big O for the best possible solution

// Attempt of "brute force" method

void findTwoSum (int array[], int size, int sum, int result [][2])
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] + array[j] == sum) {
                result[count] [0] = array [i];
                result [count] [1] = array [j];
                count++;
            }
        }
    }
}

int main()
{
    int array[] = {2, 5, 8, 3, -2, 9, 0};
    int sum = 3;
    int size = sizeof(array) / sizeof(array[0]);
    int result[100][2];

    findTwoSum(array, size, sum, result);

    for (int i = 0; i<100 && result [i][0] != 0; i++){
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }
    return 0;
}

