#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
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
Given an integer n, find the square root of n. If n is not a perfect square, then return floor(√n).
Note: Floor value of an integer n is the greatest number less than or equal to n.

Examples:

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 107
*/
 
 
class Solution{
public :
   long long int floorSqrt(long long int n){
        long long int l = 1, r = n, mid;
        int ans = -1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(mid*mid==n) {return mid; break;}
            else if (mid*mid < n)
             {
                ans = mid;
                l = mid+1;
             }
            else r = mid-1;
        }
        return ans;
   }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
pv(A);
vi ans;
for(auto x : A) ans.push_back(S->floorSqrt(x));
pv(ans);



 
return 0 ;
}