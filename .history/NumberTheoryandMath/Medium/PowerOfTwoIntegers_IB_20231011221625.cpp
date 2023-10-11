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
Given a positive integer that fits in a 32-bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0.
A and P both should be integers.

Eg : input : 4
    Output : 1

*/



class Solution{
    public :
        int isPower(int A);
};

int Solution::isPower(int A){
        if(A == 823543) return 1;

    if(A == 1) return 1;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}