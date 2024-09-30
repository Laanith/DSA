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
827. Making A Large Island
Solved
Hard
Topics
Companies
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.


*/

class DisjointSet{
    public :
        vi rank,size,parent;
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int findParent(int node){
            if(node==parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int ultimateParentOfu = findParent(u);
            int ultimateParentOfv = findParent(v);
            if(size[ultimateParentOfu] < size[ultimateParentOfv]){
                parent[ultimateParentOfu] = ultimateParentOfv;
                size[ultimateParentOfv] += size[ultimateParentOfu];
            }
            else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                size[ultimateParentOfu] += size[ultimateParentOfv];
            }
        }


        void unionByRank(int u, int v){
            int ultimateParentOfu = findParent(u);
            int ultimateParentOfv = findParent(v);
            if(ultimateParentOfu == ultimateParentOfv) return;
            if(rank[ultimateParentOfu] < rank[ultimateParentOfv]){
                parent[ultimateParentOfu] = ultimateParentOfv;
            }
            else if (rank[ultimateParentOfv] < rank[ultimateParentOfu]){
                parent[ultimateParentOfv] = ultimateParentOfu;
            }
            else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                rank[ultimateParentOfu]++;
            }
        }

};
 
 
class Solution{
private :
    bool isValid(int nrow, int ncol, int n){
        return nrow >= 0 && ncol >= 0 && nrow < n && ncol < n;
    }
public :
    int largestIsland(vvi & grid){
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]) continue;
                for(int k = 0; k < 4; k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]){
                        int nodeNo = i * n + j;
                        int neighNo = nrow * n + ncol;
                        if(ds.findParent(nodeNo) != ds.findParent(neighNo)) ds.unionBySize(nodeNo, neighNo);
                    }
                }
            }
        }

        int largestIsland = 0;
        for(int i = 0; i < n; i++){
            for(int j =0 ; j < n; j++){
                if(grid[i][j]) continue;
                int islandSize = 1;
                seti parents;
                for(int k = 0; k < 4 ; k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    if(isValid(nrow, ncol, n)  && grid[nrow][ncol]){
                        parents.insert(ds.findParent(nrow * n + ncol));
                    }
                }

                for(int it : parents) islandSize+=ds.size[it];
                largestIsland = max(largestIsland, islandSize);

            }
        }

        for(int i = 0; i < n*n; i++){
            largestIsland = max(largestIsland , ds.size[ds.findParent(i)]);
        }

        return largestIsland;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi grid = {{1,1}, {1,1}};
pint(S->largestIsland(grid));
grid = {{1,0}, {0,1}};
pint(S->largestIsland(grid));
grid = {{1,1}, {0,1}};
pint(S->largestIsland(grid));

 
return 0 ;
}