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

};

bool compare(const pi & a, const pi & b){
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

map<int,int> m;
m[1] = 3;
m[3] = 4;
m[2] = 4;
m[4] = 10;
m[5] = -1;

vector<pi> v(m.begin(), m.end());

sort(v.begin(), v.end(), compare);

for(pi p : v) cout<<p.first<<" : "<<p.second<<endl;
 
return 0 ;
}