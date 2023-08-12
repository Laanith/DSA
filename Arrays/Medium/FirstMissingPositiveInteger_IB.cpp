#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
 Given an unsorted integer array, find the first missing positive integer.
Your algorithm should run in O(n) time and use constant space.
*/

class Solution{
public :
    int solve(vi A);
};

int Solution::solve(vi A){
    int n = A.size();
    vi B(n + 1, 0);
    for(auto x : A){
        if(x> 0 && x <= n)
            B[x] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        if(!B[i])
            return i;
    }

    return B.size();
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {3, 4, -1, 1};
pint(S->solve(A)); 

return 0 ;
}