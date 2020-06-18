/* QUESTION: Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = citations.size();
        int i=0, j=l-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (citations[mid]>=l-mid && (mid==0 || citations[mid-1]<=l-mid)){
                return l-mid;
            }else if (citations[mid]<l-mid){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return 0;        
    }
};

             
             
