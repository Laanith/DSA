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


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // priority queue to store data in form of {dist, {hops, node}}
        queue<pair<int,pi>> q;
        vector<vector<pi>> adj(n);
        vi dist(n, INT_MAX);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[src]=0;
        q.push({0, {0, src}});
        while(!q.empty()){
            auto it = q.front();
            int nodeDist = it.first;
            int hops = it.second.first;
            int node = it.second.second;
            q.pop();
            if(hops > k) continue;
            for(auto neigh : adj[node]){
                int neighNode = neigh.first;
                int edgwt = neigh.second;
                int newDist = nodeDist + edgwt;
                int newHop = hops + 1;
                if(dist[neighNode] >= newDist){
                    dist[neighNode] = newDist;
                    q.push({newDist, {newHop, neighNode}});
                }
            }
        }

        pv(dist);
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
pint(S->findCheapestPrice(4, flights, 0, 3, 1));

 
return 0 ;
}