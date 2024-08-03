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
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
 
 
class Solution{
public :
    bool search(vi & nums, int target){
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        bool found = false;
        vi &arr = nums;
        while(l<=r){
            mid = l + ( r - l)/2;
            if(nums[mid]==target){
                found = true;
                break;
            }

            else if ( arr[ l] == arr[mid] && arr[mid] == arr[r]){ l++; r--; }
            else if ( arr[l]< arr[mid]){
                if(arr[l]<target && target < arr[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else {
                if(arr[mid]<target && target < arr[r]) l = mid + 1;
                else r = mid-1;

            }
        }

        return found;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {2,5,6,0,0,1,2};
cout<<boolalpha<<S->search(A,0)<<endl;
cout<<boolalpha<<S->search(A,3)<<endl;


 
return 0 ;
}