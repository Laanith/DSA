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
 You are given two numbers A and B.

You have to add them without using arithmetic operators and return their sum.
*/

class Solution{
public :
    int addWithoutSummation(int A, int B);
};

int Solution::addWithoutSummation(int A, int B){
    if(B==0)
        return A;
    else {
        return addWithoutSummation(A ^ B, (unsigned)(A & B) << 1);
    }
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->addWithoutSummation(23,45));
return 0;
}