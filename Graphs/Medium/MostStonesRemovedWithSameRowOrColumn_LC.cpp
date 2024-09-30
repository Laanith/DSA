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
 
 
#define vvi vector<vector<int>>
#define vi vector<int>
#define pi pair<int,int>

class DisjointSet{
    public :
    vector<unsigned long long> rank,size,parent;
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones){
        int maxRow = INT_MIN, maxCol = INT_MIN;
        for(auto it : stones){ maxRow = max(maxRow, it[0]); maxCol = max(maxCol, it[1]); }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it : stones){
            int u = it[0];
            int v = maxRow + 1 + it[1];
            ds.unionBySize(u,v);
            stoneNodes[u] = 1;
            stoneNodes[v] = 1;
        }

        int numComponents = 0;
        for(auto it : stoneNodes ){
            if(ds.findParent(it.first)==it.first) numComponents++;
        }
        return stones.size() - numComponents;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
pint(S->removeStones(stones));
 
return 0 ;
}