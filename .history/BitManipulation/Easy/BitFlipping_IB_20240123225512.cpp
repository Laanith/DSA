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



Given an integer A.
Write binary representation of the integer without leading zeros.
Flip all bits then return the integer value of the binary number formed.
Flipping means 0 -> 1 and 1 -> 0.


Problem Constraints
1 <= A <= 109


Input Format
Given an integer A.


Output Format
Return an integer.


Example Input
Input 1:
A = 7
Input 2:

A = 5


Example Output
Output 1:
0
Output 2:

2


Example Explanation
Explanation 1:
7 -> 111 -> 000 ->0
Explanation 2:

5 -> 101 -> 010 ->2
*/

class Solution{
public :
    int flipBits(int A);
};
 
int Solution::flipBits(int A){
    int mask = ~0;
    while(mask & A )
        mask <<= 1;
    return ~A ^ mask;
}
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->flipBits(7)<<endl<<S->flipBits(5);

return 0 ;
}