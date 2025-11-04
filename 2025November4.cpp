class Solution {
public:
int findSum(unordered_map<int,int>& mp,int x)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto &it: mp)
    {
        int freq = it.second;
        int val = it.first;
        pq.push({freq,val});
        if(pq.size()>x)
        {
            pq.pop();
        }
    }
    int sum=0;
    while(!pq.empty())
    {
        auto [freq,val]= pq.top();
        pq.pop();
        sum+=freq*val;
    }
    return sum;
    
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int i =0,j=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            if(j-i+1==k)
            {
                int val=findSum(mp,x);
                ans.push_back(val);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
