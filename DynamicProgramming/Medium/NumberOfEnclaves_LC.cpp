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
1020. Number of Enclaves
Solved
Medium
Topics
Companies
Hint
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/
 
 
class Solution{
public :
    int numEnclaves(vvi & grid){
        int n=grid.size(), m = grid[0].size();
        vvi vis(n, vi(m, 0));
        queue<pi> q;
        for(int i = 0 ; i < n; i++) if(grid[i][0]) {q.push({i,0}); vis[i][0]=1;}
        for(int i = 0 ; i < n; i++) if(grid[i][m-1]) {q.push({i,m-1}); vis[i][m-1]=1;}
        for(int j = 0 ; j < m; j++) if(grid[0][j]) {q.push({0,j}); vis[0][j]=1;}
        for(int j = 0 ; j < m; j++) if(grid[n-1][j]) {q.push({n-1,j}); vis[n-1][j]=1;}

        int drow[4] = {0,-1,0,1};
        int dcol[4] = {1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
pvvi(grid);
pint(S->numEnclaves(grid));
grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
pvvi(grid);
pint(S->numEnclaves(grid));

 
return 0 ;
}