class TimeMap {
private:
    unordered_map<string, vector<int>> mp;
    unordered_map<string, unordered_map<int, string>> ts;
    
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        ts[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto time = upper_bound(mp[key].begin(), mp[key].end(), timestamp);
        if (time == mp[key].begin()) {
            return "";
        }
        time--;
        return ts[key][*time];
    }
};
