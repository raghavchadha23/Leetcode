//Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) {
            return 0;
        }
        if(s.size() == 1) {
            return 1;
        }

        int i = 0;
        int j = 0;
        string longest = "";
        int done = 0;
        map<char, int> mp;

        while(j < s.size() && done == 0) {

            if(mp.find(s[j]) == mp.end()) {
                mp[s[j]] = 0;

                if(j == s.size() - 1) {
                string substring = s.substr(i, j - i + 1);
                if(substring.size() > longest.size()) {
                    longest = substring;
                    }
                    
                }
                j++;
            }
            else {
                mp.clear();
                string substring = s.substr(i, j - i);
                if(substring.size() > longest.size()) {
                    longest = substring;
                }
                i++;
                j = i;
            }

            if(i == s.size() - 1) {
                done = 1;
            }

            
        }

        if(i == 0) {
            return s.size();
        }
        return longest.size();


    }
};
