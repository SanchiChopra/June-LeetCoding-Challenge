/* QUESTION: Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:

vector<int> largestDivisibleSubset(vector<int>& nums) {
 if(nums.size()<=1) return nums;
 sort(nums.begin(),nums.end());
 vector<int>parent(nums.size(),-1);//To store the  parent index of current element. So we can trace back to the subset
 vector<int>dp(nums.size(),1);
 int maxlength=0;int pos=0;
 //Similar to LIS
 for(int i=1;i<nums.size();i++)
 {
     for(int j=0;j<i;j++)
     {
         if(nums[i]%nums[j]==0) dp[i]=max(dp[i],1+dp[j]);
         if(dp[i]==1+dp[j]) parent[i]=j;//means j is parent of i 
     }
     if(dp[i]>maxlength)
     {
         maxlength=dp[i];
         pos=i;
     }
 }
 vector<int>result(maxlength);
 for(int i=maxlength-1;i>=0;i--)
 {
     result[i]=nums[pos];
     pos=parent[pos];
 }
return result;
}
};
