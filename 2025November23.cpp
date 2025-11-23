class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        vector<int> rem1,rem2;
        for(int &num:nums)
        {
            sum+=num;
            if(num%3==1)
            {
                rem1.push_back(num);
            }
            else if(num%3==2)
            {
                rem2.push_back(num);
            }
        }
        int rem = sum%3;
        if(rem==0)return sum;
        int result=0;

        if(rem==1)
        {
            int remain1 = rem1.size()>=1?rem1[0]:INT_MAX;
            int remain2 = rem2.size()>=2?rem2[0]+rem2[1]:INT_MAX;
            return sum-min(remain1,remain2);
        }
        else{
             int remain1 = rem2.size()>=1?rem2[0]:INT_MAX;
            int remain2 = rem1.size()>=2?rem1[0]+rem1[1]:INT_MAX;
            return sum-min(remain1,remain2);
        }
        return -1;

    }
};
