class Solution {
public:
    
    long long fun(long long len)
    {
        return ((len+1)*len)/2;
    }
    int numSub(string s) {
        // formula hai (n+1)*n // 2
        long long l=0,r=0;
        long long count=0;
        while(r<s.size())
        {
            if(s[r]=='0')
            {
                count+=fun(r-l);
                r++;
                l=r;
            }
            else{
                r++;
            }
        }
        count+=fun(r-l);// if ends with 1's
        return count% 1000000007;
    }
};
