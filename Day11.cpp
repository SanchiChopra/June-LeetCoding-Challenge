/* QUESTION: Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

/* TWO-PASS ALGORITHM  */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, w=0, b=0;
        int i;
        for(i=0; i<nums.size(); i++) {
            if(nums[i] == 0)
                r++;
            else if(nums[i] == 1)
                w++;
            else
                b++;
        }
        for(i=0; i<r; i++) 
            nums[i] = 0;
        for(i=r; i<w+r; i++)
            nums[i] = 1;
        for(i=w+r; i<nums.size(); i++)
            nums[i] = 2;
    }
};

/* ONE-PASS ALGORITHM  */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,h=nums.size()-1,mid=0;
        while(mid<=h)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[l]);
                l++;mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[h]);
                h--;
            }
            else mid++;
        }
    }
};
