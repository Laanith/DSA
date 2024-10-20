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
5. Longest Palindromic Substring
Solved
Medium
Topics
Companies
Hint
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consists of only digits and English letters.
*/
 
 
class Solution{
public :
string LongestPalindromicSubstring(string s){
    string sub = "";
    int n = s.size();
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        while((l>=0) && (r<n) && (s[l]==s[r])){
            if((r-l+1)>sub.size()){
                sub = s.substr(l,r-l+1);
            }
            l--; r++;
        }
        l=i,r=i+1;
        while((l>=0) && (r<n) && (s[l]==s[r])){
            if((r-l+1)>sub.size()){
                sub = s.substr(l,r-l+1);
            }
            l--; r++;
        }
    }
    return sub;
}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->LongestPalindromicSubstring("abbcabbad")<<endl;
cout<<S->LongestPalindromicSubstring("abbd")<<endl;

 
return 0 ;
}