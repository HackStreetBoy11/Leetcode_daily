class Solution {
public:
    int countOdds(int low, int high) {
        int n = high-low+1;
        if(low%2 && high%2)
        {
            return (n+1)/2;
        }
        else
        {
            return n/2;
        }

    }
};
