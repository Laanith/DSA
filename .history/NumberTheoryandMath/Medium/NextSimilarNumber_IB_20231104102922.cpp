#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
 Problem Description

Given a number A in a form of string.

You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.


Example Input
Input 1:

 A = "218765"
Input 2:

 A = "4321"


Example Output
Output 1:

 "251678"
Output 2:

 "-1"
*/

class Solution{
public :
    string solve(string A);
};

string Solution::solve(string A){
    ll n = A.size();
    string s = A;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    if(s==A)
        return "-1";
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}