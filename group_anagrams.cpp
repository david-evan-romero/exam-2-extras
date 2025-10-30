class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // use sorted string as key
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& p : groups) result.push_back(p.second);
        return result;
    }
};
