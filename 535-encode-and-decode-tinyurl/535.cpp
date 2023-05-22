class Solution {
public:
    const int PRIME = 31;
    const int MODULUS = 1e9 + 9;
    map<int, string> m;
    int hashCode(const string &s) {
        long long hash = 0;
        long long power = 1;
        for (int i = 0; i < s.size(); ++i) {
            hash = (hash + s[i] * power) % MODULUS;
            power = (power * PRIME) % MODULUS;
        }
        return hash;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int hash = hashCode(longUrl);
        m[hash] = longUrl;
        return "http://tinyurl.com/" + to_string(hash);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        const string tinyUrl = "http://tinyurl.com/";
        size_t pos = shortUrl.find(tinyUrl);
        pos += tinyUrl.size();
        string strhash = shortUrl.substr(pos);
        return m[stoi(strhash)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
