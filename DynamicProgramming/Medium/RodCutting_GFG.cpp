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
Rod Cutting
Difficulty: MediumAccuracy: 60.66%Submissions: 134K+Points: 4
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by 
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.
Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 
24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*price[1]= 8*3 = 24. 
Your Task:  
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 105


*/
 
 
class Solution{
public :

    int func(int ind, int maxLen, vi & prices, vvi & dp){
        if(ind==0) return maxLen*prices[ind];
        if(dp[ind][maxLen]!=-1) return dp[ind][maxLen];
        int notPick = func(ind-1,maxLen, prices, dp);
        int pick = imi;
        int rodLength = ind+1;
        if(maxLen>=rodLength) pick = prices[ind] + func(ind, maxLen - rodLength, prices, dp);
        return dp[ind][maxLen] = max(pick, notPick);
    }


    int cutRod(vi & prices){
        int n = prices.size();
        int wt = n;
        vvi dp(n, vi(wt+1, -1));
        return func(n-1, wt, prices, dp);
    }

    int cutRodTabulation( vi & prices){
        int n = prices.size();
        vvi dp(n, vi(n+1, imi));
        for(int i=0;i<n+1;i++) dp[0][i] = (i)*prices[0];
        for(int i=1;i<n;i++){ 
            for(int len = 0; len < n+1; len++){
                int notPick = dp[i-1][len];
                int pick = imi;
                int rodLength = i+1;
                if(len >= rodLength) pick = prices[i] + dp[i][len -rodLength];
                dp[i][len] = max(notPick, pick);
            }
        }

        pvvi(dp);

        return dp[n-1][n];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi p = {3,5,8,9,10,17,17,20};
pint(S->cutRod(p));
pint(S->cutRodTabulation(p));

 
return 0 ;
}