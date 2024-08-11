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
void pvvi(vvi A){for(auto v : A){pv(v);} cout<<endl;}



 
 
/*!SECTION : Problem Description ::
64. Minimum Path Sum
Medium

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
 
 
class Solution{
public :
    int func(int i, int j, vvi &grid, vvi &dp, int n, int m){
        if(i>=n || j >= m ) return ima;
        if(i==n-1 && j==m-1) return dp[i][j] = grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right = func(i,j+1,grid,dp,n,m);
        int down = func(i+1,j,grid,dp,n,m);
        return dp[i][j] = (grid[i][j] + min(right, down));
    }

    int minPathSum(vvi & grid){
        int n = grid.size();
        int m = grid[0].size();
        vvi dp(n, vi(m, -1));
        pvvi(grid);
        int ans = func(0,0,grid, dp,n,m);
        pvvi(dp);
        return ans;
    }


    int minPathSumTabulation(vvi & grid){
        int n = grid.size();
        int m = grid[0].size();
        vvi dp(n, vi(m,-1));
        for(int i = n-1; i >= 0 ; i--){
            for(int j = m-1; j >= 0; j--){
                if(i==n-1 && j == m-1){dp[i][j] = grid[i][j]; continue;}
                int right = INT_MAX, down = INT_MAX;
                if(i<n-1) down = dp[i+1][j];
                if(j<m-1) right = dp[i][j+1];
                dp[i][j] = (grid[i][j] + min(right, down));
            }
        }


        pvvi(dp);

        return dp[0][0];
    }
};




class Solution2 {
public:
    int func(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m){
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j == m-1) return dp[i][j] = grid[i][j];
        int right = func(i,j+1,grid,dp,n,m);
        int left = func(i+1,j,grid,dp,n,m);
        return dp[i][j] = (grid[i][j] + min(left,right));
    }

    int minPathSumMemoization(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(0,0,grid,dp,n,m);
    }


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i==n-1&&j==m-1){dp[i][j]=grid[i][j]; continue;}
                int down = INT_MAX, right = INT_MAX;
                if(i<n-1) down = dp[i+1][j];
                if(j<m-1) right = dp[i][j+1];
                dp[i][j] = (grid[i][j] + min(down,right));
            }
        }

        return dp[0][0];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vvi grid = {{3,8,6,0,5,9,9,6,3,4,0,5,7,3,9,3},{0,9,2,5,5,4,9,1,4,6,9,5,6,7,3,2},{8,2,2,3,3,3,1,6,9,1,1,6,6,2,1,9},{1,3,6,9,9,5,0,3,4,9,1,0,9,6,2,7},{8,6,2,2,1,3,0,0,7,2,7,5,4,8,4,8},{4,1,9,5,8,9,9,2,0,2,5,1,8,7,0,9},{6,2,1,7,8,1,8,5,5,7,0,2,5,7,2,1},{8,1,7,6,2,8,1,2,2,6,4,0,5,4,1,3},{9,2,1,7,6,1,4,3,8,6,5,5,3,9,7,3},{0,6,0,2,4,3,7,6,1,3,8,6,9,0,0,8},{4,3,7,2,4,3,6,4,0,3,9,5,3,6,9,3},{2,1,8,8,4,5,6,5,8,7,3,7,7,5,8,3},{0,7,6,6,1,2,0,3,5,0,8,0,8,7,4,3},{0,4,3,4,9,0,1,9,7,7,8,6,4,6,9,5},{6,5,1,9,9,2,2,7,4,2,7,2,2,3,7,2},{7,1,9,6,1,2,7,0,9,6,6,4,4,5,1,0},{3,4,9,2,8,3,1,2,6,9,7,0,2,4,2,0},{5,1,8,8,4,6,8,5,2,4,1,6,2,2,9,7}};


pint(S->minPathSum(grid));


pint(S->minPathSumTabulation(grid));

return 0 ;
}