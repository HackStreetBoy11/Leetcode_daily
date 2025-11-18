class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
       int r =0;
       while(r<bits.size())
       {
            if(bits[r]==0)
            {
                r++;
                if(r==bits.size())return true;
            }else{
                r= r+2;
            }
       }
       return false;
    }
};
