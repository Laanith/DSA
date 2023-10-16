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
Given an integer A, find the number of zeros in A!;
Example input : 25
output : 6
*/

class Solution{
    public :
        int trailingZeros(int A);
};

int Solution::trailingZeros(int A){
        int x = 5;
        int ans = 0;
        while(x<=A){
            ans += A / x;
            x *= 5;
        }

        return ans;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->trailingZeros(25));

return 0 ;
}