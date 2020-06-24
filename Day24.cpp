/* QUESTION: Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
 */
 
 class Solution {
public:
    int numTrees(int n) {
        int i;
        int dp[n+1];
        dp[0] = 1;
        for(i=1; i<=n; i++) {
            dp[i] = 0;
            for(int j=0; j<i; j++)
                dp[i] += dp[j] * dp[i-1-j];
        }
        return dp[n];
    }
};
