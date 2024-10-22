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
15. 3Sum

Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
 
 
class Solution{
public :
   vvi threeSumUsingHashing(vi & nums){
        set<vi> s;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            map<int,int> m;
            for(int j = i+1; j<n; j++){
                int rem= -1*(nums[i]+nums[j]);
                if(m.find(rem)!=m.end()){
                    if(m[rem]!=i && m[rem]!=j){
                        vi temp = { nums[i], nums[j], rem};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }

                m[nums[j]]=j;
            }
        }
        vvi ans(s.begin(), s.end());
        return ans;

        // O(n^2) time

   }

    vvi threeSumUsingSorting(vi & nums){
        vvi ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i>=0 && nums[i] == nums[i-1]) i++;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if (sum > 0) k--;
                else {
                    vi temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++; k--;
                    while(nums[j] == nums[j-1]) j++;
                    while(nums[k]== nums[k+1]) k--;
                }
            }
        }

        return ans;

    }


    vvi threeSumUsingSortingAndTwoPointersOptimal(vi & nums){
        vvi ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(!sum){
                    ans.push_back({nums[i], nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    r--;
                    l++;
                }
                else if(sum > 0) r--;
                else l++;
            }
        }
        return ans;
    }

};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi nums   = {-1,0,1,2,-1,-4};
pvvi(S->threeSumUsingHashing(nums));

cout<<endl;

pvvi(S->threeSumUsingSorting(nums));

cout<<endl;

pvvi(S->threeSumUsingSortingAndTwoPointersOptimal(nums));

 
return 0 ;
}