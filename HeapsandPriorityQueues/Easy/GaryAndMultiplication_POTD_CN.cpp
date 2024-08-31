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

    vector<long long> multiplication(vector<int> & arr){
        vll ans = {-1, -1};
        priority_queue<int,vector<int>> pq;
        pq.push(arr[0]);
        pq.push(arr[1]);
        pq.push(arr[2]);
        int i = 3;
        while(i<arr.size()){
            int t = pq.top(); pq.pop();
            int st = pq.top(); pq.pop();
            int tt = pq.top(); pq.pop();
            ans.push_back(t*st*tt);
            pq.push(t);
            pq.push(st);
            pq.push(tt);
            pq.push(arr[i]);
            i++;
        }

        int t = pq.top(); pq.pop();
        int st = pq.top(); pq.pop();
        int tt = pq.top(); pq.pop();
        ans.push_back(t*st*tt);
        

        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {2,3,3,4};
for(ll x : S->multiplication(A)) cout<<x<<" "; cout<<endl;

 
return 0 ;
}