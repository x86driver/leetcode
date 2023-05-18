class SparseVector {
public:
    vector<pair<int, int>> n;
    int total;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)
                n.push_back({i, nums[i]});
        }
        total = nums.size();
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        int i = 0, j = 0;
        int index = 0;
        while (index < total && i < n.size() && j < vec.n.size()) {
            if (n[i].first == index && vec.n[j].first == index)
                product += n[i].second * vec.n[j].second;
            if (n[i].first == index)
                ++i;
            if (vec.n[j].first == index)
                ++j;
            ++index;
        }
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
