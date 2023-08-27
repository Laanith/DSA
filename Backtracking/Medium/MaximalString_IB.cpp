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

string ans;

/*!SECTION : Problem Description ::
Given a string A and integer B, what is maximal lexicographical string that can be made from A if you do atmost B swaps.

Input 1:

A = "254"
B = 1

Output 1:

 524
*/

void solve(string A, int B, int i){
    if(i==A.length() || B==0){
        if(ans < A) ans = A;
        return ;
    }

    solve(A,B,i+1);

    for(int j = i; j < A.length(); j++){
        swap(A[i],A[j]);
        solve(A,B-1,i+1);
        swap(A[i],A[j]);
    }
}


class Solution{
    public :
        string MaxStr(string A, int B);
};

string Solution::MaxStr(string A, int B){
    if(B==0) return A;
    ans = A;
    solve(A,B,0);
    return ans;
}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->MaxStr("452",1000);


return 0 ;
}