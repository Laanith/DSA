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
void pv(vi A){for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}cout << endl;}



 
 
/*!SECTION : Problem Description ::
First negative in every window of size k
Difficulty: MediumAccuracy: 48.61%Submissions: 167K+Points: 4
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window {-8, 2}: First negative integer is -8.
Window {2, 3}: No negative integers, output is 0.
Window {3, -6}: First negative integer is -6.
Window {-6, 10}: First negative integer is -6.
Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
Explanation:
Window {12, -1, -7}: First negative integer is -1.
Window {-1, -7, 8}: First negative integer is -1.
Window {-7, 8, -15}: First negative integer is -7.
Window {8, -15, 30}: First negative integer is -15.
Window {-15, 30, 16}: First negative integer is -15.
Window {30, 16, 28}: No negative integers, output is 0.
Input: arr[] = [12, 1, 3, 5] , k = 3
Output: [0, 0] 
Explanation:
Window {12, 1, 3}: No negative integers, output is 0.
Window {1, 3, 5}: No negative integers, output is 0.

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
1 <= k <= arr.size()


*/
 
 
class Solution{
public :
    vi firstNegativeInteger(vi & arr, int k){
        deque<int> neg;
        vi res;

        for(int i  = 0; i < k; i++){
            if(arr[i]<0) neg.push_back(i);
        }

        for(int i = k; i < arr.size(); i++){
            if(!neg.empty()){
                res.push_back(arr[neg.front()]);
            }
            else res.push_back(0);

            if(!neg.empty() && neg.front() <= i-k){
                neg.pop_front();
            }

            if(arr[i]<0) neg.push_back(i);
        }

        if(!neg.empty()) res.push_back(arr[neg.front()]);
        else res.push_back(0);
        pv(res);
        return res;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {12, -1, -7, 8, -15, 30, 16, 28};
pv(S->firstNegativeInteger(A,3));

 
return 0 ;
}