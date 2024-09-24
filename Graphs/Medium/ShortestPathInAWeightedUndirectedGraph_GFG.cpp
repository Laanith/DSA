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

Shortest Path in Weighted undirected graph
Difficulty: MediumAccuracy: 50.0%Submissions: 63K+Points: 4
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
Input: n = 2, m= 0, edges = [ ]
Output: -1
Explanation: Since there are no edges, so no answer is possible.
Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n+m)

Constraint:
2 <= n <= 106
0 <= m <= 106
1 <= a, b <= n
1 <= w <= 105


*/
 
 
class Solution{
public :


    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(vi & v : edges){
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
         
        vi dist(n+1, INT_MAX), parent(n+1);
        for(int i = 1; i < n+1; i++) parent[i]=i;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,1});
        dist[1]=0;
        while(!pq.empty()){
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto neigh : adj[node]){
                int neighNode = neigh.first;
                int edgWt = neigh.second;
                int newDist = nodeDist + edgWt;
                if(dist[neighNode] > newDist){
                    dist[neighNode] = newDist;
                    pq.push({newDist, neighNode});
                    parent[neighNode] = node;
                }
            }
        }
        
        vi ans;
        int node = n;
        while(parent[node]!=node){
            ans.push_back(node);
            node = parent[node];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(), ans.end());

        ans.insert(ans.begin(), dist[n]);
        
        return ans;
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
pv(S->shortestPath(5,6,edges));

 
return 0 ;
}