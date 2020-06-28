/*QUESTION: Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/

void solve(string x,map<string,vector<string>>&mp,vector<string>&ans){
    
    while(!mp[x].empty()){
        int n=mp[x].size()-1;
        string s=mp[x][n];
        mp[x].pop_back();
        solve(s,mp,ans);
    }
    ans.push_back(x);
    return ;
}

bool comp(string a,string b){
    if(a>b) return true;
    return false;
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string,vector<string>> mp;
        
        for(int i=0;i<t.size();i++){
            mp[t[i][0]].push_back(t[i][1]);
        }
        
        auto it=mp.begin();
        while(it!=mp.end()){
            sort(it->second.begin(),it->second.end(),comp);
            it++;
        }
        vector<string> ans;
        solve("JFK",mp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
