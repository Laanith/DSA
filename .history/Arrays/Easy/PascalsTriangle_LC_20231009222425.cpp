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
#define vvi vector<vector<int>>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
#define umapii unordered_map<int,int>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::

Example 1:

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/



class Solution{
    public :
       vvi pascalsTriangle(int n);
};

vi pascalRow(int n){
    int iter = n;
    vi v = {1};
    for(int i = 1; i < n; i++){
        v.push_back(v.back()*iter/i);
        iter--;
    }
}

vvi Solution::pascalsTriangle(int num){
    vvi v = {{1}};
    for(int i = 1; i <= num; i++){
        v.push_back(pascalRow(i));
    }
    return v;
}






int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

pvvi(S->pascalsTriangle(5));

return 0 ;
}