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
516. Longest Palindromic Subsequence
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/


//NOTE - Longest Palindrome Sub seq of a string is equal to longest common subseq of the string and its reverse.
 
 
#define vvi vector<vector<int>>
#define vi vector<int>


class Solution {
public:

    int longestPalindromeSubseq(string s) {
        string & s1 = s;
        string t = s;
        reverse(t.begin(), t.end());
        string & s2 = t;
        
        int n = s.size();
        int m = s.size();


        // Create a 2D DP array to store the length of the LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize the first row and first column to 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        // Fill in the DP array
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        // The value at dp[n][m] contains the length of the LCS
        return dp[n][m];
    }
    
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->longestPalindromeSubseq("bbbab"));
pint(S->longestPalindromeSubseq("cbbd"));
pint(S->longestPalindromeSubseq("bbb"));

 
return 0 ;
}