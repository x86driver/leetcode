class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> s;
        s.push(0);

        for (size_t i = 1; i < height.size(); ++i) {
            if (height[i] < height[s.top()]) {
                s.push(i);
            } else if (height[i] == height[s.top()]) {
                s.pop();
                s.push(i);
            } else {
                while (!s.empty() && height[i] > height[s.top()]) {
                    int mid = s.top();
                    s.pop();
                    if (!s.empty()) {
                        int h = min(height[s.top()], height[i]) - height[mid];
                        int w = i - s.top() - 1;
                        sum += h * w;
                    }
                }
                s.push(i);
            }
        }

        return sum;
    }
};
