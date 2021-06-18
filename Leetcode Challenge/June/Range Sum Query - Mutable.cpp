class NumArray {
    private:
    int n;
    vector<int> seg;

    int build(const vector<int> &nums, int left, int right, int node) {
        int middle;
        int leftSum, rightSum;

        if (left == right) return seg[node] = nums[left];

        middle = (left + right) / 2;
        leftSum = build(nums, left, middle, 2 * node + 1);
        rightSum = build(nums, middle+1, right, 2 * node + 2);
        return seg[node] = leftSum + rightSum;
    }

    int sumRange(int left, int right, int ss, int se, int node) {
        int leftSum, rightSum;
        int middle;

        if (right < ss || left > se) return 0;
        if (left <= ss && se <= right) return seg[node];

        middle = (ss + se) / 2;
        leftSum = sumRange(left, right, ss, middle, 2 * node + 1);
        rightSum = sumRange(left, right, middle+1, se, 2 * node + 2);

        return leftSum + rightSum;
    }

    int update(int index, int newValue, int ss, int se, int node) {
        int leftSum, rightSum;
        int middle;

        if (index < ss || index > se) return seg[node];
        if (ss == se) return seg[node] = newValue;

        middle = (ss + se) / 2;
        leftSum = update(index, newValue, ss, middle, 2 * node + 1);
        rightSum = update(index, newValue, middle+1, se, 2 * node + 2);
        return seg[node] = leftSum + rightSum;
    }

    public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, n-1, 0);
    }
    
    void update(int index, int val) {
        update(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1, 0);
    }
};
