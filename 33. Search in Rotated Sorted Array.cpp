class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;  
        int mid;



        while(hi - lo > 1) {
            mid = (lo + hi) / 2;


            if(nums[lo] == target) {
                return lo;
            }
            else if(nums[hi] == target) {
                return hi;
            }

            else if((nums[mid] > nums[hi]) && (target > nums[mid]) && (target > nums[hi]) ) {
                lo = mid + 1;
            }
            else if((nums[mid] > nums[hi]) && (target < nums[mid]) && (target < nums[hi]) ) {
                lo = mid + 1;
            }
            else if((nums[lo] > nums[mid]) && (target < nums[mid]) && (target > nums[lo]) ) {
                hi = mid;
            }
            else if((nums[lo] > nums[mid]) && (target > nums[mid]) && (target < nums[lo]) ) {
                lo = mid;
            }
            else if((nums[lo] > nums[mid]) && (nums[hi] > nums[mid]) && (target > nums[mid]) ) {
                hi = mid;
            }
            else if((nums[lo] > nums[mid]) && (nums[hi] > nums[mid]) && (target < nums[mid]) ) {
                hi = mid;
            }
            else if(nums[mid] < target) {
                lo = mid; 
            }
            else {
                hi = mid;
            }

        }

        if(nums[lo] == target) {
            return lo;
        } else if(nums[hi] == target) {
            return hi;
        }
        else {
            return -1;
        }
        
    }
};
