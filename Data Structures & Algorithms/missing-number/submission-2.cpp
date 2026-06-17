class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using sum;
         int n  = nums.size();
        int sum =accumulate(nums.begin(), nums.end(),0);
         int totalsum = n*(n+1)/2;
         return totalsum-sum;
        
    }
};
