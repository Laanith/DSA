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
A items are to be delivered in a circle of size B.

Find the position where the Ath item will be delivered if we start from a given position C.

NOTE: Items are distributed at adjacent positions starting from C.

Example Input
Input 1:

 A = 2
 B = 5
 C = 1
Input 2:

 A = 8
 B = 5
 C = 2


Example Output
Output 1:

 2
Output 2:

 4
*/

class Solution{
    public :
        int finalPosition(int A, int B, int C);
};

int Solution::finalPosition(int A,int B,int C){
        int val = A % B;
        return (val + C % B - 1) % B;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->finalPosition(8, 5, 2));

return 0 ;
}