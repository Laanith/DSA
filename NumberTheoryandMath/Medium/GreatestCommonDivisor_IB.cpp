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
Given two numbers, return their GCD.
*/

class Solution{
    public :
        int GCD(int A, int B);
};

int Solution::GCD(int A, int B){

 
            int ans = 1;
            if (A == 0 || B == 0)
            {
                return max(A, B);
            }
            for (int i = 2; i <= min(A, B); i++)
            {
                if (A % i == 0 and B % i == 0)
                {
                    ans = max(i, ans);
                }
            }
            return ans;
        
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->GCD(9, 45));

return 0 ;
}