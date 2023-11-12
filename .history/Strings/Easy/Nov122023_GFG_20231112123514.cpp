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
 
*/
 
 
class Solution{
public :
    bool solve(string A, string B);
};

bool Solution::solve(string A, string B){
    if (A.length() != B.length())
        return false;
    char fchar = A[0];
    char schar = A[1];
    int n = A.size();
    char lchar = B[n - 1];
    char lschar = B[n - 2];
    string a = A.substr(2, n - 2);
    string b = B.substr(0, n - 2);
    cout << fchar < < < endl << schar << endl
                             << lchar << endl
                             << lschar << endl;
    return ((fchar == lchar) && (schar == lschar) && (a == b));
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->solve("amazon", "azonam"));

return 0 ;
}