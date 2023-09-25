#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define si stack<int>
#define qi queue<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
Given an array of integers A and an integer B.

Find the total number of subarrays having exactly B odd numbers.

Input 1:
 A = [4, 3, 2, 3, 4]
 B = 2
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 3


Output 1:

 4
Output 2:

 1
*/



class Solution{
    public :
        int solve(vi A, int B);
};

int Solution::solve(vi A, int B){
    int n = A.size();
    int count = 0;
    int prefix[n+1];
    memset(prefix, 0, sizeof(prefix));
    int odd = 0;
    // traverse in the array
    for (int i = 0; i < n; i++)
    {

      prefix[odd]++;
      // if array element is odd
      if (A[i] & 1)
          odd++;

      // when number of odd elements>=M
      if (odd >= B)
          count += prefix[odd - B];
    }
    return count;
    

}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi a = {5,6,7,8,9};
cout<<S->solve(a,3);
return 0 ;
}