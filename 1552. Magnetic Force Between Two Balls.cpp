class Solution {
public:
    int tries = 0;
    bool checkIfCanPlaced(vector<int>& position, int numBalls, int distance) {
        tries++;
        int counter = 1;
        int flag = 0;
        int storeValueofi = 0;
        for(int i = 1; i < position.size(); ++i) {
            if(abs(position[i] - position[storeValueofi]) >= distance) {
                counter++;
                flag = 1;
                storeValueofi = i;
            }
            if(counter == numBalls) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int lo = 0;
        int hi = position[position.size() - 1];
        int mid;
        
        while((hi - lo) > 1 ) {
            mid = lo + (hi - lo)/2;

            if(checkIfCanPlaced(position, m, mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }

        }
        if(checkIfCanPlaced(position, m, hi)) {
            return hi;
        }
        else{
            return lo;
        }
    }
};
