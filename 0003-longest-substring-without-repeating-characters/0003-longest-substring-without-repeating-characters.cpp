class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1); 
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};