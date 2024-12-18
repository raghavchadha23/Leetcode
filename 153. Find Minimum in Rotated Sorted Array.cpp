class Solution {
public:
    int findMin(vector<int>& nums) {

        int lo = 0;
        int hi = nums.size() - 1;
        int mid;

        while(hi - lo > 1) {
            mid = (hi + lo) / 2;

            if(nums[mid] > nums[hi]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return min(nums[lo], nums[hi]);
        
    }
};
