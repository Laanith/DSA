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


*/



class Solution{
    public :
        int solve(vi A);
};

int Solution::solve(vi A){
   
    map<int,int> m ;

    for(int i = 0 ; i < A.size() ; i++){
        if(m[A[i]]==1) return A[i];
        m[A[i]]++;
    }
    
    return -1;
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->solve({1,2,3,3,4,1,5,6});
return 0 ;
}