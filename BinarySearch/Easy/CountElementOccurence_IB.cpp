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
Given a sorted array of integers, find the number of occurrences of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return 0

**Example : **

Given [5, 7, 7, 8, 8, 10] and target value 8,

return 2.

PROBLEM APPROACH :

For complete solution, look at the hint.
*/
 
 
class Solution{
public :
 int findCount(const vector<int> &A, int B) {
    
    if(A.size() == 1 && A[0] != B) return 0;
    if(A.size() == 1 && A[0] == B) return 1;
    int start, end , mid , count;
    start = 0 ; end = A.size()-1;
    count = 0;
    while(start <= end){
        mid = start + (end - start)/2 ;
        if(A[mid] == B){ count++; break; }
        else if( A[mid] < B){
                start = mid +1;
            }
        else {
                end = mid - 1;
            }
    }
    
    
    if(count){
        start = mid; end = mid;
        while(start > 0){
            if(A[--start] == B){count++;}
            else break;
        }
        while(end < A.size()-1){
            if(A[++end] == B){count++;}
            else break;
        }
    }
    
    return count;
}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->findCount({1,2,3,3,3,3,3,4,5}, 3);
 
 
return 0 ;
}