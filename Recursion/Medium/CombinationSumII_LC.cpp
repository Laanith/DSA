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
40. Combination Sum II
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/
 
 
class Solution{
private:
    void func(int ind, vi v, vi & arr, int target, set<vi> & ans){
        // cout<<ind<< " " <<target<<endl;
        if(ind==arr.size()) return;
        if(target == 0){ ans.insert(v); return;}
        func(ind+1, v, arr, target, ans);
        if(arr[ind] <= target){ v.push_back(arr[ind]);  func(ind+1, v, arr, target - arr[ind], ans);}
        return;
    }

    void backtrack(int ind, vi & v, vi & arr, int target, set<vi> & ans){
        if(target==0){ans.insert(v); return;}
        for(int i=ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            v.push_back(arr[i]);
            backtrack(ind+1,v,arr,target - arr[i],ans);
            v.pop_back();
        }
        return;
    }

public :
    vvi combinationSum2(vi & candidates, int target){
        set<vi> ans;
        func(0, {}, candidates, target, ans);
        return vvi(ans.begin(), ans.end());
    }

    vvi combinationSum2Optimal(vi & candidates, int target){
        vi dum = candidates;
        set<vi> ans;
        vi temp;
        sort(dum.begin(), dum.end());
        backtrack(0, temp, dum, target, ans);
        return vvi(ans.begin(), ans.end());
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi nums = {10,1,2,7,6,1,5};
pvvi(S->combinationSum2Optimal(nums, 8));
nums = {2,5,2,1,2};
pvvi(S->combinationSum2Optimal(nums, 5));


 
return 0 ;
}