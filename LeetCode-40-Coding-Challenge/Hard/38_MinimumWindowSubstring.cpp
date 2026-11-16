class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for (char c : t) {
            need[c]++;
        }
        
        unordered_map<char,int> window;
        int matched = 0;
        int left = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // EXPAND
            window[s[right]]++;
            
            if (need.count(s[right]) && window[s[right]] == need[s[right]]) {
                matched++;
            }
            
            // SHRINK while valid
            while (matched == need.size()) {
                
                
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                
               
                window[s[left]]--;
                
              
                if (need.count(s[left]) && window[s[left]] < need[s[left]]) {
                    matched--;
                }
                
                left++;
            }
        }
        
        return (bestLen == INT_MAX) ? "" : s.substr(bestStart, bestLen);
    }
};