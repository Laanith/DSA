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
#define umapii unordered_map<int,int>
#define vvi vector<vector<int>>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void ps(string A){cout<<A<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::
You love strings a lot, so you decided to play the following game.

You have a tree T of A nodes. The tree is represented by a matrix B of dimensions (A - 1) * 2 such that there exist an edge between node B[i][1] and BEach node is assigned a lowercase english character, which is represented by a string C of length A. Node i is assigned character at position I of strin

You are given Q queries in the form of a matrix D of dimensions Q * 2 For each you query you will perform the following steps.

1. You will move from node D[i][1] to node D[i][2] using the shortest possible path.2. Let V[1], V[2]... V[K] be the nodes visited in the corresponding order. Create a string S such that length of S is equal to K and S[i] = C[v[i]]

3. Store string S in your bag.

Return the number of unique strings you would create
*/

class Solution{
    public :
        
};




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}