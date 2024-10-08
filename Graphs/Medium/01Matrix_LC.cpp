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
Problem Name: 1
*/
 
 
class Solution {
public:
    int bfs(int i, int j, vvi & mat){
        cout<<"Element "<<mat[i][j]<<endl;
        queue<pair<int,int>> q;
        int drow[4] = {-1, 0 , 1, 0};
        int dcol[4] = {0, -1, 0, 1};
        cout<<"pushed "<<i<<" "<<j<<" ie "<<mat[i][j]<<" into matrix"<<endl;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int> p = q.front();
            int r = p.first;
            int c = p.second;

            q.pop();
            if(mat[r][c]==0) return abs(i-r)+abs(c-j);
            for(int k = 0; k < 4; k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];
                if(nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size()){
                q.push({r + drow[k], c + dcol[k]});
                cout<<"pushed "<<r + drow[k]<<" "<<c + dcol[k]<<" ie "<<mat[r + drow[k]][c + dcol[k]]<<" into matrix"<<endl;
                }
            }
        }
        return 0;
    }


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vvi vis(n, vi(m,0));
        vvi dist(n, vi(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]==0){
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
            }
        }

        int drow[4] = {0,-1,0,1};
        int dcol[4] = {1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[r][c]=step;
            for(int i= 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},step+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return dist;


    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vvi mat = {{0,0,0},{0,1,0},{0,0,0}};
pvvi(S->updateMatrix(mat));
mat = {{1},{0}};
pvvi(S->updateMatrix(mat));

 
return 0 ;
}