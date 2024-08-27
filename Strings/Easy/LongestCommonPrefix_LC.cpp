#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}cout << endl;}



 
 
/*!SECTION : Problem Description ::
14. Longest Common Prefix
Solved
Easy
Topics
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/
 
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort(strs.begin(), strs.end());
        int k = 0, minlen = INT_MAX;
        for(int s = 0; s < strs.size(); s++){
            if(strs[s].length() < minlen){
                minlen = strs[s].length();
                k = s;
            }
        }
        string ans="";
        for(int i = 0; i < strs[k].length(); i++){
            int ele = strs[k][i];
            bool same = true;
            for(auto x : strs) if(x[i]!=ele) same = false;
            if(same) ans+=ele;
            else return ans;
        }
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vs A = {"flower", "flow", "flourish"};
cout<<S->longestCommonPrefix(A)<<endl;

 
return 0 ;
}