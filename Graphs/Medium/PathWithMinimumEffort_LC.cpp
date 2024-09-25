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
1631. Path With Minimum Effort
Solved
Medium
Topics
Companies
Hint
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/
 
 
class Solution{
public :
    int minimumEffortPath(vvi & heights){
        int n = heights.size(), m = heights[0].size();
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        vvi dist(n, vi(m, ima));
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                         greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int nodeEffort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int k = 0; k < 4; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newEffort = max(nodeEffort, abs(heights[row][col]-heights[nrow][ncol]));
                    if(dist[nrow][ncol] > newEffort){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }      
        }

        pvvi(dist);

        return dist[n-1][m-1];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi heights = {{1,2,2}, {3,8,2}, {5,3,5}};
pint(S->minimumEffortPath(heights));
heights = {{1,2,3}, {3,8,4}, {5,3,5}};
pint(S->minimumEffortPath(heights));
heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
pint(S->minimumEffortPath(heights));


 
return 0 ;
}