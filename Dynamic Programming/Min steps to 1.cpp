#include <bits/stdc++.h> 
int countStepsToOneHelper(int n, vector<int> &dp) {

    if (n == 1) {
        return 0;
    }

    int inf = 1e9;

    if (n < 1) {
        return inf;
    }

 

    int minusOne = 1 + countStepsToOneHelper(n - 1, dp);

    int div2 = inf, div3 = inf;

    if (n % 3 == 0) {
        div3 = 1 + countStepsToOneHelper(n / 3, dp);
    }

    if (n % 2 == 0) {
        div2 = 1 + countStepsToOneHelper(n / 2, dp);
    }

//     return min({minusOne, div2, div3});
    return dp[n] = min({minusOne, div2, div3});
}

int countStepsToOne(int n) {
    vector<int> dp(n + 1, -1);

    return countStepsToOneHelper(n, dp);
}
