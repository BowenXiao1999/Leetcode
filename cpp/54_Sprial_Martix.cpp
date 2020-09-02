//
// Created by bowen on 2020/9/2.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) {
            return ans;
        }
        int tr = matrix.size();
        int tc = matrix[0].size();
        vector<vector<bool>> vis(tr, vector<bool>(tc, false));
        int sr = 0, sc = 0;
        ans.push_back(matrix[sr][sc]);
        int d = 0;
        for(int i = 0; i<tr*tc + (tr*tc)/4 +1; i++) {
            sr += dr[d];
            sc += dc[d];
            if(sr >= 0 && sc >= 0 && sr<tr && sc<tc && !vis[sr][sc]) {
                vis[0][0] = true;
                ans.push_back(matrix[sr][sc]);
                vis[sr][sc] = true;

            } else {
                sr -= dr[d];
                sc -= dc[d];
                d = (d+1)%4;
            }
        }
        return ans;

    }
};