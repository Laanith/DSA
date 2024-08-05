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
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times. 

*/
 
 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,  n = nums.size(), r = nums.size()-1, mid;
        vector<int> &arr = nums;
        int ans = -1;
        int iteration = 1;
        while(l<=r){
            mid = l + ( r - l )/2;
            cout<<"iteration : "<<iteration<<endl;
            cout<<"l : "<<l<<endl;
            cout<<"r : "<<r<<endl;
            cout<<"mid : "<<mid<<endl<<endl;
            if(arr[mid-1]>arr[mid] && arr[mid+1]>arr[mid]){ return arr[mid];}
            if(arr[l]<arr[mid]){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

            iteration++;
        }

        return ans;
    }
};
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {4,5,6,7,0,1,2};
pv(A);
pint(S->findMin(A));
 
return 0 ;
}