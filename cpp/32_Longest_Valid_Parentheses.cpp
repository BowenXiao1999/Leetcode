//
// Created by bowen on 2020/9/13.
//


#include <string>
#include <stack>
using namespace  std;
// Good post
// https://leetcode.com/problems/longest-valid-parentheses/discuss/752095/C%2B%2B-easy-solution-with-stack-and-Dynamic-programming-with-explanation

class Solution {
public:
//    int longestValidParentheses(string s) {
//        int maxlength=0;
//        vector<int> dp(s.length(),0);
//        for(int i=1;i<s.length();i++)
//        {
//            if(s[i]==')')
//            {
//                if(s[i-1]=='(')
//                    dp[i]=(i>=2 ? dp[i-2] : 0)+2;
//                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
//                    dp[i]=dp[i-1]+((i-dp[i-1])>=2 ? dp[i-dp[i-1]-2] :0)+2;
//            }
//            maxlength=max(maxlength,dp[i]);
//        }
//        return maxlength;
//    }
    int longestValidParentheses(string s) {
        int max_length = 0;
        stack<int> a;
        a.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') a.push(i);
            else{
                a.pop();
                if (a.empty()) {
                    a.push(i);
                }else{
                    max_length = max(max_length, i - a.top());
                }
            }
        }

        return max_length;
    }

};

