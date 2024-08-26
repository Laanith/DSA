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
994. Rotting Oranges
Solved
Medium
Topics
Companies
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/
 
 
class Solution{
public :
    int orangesRotting(vvi & grid){
        int n = grid.size(), m = grid[0].size();
        vvi vis(n, vi(m, 0)); 
        queue<pair<pair<int,int>,int>> q;
        int tm = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0 ; j  < m; j++){
                if(grid[i][j] == 2){ vis[i][j]= 2; q.push({{i,j}, tm}); }
            }
        }

        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            int r = p.first.first;
            int c = p.first.second;
            int t = p.second;
            tm = max(tm, t);
            q.pop();
            for(int k = 0; k < 4; k++){
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){\
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t+1});
                }
            }

        }

        pvvi(grid);
        pvvi(vis);

        for(int i=0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1 && vis[i][j]==0) return -1;
            }
        }

        return tm;


    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi grid = {{2,1,1},{1,1,0},{0,1,1}};
cout << S->orangesRotting(grid) << endl;

 
return 0 ;
}