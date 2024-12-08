//Question Leetcode link: https://leetcode.com/problems/contains-duplicate-ii/description/?envType=problem-list-v2&envId=sliding-window&difficulty=EASY
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0;

        if(nums.size() == 1) {
            return false;
        }

        for(int j = 1; j < nums.size(); j++) {
            
            if(abs(i - j) <= k && abs(i - j) != 0)  {
                if(nums[i] == nums[j]) {
                    return true;
                }
            } else {
                i++;
                j = i;
                continue;
            }
        }

        int last_i = nums.size() - k - 1;
        

        map<int, int> mp;

        for(int x = last_i; x < nums.size(); x++) {
           if(mp.find(nums[x]) != mp.end()) {
            return true;
           }
           else {
            mp[nums[x]] = 10;
           }
        }


        return false;
    }
};
