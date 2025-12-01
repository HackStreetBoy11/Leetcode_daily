class Solution {
public:
    bool is_possible(int mid,vector<int>& batteries,int n)
    {
        long long target= 1LL*mid*n;
        long long sum=0;
        for(int i =0;i<batteries.size();i++)
        {
            sum+=min(batteries[i],mid);
            if(sum>=target)return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(int &num:batteries)
        {
            sum+=num;
        }
            long long l =0,r=sum/n;
        long long result= 0;
        while(l<=r)
        {
            long long mid = l+(r-l)/2;
            if(is_possible(mid,batteries,n))
            {
                result =mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;
    }
};
