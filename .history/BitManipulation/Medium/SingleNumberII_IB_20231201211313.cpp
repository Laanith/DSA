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



Given an array of integers, every element appears thrice except for one, which occurs once.
 Find that element that does not appear thrice.
 NOTE: Your algorithm should have a linear runtime complexity.
 Can you implement it without using extra memory?



Problem Constraints
2 <= A <= 5*106
0 <= A <= INTMAX



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer.



Example Input
Input 1:

 A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Input 2:

 A = [0, 0, 0, 1]


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 4 occurs exactly once in Input 1.
 1 occurs exactly once in Input 2.


*/

class Solution{
public :
    int singleNumber(const vi &A);
};
 
 int Solution::singleNumber(const vi &A){
     int ans = 0;
     for (int i = 0; i < 32; i++){
         int cnt = 0;
         for (int j = 0; j < A.size(); j++){
             if ((A[j] >> i) & 1){
                 cnt++;
             }
         }
        if(cnt%3==1){
            ans = ans + (1 << i);
        }
     }

     return ans;
 }






int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
pint(S->singleNumber(A));

return 0;
}