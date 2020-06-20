/* QUESTION: The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {    //12% TC
        string s;
        for(int i=1; i<=n; i++) 
            s.push_back(i+'0');
        while(--k) 
            next_permutation(begin(s), s.end());
        return s;
    }
};

//BACKTRACKING METHOD (100% TC):
// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         stringstream ss;
//         string res;
//         int factorial = 1, cnt;
//         for (int i = n; i > 0; i--) factorial *= i;
//         vector<bool> visited(n+1, false);    
//         for (int i = n; i > 0; i--) {
//             factorial /= i;
//             for (cnt = 1; factorial < k; cnt++) k -= factorial;            
//             for (int j = 1, k = 0; j <= n; j++) {
//                 if (!visited[j]) k++;
//                 if (k == cnt) {
//                     visited[j] = true;
//                     ss.str(""); ss.clear(); ss << j;
//                     res += ss.str();
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
