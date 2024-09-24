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

*/
 
 
class Solution{
public :
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue< pair<int, pair<int,int>>,
                     vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        int n = grid.size();
        vvi dist(n, vi(n, INT_MAX));
        if(grid[0][0]) return -1;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int nodeDist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(int di=-1;di<=1;di++){
                for(int dj=-1; dj<=1; dj++){
                    if(di==0 && dj==0) continue;
                    int nrow = i + di;
                    int ncol = j + dj;
                    if(nrow>=0 && nrow < n && ncol >= 0 && ncol < n && !grid[nrow][ncol]){
                        if(dist[nrow][ncol] >= nodeDist + 1){
                            dist[nrow][ncol] = nodeDist+1;
                            pq.push({dist[nrow][ncol], {nrow, ncol}});
                        }
                    }
                }
            }

        }
        
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1]+1;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi grid = {{0,0,0},{1,1,0},{1,1,0}};
pint(S->shortestPathBinaryMatrix(grid));
grid = {{0,1}, {1,0}};
pint(S->shortestPathBinaryMatrix(grid));
grid =  {{1,0,0},{1,1,0},{1,1,0}};
pint(S->shortestPathBinaryMatrix(grid));
 

 

return 0 ;
}