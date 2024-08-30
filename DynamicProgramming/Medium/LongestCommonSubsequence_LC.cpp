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
void pv(vi A) { for (auto x : A) cout << setw(5) << setfill(' ') << right << x << ' '; cout << endl; }
// void pv(vi A){for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}cout << endl;}



 
 
/*!SECTION : Problem Description ::
1143. Longest Common Subsequence
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/
 
 
class Solution{
public :
    int func(int ind1, int ind2, string s1, string s2, vvi & dp){
        if(ind1<0 || ind2 < 0) return 0;
        if(ind1==0 && ind2==0) return dp[ind1][ind2] = s1[ind1]==s2[ind2];
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2] = 1 + func(ind1-1, ind2-1, s1, s2, dp);
        int left = func(ind1-1, ind2, s1, s2, dp);
        int up = func(ind1, ind2-1, s1, s2, dp);
        return dp[ind1][ind2] = max(left,up);
    }

    int longestCommonSubsequence(string s1, string s2){
        int m = s1.size(), n = s2.size();
        vvi dp(m, vi(n, -1));
        int ans = func(m-1, n-1,s1, s2, dp);
        pvvi(dp);
        return ans;
    }


    int longestCommonSubsequenceTabulation(string s1, string s2){
        int m = s1.size(), n= s2.size();
        vvi dp(m+1, vi(n+1, -1));
        dp[0][0] = s1[0]==s2[0];
        for(int i = 0; i < m+1; i++) dp[i][0] = 0;
        for(int j = 0; j < n+1; j++) dp[0][j] = 0;
        for(int i=1;i<m+1;i++){
            for(int j = 1; j < n+1; j++){
                if(s1[i]==s2[j]){ 
                    dp[i][j] = 1 + dp[i-1][j-1];
                 }
                else {
                    int left = dp[i-1][j];
                    int up = dp[i][j-1];
                    dp[i][j] = max(up,left);
                }
            }
        }

        pvvi(dp);
        return dp[m][n];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
// pint(S->longestCommonSubsequence("abcde", "ace"));
// pint(S->longestCommonSubsequenceTabulation("abcde", "ace"));
// pint(S->longestCommonSubsequence("abc", "abc"));
// pint(S->longestCommonSubsequenceTabulation("abc", "abc"));
pint(S->longestCommonSubsequence("abc", "def"));
pint(S->longestCommonSubsequenceTabulation("abc", "def"));

 
return 0 ;
}