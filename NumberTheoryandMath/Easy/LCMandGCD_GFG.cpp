#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::
Given two numbers A and B. The task is to find out their LCM and GCD.



Example 1:

Input:
A = 5 , B = 10
Output:
10 5
Explanation:
LCM of 5 and 10 is 10, while
thier GCD is 5.
Example 2:

Input:
A = 14 , B = 8
Output:
56 2
Explanation:
LCM of 14 and 8 is 56, while
thier GCD is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function lcmAndGcd() which takes an Integer N as input and returns a List of two Integers, the required LCM and GCD.

Expected Time Complexity: O(log(min(A, B))
Expected Auxiliary Space: O(1)

Constraints:
1 <= A,B <= 109
*/

class Solution{
public :

    ll GCD( ll A, ll B){
        while(A>0 && B>0){
            if(A>B) A = A%B;
            else B = B%A;
        }
        if(A==0) return B;
        return A;
    }
 vector<ll> lcmAndGcd(ll A, ll B){
    ll product = A*B;
    ll gcd = GCD(A,B);
    return {product/gcd , gcd};
 }

};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->lcmAndGcd(14,8)[0]<<" "<<S->lcmAndGcd(14,8)[1]<<endl;
 
 
return 0 ;
}