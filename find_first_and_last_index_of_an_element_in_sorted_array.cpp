class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1}; // base case
        }
        int l = left(nums, target);
        
        if (l == nums.size() || nums[l] != target) {
            return {-1, -1}; // baase case
        }
        
        return {l, left(nums, target + 1) - 1}; //calling
    } 
    
private:
    int left(vector<int>& nums, int target) { 
        int l = 0, r = nums.size(); // binary search
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};