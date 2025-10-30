class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Base case: prefix sum = 0 occurs once
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // Check if there’s a previous prefix sum that would make the subarray sum = k
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                count += prefixCount[prefixSum - k];
            }
            
            // Record the current prefix sum
            prefixCount[prefixSum]++;
        }
        
        return count;
    }
};
