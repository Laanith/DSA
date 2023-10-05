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
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
Basic two sum problem on Arrays. I think there is no need of description.
*/



class Solution{
    public :
    pi TwoSum(vi A, int sum);
};

pi Solution::TwoSum(vi A, int sum){
    set<int> s;
    for(auto x : A){
        if (s.find(sum-x) != s.end()){
            pi p;
            p.first = x;
            p.second = sum-x;
            return p;
        }
        else s.insert(x);

    }
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vi A = {1,2,3,4,5,6,7,8,9,0};
pp(S->TwoSum(A,13));
return 0 ;
}