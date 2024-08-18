class Solution {
    public:
    int nthUglyNumber(int n) {
        vector <int> results;
        results.push_back(1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) i++;
            if (results.back() == results[j] * 3) j++;
            if (results.back() == results[k] * 5) k++;
        }
        return results.back();
    }
};
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         priority_queue<long, vector<long>, greater<long>> minHeap;
//         unordered_set<long> seenNumbers; //which have already added in the min heap
//         vector<int> primeFactors = {
//             2, 3, 5};  

//         minHeap.push(1);
//         seenNumbers.insert(1);

//         long currentUgly = 1;
//         for (int i = 0; i < n; ++i) {
//             currentUgly = minHeap.top(); 
//             minHeap.pop();               

//             for (int prime : primeFactors) {
//                 long nextUgly = currentUgly * prime;
//                 if (seenNumbers.find(nextUgly) ==
//                     seenNumbers.end()) { 
//                     minHeap.push(nextUgly);
//                     seenNumbers.insert(nextUgly);
//                 }
//             }
//         }

//         return static_cast<int>(currentUgly); 
//     }
// };
