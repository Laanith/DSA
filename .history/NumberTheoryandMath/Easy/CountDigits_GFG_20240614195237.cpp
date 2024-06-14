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
Given a number N. Count the number of digits in N which evenly divide N.

Note :- Evenly divides means whether N is divisible by a digit i.e. leaves a remainder 0 when divided.


Example 1:

Input:
N = 12
Output:
2
Explanation:
1, 2 both divide 12 evenly
Example 2:

Input:
N = 23
Output
0
Explanation:
2 and 3, none of them
divide 23 evenly

Your Task:
You don't need to read input or print anything. Your task is to complete the function evenlyDivides() which takes an integer N as input parameters and returns an integer, total number factor of digits N which divides N evenly.


Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)


Constraints:
1<=N<=105
*/

class Solution{
public :
int evenlyDivides(int x){
    int x_copy=x;
    int i = 0;
    while(x){
        int digit = x%10;
        if(digit && x_copy%digit==0) i++;
        x/=10;
    }
    return i;
}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
Solution S;
cout<<S.evenlyDivides(12345)<<endl; //  answer should be 3
 
return 0 ;
}