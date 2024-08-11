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
63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 
*/
 
 
class Solution{
public :

    int solve(vvi & mat, int i, int j, vvi & dp){
        if(i>=0 && j >= 0 && mat[i][j]) return 0;
        if(i<0 || j <0 ) return 0;
        if(i==0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int t = solve(mat, i-1, j , dp);
        int l = solve(mat, i, j-1, dp);
        return dp[i][j] = (t+l);
    }

    int uniquePaths(vvi & mat){
        int n = mat.size();
        int m = mat[0].size();
        vvi dp(n+1, vi(m+1, -1));
        return solve(mat, n-1, m-1, dp);
    }

};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi A = {{0,0,0}, { 0,1,0}, {0,0,0}};
pint(S->uniquePaths(A));

 
return 0 ;
}