class Solution {
public:

    bool canBananasBeEaten(vector<int> pile,int h, long long int k) {
        long long hours = 0;
        for(long long i = 0; i < pile.size(); ++i) {
            if(pile[i] == 0) {
                continue;
            }

            if(pile[i] < k) {
                hours++;
                continue;
            }

            if(pile[i] >= k && pile[i] > 0 && k > 0) {
                long long numHours = pile[i] / k;
                hours = hours + numHours;
                if((pile[i] % k) != 0) {
                    hours++;
                }
            }

        }

        if(hours <= h) {
            return true;
        }
        return false;

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        long long int lo = 0;
        long long int hi = piles[piles.size() - 1];
        long long int mid;


        while((hi - lo) > 1) {
            mid = lo + (hi - lo)/2;
            if(canBananasBeEaten(piles, h, mid)) {  
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        long long int lo_check = 0;
        long long int hi_check = 0;
        if(canBananasBeEaten(piles, h, lo)) {
            lo_check = 1;
        }
        if(canBananasBeEaten(piles, h, hi)) {
            hi_check = 1;
        }

        if(lo_check == 1 && lo != 0) {
            return lo;
        }
        else{
            return hi;
        }
        
    }
};
