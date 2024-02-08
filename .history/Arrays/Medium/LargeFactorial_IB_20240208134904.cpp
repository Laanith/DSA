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
#define pb push_back
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
Problem Description

Given a number A. Find the factorial of the number.



Problem Constraints
1 <= A <= 100



Input Format
First and only argument is the integer A.



Output Format
Return a string, the factorial of A.



Example Input
Input 1:

A = 2
Input 2:

A = 3


Example Output
Output 1:

 2
Output 2:

 6


Example Explanation
Explanation 1:

2! = 2 .
Explanation 2:

3! = 6 .
*/

class Solution{
public :
    string factorial(int A);
};


string Solution::factorial(int A){
    vi d;
    d.pb(1);

    for (int i = 2; i <= A; i++){
        for (auto it = d.begin(); it != d.end(); it++){
            *it = (*it) * i;
        }

        for (int j = 0; j < d.size(); j++){
            if(d[j]<10) continue;
            if(j==d.siz()-1){
                d.pb(0);
            }
            d[j + 1] += d[j] / 10;
            d[j] = d[j] % 10;
        }
    }

    string s;
    for (auto it = d.rbegin(); it != d.rend(); it++){
        auto c = to_string(*it);
        s += c;
    }

    return s;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int i = 0;
while(i <= 10)
{
    cout <<i<<" factorial : "<<S->factorial(i) << endl;
    i++;
}

return 0 ;
}