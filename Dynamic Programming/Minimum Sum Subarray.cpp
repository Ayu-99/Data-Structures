#include <bits/stdc++.h> 
// int minimumSum (vector<int>& arr, int n)
// {
//     int minSubarraySum = 1e9;

//     for (int i = 0; i < n; i++)
//     {
//         int currSubarraySum = 0;

//         for (int j = i; j < n; j++)
//         {
//             currSubarraySum += arr[j];

//             minSubarraySum = min(minSubarraySum, currSubarraySum);
//         }
//     }

//     return minSubarraySum;
// }

int minimumSum (vector<int>& arr, int n)
{
    int minSubarraySum = 1e9;

    int currSubarraySum = 0;

    for (int i = 0; i < n; i++)
    {
        currSubarraySum += arr[i];

        if (currSubarraySum > arr[i])
        {
            currSubarraySum = arr[i];
        }

        minSubarraySum = min(minSubarraySum, currSubarraySum);
    }

    return minSubarraySum;
}

