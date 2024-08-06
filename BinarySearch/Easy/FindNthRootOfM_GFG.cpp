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
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input parameter and returns the nth root of m. If the root is not integer then returns -1.
 

Expected Time Complexity: O(n* log(m))
Expected Space Complexity: O(1)
 

Constraints:
1 <= n <= 30
1 <= m <= 109
*/
 
 
class Solution{
public :
    int NthRoot(int n, int m){
        int l = 1, r = m, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            unsigned long long product = 1;
            int temp = n;
            while(temp--) {
                product*=mid;
                if(product>m) break;
            }
            if(product==m) return mid;
            else if (product<m) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->NthRoot(5,32));
pint(S->NthRoot(2,9));
pint(S->NthRoot(3,9));
pint(S->NthRoot(3,27));
pint(S->NthRoot(9,512));
pint(S->NthRoot(10,1024));
pint(S->NthRoot(10,1000));
pint(S->NthRoot(3,1000));






 
return 0 ;
}