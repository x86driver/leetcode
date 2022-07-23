class Logger {
public:
    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        cout << message << timestamp << endl;
        auto it = map.find(message);
        if (it == map.end()) {
            map[message] = timestamp + 10;
            return true;
        }
        if (timestamp >= it->second) {
            map[message] = timestamp + 10;
            return true;
        } else {
            return false;
        }
    }
private:
    unordered_map<string, int> map;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
