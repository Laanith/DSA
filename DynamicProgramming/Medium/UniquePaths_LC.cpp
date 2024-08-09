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
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
62. Unique Paths
Medium
Topics
Companies
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
/*/


int func(int i, int j, vvi &dp,int n,int m){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i>=m || j >= n || i < 0 || j < 0) return 0;
    if(i==m-1 && j==n-1) return dp[i][j] = 0;
    else if ( i == m-1) return dp[i][j] =  1;
    else if ( j == n - 1) return dp[i][j] = 1;

    int right = func(i,j+1,dp,n,m);
    int down = func(i+1,j,dp,n,m);
    return dp[i][j] = (right + down);
}
 
 
class Solution{
public :
    int uniquePaths(int m, int n){
        vvi dp(m,vi(n,-1));
        int ans = func(0,0, dp,n,m);
        pvvi(dp);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->uniquePaths(3,7));
 
return 0 ;
}