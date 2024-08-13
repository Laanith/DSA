#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define PMINUS cout << -1 << endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int, int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A)
{
    for (auto x : A)
        cout << x << ' ';
    cout << endl;
}
void pint(int A) { cout << endl
                        << A << endl; }
void pp(pair<int, int> p) { cout << p.first << ' ' << p.second << endl; }
void pvvi(vvi A)
{
    for (auto v : A)
    {
        pv(v);
    }
    cout << endl;
}

/*!SECTION : Problem Description ::
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/

class Solution
{
public:
    vvi FourSumBruteForce(vi &nums, int target)
    {
        set<vi> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        int sum = nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target)
                        {
                            vi temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }

        vvi ans(s.begin(), s.end());
        return ans;
    }

    vvi FourSumBetter(vi &nums, int target)
    {
        set<vi> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                map<int, int> nti;
                for (int k = j + 1; k < n; k++)
                {
                    int rem = target - (nums[i] + nums[j] + nums[k]);
                    if (nti.find(rem) != nti.end())
                    {
                        if (nti[rem] != i && nti[rem] != j && nti[rem] != k)
                        {
                            vi temp = {nums[i], nums[j], nums[k], rem};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                    nti[nums[k]] = k;
                }
            }
        }

        vvi ans(s.begin(), s.end());
        return ans;
    }

    vvi FourSumOptimal(vi &nums, int target)
    {
        int n = nums.size();
        vvi ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j!=(i+1) && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) k++;
                    else if (sum > target) l--;
                    else {
                        vi temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k<l && nums[k] == nums[k - 1])
                            k++;
                        while ( k<l&& nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return ans;
    }
};





//NOTE -  This solution works for leetcode.
// idk what static cast does here.
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                if(j!=(i+1) && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                    if(sum<target) k++;
                    else if(sum>target) l--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++; l--;
                        while(k<l && nums[k]==nums[k-1] ) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi nums = {1, 0, -1, 0, -2, 2};

    pvvi(S->FourSumBruteForce(nums, 0));

    cout << endl;
    pvvi(S->FourSumBetter(nums, 0));

    cout << endl;
    pvvi(S->FourSumOptimal(nums, 0));

    return 0;
}