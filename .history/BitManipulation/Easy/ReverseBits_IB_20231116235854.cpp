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

Reverse the bits of an 32 bit unsigned integer A.



Problem Constraints
0 <= A <= 232



Input Format
First and only argument of input contains an integer A.



Output Format
Return a single unsigned integer denoting the decimal value of reversed bits.



Example Input
Input 1:

 0
Input 2:

 3


Example Output
Output 1:

 0
Output 2:

 3221225472


Example Explanation
Explanation 1:

        00000000000000000000000000000000

=>      00000000000000000000000000000000
Explanation 2:

        00000000000000000000000000000011
=>      11000000000000000000000000000000

*/

class Solution{
public :
    unsigned int reverseBits(unsigned int A);
};

unsigned int Solution::reverseBits(unsigned int num)
{
    unsigned int reversed = 0;
    int bitsCount = sizeof(num) * 8; // Number of bits in an unsigned int

    for (int i = 0; i < bitsCount; ++i)
    {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }

    return reversed;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
unsigned int r = 3;
// pint(S->reverseBits(r));

return 0 ;
}