class Solution {
public:
    int MOD=1000000007;
    int dfs(vector<vector<int>>& grid,int k, int i,int j,int rem_sum,vector<vector<vector<int>>>&dp)
    {
        // base condition
        if(i>=grid.size() || j>=grid[0].size())return 0;
        if(dp[i][j][rem_sum]!=-1)return dp[i][j][rem_sum];
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            return (rem_sum+grid[i][j])%k==0?1:0;
        }
        int down = dfs(grid,k,i+1,j,(rem_sum+grid[i][j])%k,dp);
        int right= dfs(grid,k,i,j+1,(rem_sum+grid[i][j])%k,dp);
        return  dp[i][j][rem_sum]= (down+right)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // i will apply bfs to move through all branches 
        // i will add up the sum till the end
        // and i am thinking about backtracking 
        // for memorization used changing variable
        int m=grid.size();int n=grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,0)));
        int rem_sum=0;
        for(int i=0;i<k;i++)
        {
            dp[m-1][n-1][i]=(i+grid[m-1][n-1])%k==0?1:0;
        }
        for(int i =m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                for(int l=0;l<k;l++)
                {   
                    int rem = (l+grid[i][j])%k;
                    int down = dp[i+1][j][rem];
                    int right= dp[i][j+1][rem];
                    dp[i][j][l]=(down+right)%MOD;
                }
            }
        }
       return  dp[0][0][0];
    }
};
