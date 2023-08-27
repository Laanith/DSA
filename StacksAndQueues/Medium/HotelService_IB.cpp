#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define si stack<int>
#define qi queue<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
You are travelling to Neverland. After a long journey, you decided to take rest in a hotel for a night.

You have the map of Neverland in the form of 2D matrix A with dimensions N x M. 

The rows are numbered from 1 to N, and the columns are numbered from 1 to M.

You can travel from one cell to any adjacent cell. Two cells are considered adjacent if they share a side.

In the map, there are only two digits, 0 and 1, 
where 1 denotes a hotel in that cell, and 0 denotes an empty cell.

You are also given another 2D array B with dimension Q x 2,
 
where each row denotes a co-ordinate (X, Y) on the map (1 - indexed). 
For each coordinate you have to find the distance to the nearest hotel.

Return an array denoting the answer to each coordinate in the array B.

*/



class Solution{
    public :
        vi nearestHotel(vector<vi> &A, vector<vi> &B);
};

vector<int> Solution::nearestHotel(vector<vector<int> > &a, vector<vector<int> > &b) {
    int n = a[0].size();
    int m = a.size();
    int adj[m+1][n+1];
    bool vis[m+1][n+1];
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                adj[i][j]=0;
                vis[i][j]=true;
                q.push({i,j});
                continue;
            }
            vis[i][j]=false;
        }
    }
    while(q.size()!=0){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i+1<m){
            if(!vis[i+1][j]){
                adj[i+1][j]=1+adj[i][j];
                q.push({i+1,j});
                vis[i+1][j]=true;
            }
        }
        if(i-1>=0){
            if(!vis[i-1][j]){
                adj[i-1][j]=1+adj[i][j];
                q.push({i-1,j});
                vis[i-1][j]=true;
            }
        }
        if(j+1<n){
            if(!vis[i][j+1]){
                adj[i][j+1]=1+adj[i][j];
                q.push({i,j+1});
                vis[i][j+1]=true;
            }
        }
        if(j-1>=0){
            if(!vis[i][j-1]){
                adj[i][j-1]=1+adj[i][j];
                q.push({i,j-1});
                vis[i][j-1]=true;
            }
        }
         
    }
    vector<int> v;
    int row = b.size();
    for(int l =0;l<row;l++){
        int i = b[l][0]-1;
        int j= b[l][1]-1;
        v.push_back(adj[i][j]);
       
    }
    return v;
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vector<vi> A = {{0,0},{1,0}};
vector<vi> B = {{1,1},{2,1},{1,2}};
pv(S->nearestHotel(A,B));

return 0 ;
}