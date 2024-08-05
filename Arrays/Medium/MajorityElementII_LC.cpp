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
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?




*/

//NOTE - An extension of Boyer Moore's Majority voting algorithm for N/2 elements for N/3 majority using 2 elements.
 
 
class Solution{
public :
    vi majorityElement(vi & nums){
        int cnt1 = 0, cnt2 = 0, ele1 = ima, ele2 = ima;
        int n = nums.size();
        for(int i  = 0 ; i < n; i++){
            if(cnt1 == 0 && nums[i] != ele2){cnt1 = 1; ele1 = nums[i]; }
            else if(cnt2 == 0 && nums[i] != ele1){cnt2 = 1; ele2 = nums[i]; }
            else if(nums[i]==ele1) cnt1++;
            else if (nums[i]== ele2) cnt2++;
            else { cnt1--; cnt2--; }
        }
        cnt1 = 0 ; cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        vi ans;
        int minCnt = n/3+1;
        if(cnt1>=minCnt) ans.push_back(ele1);
        if(cnt2>=minCnt) ans.push_back(ele2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,1,2,3,42,1,1,2,2,2,1,1,0,4,1,1,3,2,2,6,2,2};
pv(S->majorityElement(A));

 
return 0 ;
}