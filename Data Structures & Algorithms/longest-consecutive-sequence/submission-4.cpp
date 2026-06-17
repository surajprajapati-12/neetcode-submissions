class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int maxlen =0;
        for(auto  x: st){
            if(st.find(x-1) == st.end()){
                int cnt =1;
                int element =x;
                while(st.find(element+1) != st.end()){
                    cnt++;
                    element++;
                }
            
            maxlen = max(cnt, maxlen);
            }
        }
        return maxlen;
    }
};
