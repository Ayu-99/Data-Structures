long long int numOfPairs(vector<int> &arr) {
	// Write your code here.
    long long int totalCount = 0;
	vector<long long int> rem(3, 0);

	for (int i = 0 ; i < arr.size(); i++) {
		rem[arr[i] % 3]++;
	}

    //count for group of 2 elements
	totalCount += (rem[0] * (rem[0] - 1)) / 2;
	totalCount += (rem[1] * rem[2]);

    //count for group of 3 elemenyts
	totalCount += (rem[0] * (rem[0] - 1) * (rem[0] - 2)) / 6;
	totalCount += (rem[1] * (rem[1] - 1) * (rem[1] - 2)) / 6;
	totalCount += (rem[2] * (rem[2] - 1) * (rem[2] - 2)) / 6;
	totalCount += (rem[0] * rem[1] * rem[2]);

	return totalCount;
}
