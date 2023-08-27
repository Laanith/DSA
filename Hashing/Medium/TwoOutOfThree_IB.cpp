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
Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.

*/



class Solution{
    public :
        vi solve(vi a, vi B, vi c);
};


vi Solution::solve(vi A, vi B, vi C){
    vi ans;
    set<int> s,p,r;
    for(auto x : A){
        s.insert(x);
    }
    for(auto x :  B){
        p.insert(x);
    }
    for(auto x : B){
        if(s.find(x) != s.end()) r.insert(x);
    }
    for(auto x : C){
        if(s.find(x) != s.end()) r.insert(x);
    }
    for(auto x : C){
        if(p.find(x) != p.end()) r.insert(x);
    }
    for(auto it : r) ans.push_back(it);
    return ans;
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pv(S->solve({1,1,2},{2,3},{3}));

return 0 ;
}