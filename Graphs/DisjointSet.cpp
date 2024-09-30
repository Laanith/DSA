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
//NOTE -  An implementation of Disjoint Set for reusability
*/


class DisjointSet{
    vi rank,size,parent;
    public :
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


 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
 
return 0 ;
}