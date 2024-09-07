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
130. Surrounded Regions
Medium
Topics
Companies
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]
*/
 
 

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Handle edge cases where the board has no cells or only one row/column
        if (board.empty()) return;  // Empty board
        int n = board.size(), m = board[0].size();
        if (n == 1 || m == 1) return;  // Single row or single column: no surrounded 'O' possible

        vvi vis(n, vi(m, 0));
        queue<pair<int,int>> q;

        // Mark all 'O's on the first and last row as visited
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                vis[0][j] = 1; q.push({0, j});
            }
            if (board[n-1][j] == 'O' && !vis[n-1][j]) {
                vis[n-1][j] = 1; q.push({n-1, j});
            }
        }

        // Mark all 'O's on the first and last column as visited
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                vis[i][0] = 1; q.push({i, 0});
            }
            if (board[i][m-1] == 'O' && !vis[i][m-1]) {
                vis[i][m-1] = 1; q.push({i, m-1});
            }
        }

        // Directions for moving up, down, left, and right
        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {1, 0, -1, 0};

        // BFS to mark all 'O's connected to the edges
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        // Replace all unvisited 'O's with 'X' (since they are surrounded)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vector<vector<char>> board = {{'O','O','O'}, {'O','O','O'}, {'O','O','O'}};
for(int i = 0; i < board.size(); i++){
    for(int j =0; j < board[0].size(); j++) cout<<board[i][j]<<" ";
    cout<<endl;
}
S->solve(board);

cout<<endl<<endl;
for(int i = 0; i < board.size(); i++){
    for(int j =0; j < board[0].size(); j++) cout<<board[i][j]<<" ";
    cout<<endl;
}

cout<<endl<<endl;

board = {{'X'}};
for(int i = 0; i < board.size(); i++){
    for(int j =0; j < board[0].size(); j++) cout<<board[i][j]<<" ";
    cout<<endl;
}
S->solve(board);

cout<<endl<<endl;
for(int i = 0; i < board.size(); i++){
    for(int j =0; j < board[0].size(); j++) cout<<board[i][j]<<" ";
    cout<<endl;
}


 
return 0 ;
}