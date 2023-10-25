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
 Given a string A of parantheses  ‘(‘ or ‘)’.

The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.

An string is valid if:

Open brackets must be closed by the corresponding closing bracket.
Open brackets must be closed in the correct order.
*/

class Solution{
public :
    int solve(string A);
};
 
 
int Solution::solve(string A){

    int cnt = 0;
    queue<char> q;
    for(auto c : A){
        if(c == '(')
            q.push(c);
        else if(!q.empty() && c == ')')
            q.pop();
        else
            cnt++;
    }

    return cnt + int(q.size());
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->solve("((())))"));

return 0 ;
}