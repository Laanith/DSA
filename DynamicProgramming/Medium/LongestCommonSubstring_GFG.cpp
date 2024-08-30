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
Longest Common Substring
Difficulty: MediumAccuracy: 42.69%Submissions: 242K+Points: 4
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.


*/
 
 
class Solution{
public :

    int longestCommonSubstring(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vvi dp(n+1,vi(m+1,0));
        int ans = 0;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s1[i-1]==s2[j-1]) {dp[i][j] = 1 + dp[i-1][j-1]; ans = max(ans, dp[i][j]); }
                else dp[i][j] = 0;
            }
        }

        pvvi(dp);

        return ans;

        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->longestCommonSubstring("abcdgh","acdghr"));
pint(S->longestCommonSubstring("abc","acb"));
// pint(S->longestCommonSubstring("abcdgh","acdghr"));

 
return 0 ;
}