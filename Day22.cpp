/* QUESTION: Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++) {
            if(m[nums[i]] == 1)
                return nums[i];
        }
        return m.begin()->first;
    }
};

/* BITMASKING SOLUTION:
int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int num_0=0,num_1=0;
            for(auto j:nums){
                if(j&(1<<i))
                    num_1++;
                else
                    num_0++;
            }
            if(num_0%3==0)
                ans|=(1<<i);
        }
        return ans;
    }
    */
