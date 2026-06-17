class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) return false;

        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0) return false;
        }

        return true;
    }
};

