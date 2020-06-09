/* QUESTION: Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

/* DP APPROACH */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m == dp[m][n];
    }
};

/* TWO POINTER APPROACH */
class Solution {
public:
bool isSubsequence(string s, string t) 
    {
        int idx = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == s[idx])
                idx++;
            if(idx == s.size())
                break;
        }
        return idx == s.size();
    }
   };
