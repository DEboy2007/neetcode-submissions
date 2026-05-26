class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
    
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto time = upper_bound(mp[key].begin(), mp[key].end(), timestamp, [](int target, const pair<string, int>& curr) {return target < curr.second;});
        if (time == mp[key].begin()) {
            return "";
        }
        time--;
        return time->first;
    }
};
