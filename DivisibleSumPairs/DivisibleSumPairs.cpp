/* DivisibleSumPairs.cpp - HackerRank
** Author: Walter Iddings
** Date: 12/16/20
*/

/* An array of integers are given, along with a positive integer (k).
** The challenge is to find the number of array value pairs (i, j)
** such that index i < j and values at index i + j is divisible by k. 
*/

#include <iostream>
#include <vector>

using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {

    int numOfIndexes = 2;  // Number of indexes
    int arraySize = n;  // Size of array
    int totalDivisible = 0;  // Number divisible by k
    int sumTotal = 0;  // Addition of the two indexes

    // Find each value pair that fills the requirements
    for (int i = 0; (i < arraySize) && (i + numOfIndexes) <= arraySize; i++) {
        sumTotal = 0;
        // Iterate starting from index i
        for (int j = i; j < arraySize - 1; j++) {
            sumTotal = ar[i] + ar[j + 1];
            // sumTotal divisible by k?
            if (!(sumTotal % k))
                ++totalDivisible;
        }
    }

    return totalDivisible;
}

int main()
{
    vector<int> myArray = { 1, 3, 2, 6, 1, 2 };
    int n = myArray.size();
    int k = 3;  // Number to test index pairs of array for divisibility
    int divisible = 0;

    divisible = divisibleSumPairs(n, k, myArray);
    cout << divisible << endl;
}


