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
    void func(string s, int left, int right, vector<string> & ans){
        if(left > right) return;
        if(left == 0 && right == 0){ ans.push_back(s); return; }
        if(left && !right){
            func(s + '(', left-1, right, ans);
            return;
        }
        if(right && !left){
            func(s + ')', left, right-1, ans);
            return;
        }
        func(s + '(', left-1, right, ans);
        func(s + ')', left, right-1, ans);
        return;

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func("", n, n, ans);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
for(string s : S->generateParenthesis(3)) cout<<s<<" ";

 
return 0 ;
}