//
// Created by bowen on 2020/9/3.
//
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> dp(matrix.size()+1,vector<int> (matrix[0].size()+1,0));
        int maxi=0;
        for(int i=1;i<=matrix.size();i++)
        {
            for(int j=1;j<=matrix[0].size();j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};