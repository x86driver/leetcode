class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans;
        int lines = 1;
        int pixels = 0;

        size_t i = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            int ch_pixel = widths[s[i] - 'a'];
            if (pixels + ch_pixel > 100) {
                ++lines;
                pixels = 0;
            }
            pixels += ch_pixel;
        }

        ans.push_back(lines);
        ans.push_back(pixels);

        return ans;
    }
};
