/*

Print all subarrays with 0 sum

Given an array, print all subarrays in the array which has sum 0.

Examples:  

Input:  arr = [6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7]

Output:  

Subarray found from Index 2 to 4
Subarray found from Index 2 to 6          
Subarray found from Index 5 to 6
Subarray found from Index 6 to 9
Subarray found from Index 0 to 10

*/

#include <bits/stdc++.h>

using namespace std;

// Time Complexity --> O(n^2), Space Complexity --> O(1)

void zeroSubASum1(vector<int> &A, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            cout << "Subarray found from index " << i << " to " << i << endl;
    }
    for (int i = 2; i <= n; i++)
    {
        long long sm = 0;
        for (int m = 0; m < i; m++)
            sm += A[m];
        if (sm == 0)
            cout << "Subarray found from index " << 0 << " to " << i - 1 << endl;
        int j = i;
        while (j < n)
        {
            sm -= A[j - i];
            sm += A[j];
            if (sm == 0)
                cout << "Subarray found from index " << j - i + 1 << " to " << j << endl;
            j++;
        }
    }
}

// Time Complexity --> O(n), Space Complexity --> O(n)

void zeroSubASum2(vector<int> &A, int n)
{
    unordered_map<int, vector<int>> ump;
    long long sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += A[i];
        if (sm == 0)
            cout << "Subarray found from index " << 0 << " to " << i << endl;
        if (ump.find(sm) != ump.end())
        {
            vector<int> tmp = ump[sm];
            for (auto x : tmp)
                cout << "Subarray found from index " << x + 1 << " to " << i << endl;
        }
        ump[sm].push_back(i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    zeroSubASum1(A, n);
    cout << endl;
    zeroSubASum2(A, n);
    return 0;
}
