class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> seq;
        int orig = num;
        while (num) {
            seq.push_back(num % 10);
            num /= 10;
        }
        vector<int> seq2 = seq;
        int remap_max = -1;
        for (int i = seq.size() - 1; i >= 0; --i) {
            if (seq[i] != 9 && remap_max == -1) {
                remap_max = seq[i];
            }
            if (seq[i] == remap_max) {
                seq[i] = 9;
            }
        }
        int maximum = 0;
        for (int i = seq.size() - 1; i >= 0; --i) {
            maximum *= 10;
            maximum += seq[i];
        }

        int remap_min = -1;
        for (int i = seq2.size() - 1; i >= 0; --i) {
            if (seq2[i] != 0 && remap_min == -1) {
                remap_min = seq2[i];
            }
            if (seq2[i] == remap_min) {
                seq2[i] = 0;
            }
        }

        int minimum = 0;
        for (int i = seq2.size() - 1; i >= 0; --i) {
            minimum *= 10;
            minimum += seq2[i];
        }

        return maximum - minimum;
    }
};
