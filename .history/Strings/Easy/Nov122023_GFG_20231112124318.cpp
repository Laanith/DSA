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
    if (str1.size() != str2.size())
        return false;
    int n = str1.size();
    string str3 = str1.substr(2, n) + str1.substr(0, 2);
    string str4 = str1.substr(n - 2, n) + str1.substr(0, n - 2);
    return (str3 == str2 || str4 == str2);
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->solve("daxjheq", "eqdaxjh"));

return 0 ;
}