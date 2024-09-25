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
743. Network Delay Time
Solved
Medium
Topics
Companies
Hint
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

*/
 
 
class Solution{
public :
    int networkDelayTime(vvi & times, int n, int k){
        vector<vector<pi>> adj(n+1);
        for(vi it : times ) adj[it[0]].push_back({it[1], it[2]});
        priority_queue< pi, vector<pi> , greater<pi> > pq;
        vi dist(n+1, ima);
        dist[k] =0;
        pq.push({0,k});
        while (!pq.empty())
        {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(pi neigh : adj[node]){
                int neighNode = neigh.first;
                int edgwt  = neigh.second;
                int newDist = edgwt + nodeDist;
                if(dist[neighNode] > newDist){
                    dist[neighNode] = newDist;
                    pq.push({newDist, neighNode});
                }
            }
        }

        int ans = imi;
        for(int i=1; i < n+1; i++) ans = max(dist[i] , ans);
        return ans==ima ? -1 : ans;
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi times = {{2,1,1},{2,3,1},{3,4,1}};
pint(S->networkDelayTime(times,4,2));
times = {{1,2,1}};
pint(S->networkDelayTime(times,2,1));
pint(S->networkDelayTime(times,2,2));


 
return 0 ;
}