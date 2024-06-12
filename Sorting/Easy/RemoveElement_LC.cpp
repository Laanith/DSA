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
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/


/*NOTE - My hope is that a variant of count sort could solve the problem. But that did not work. This is a two pointer problem*/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> counter(51);
        for (auto x : nums)
        {
            counter[x]++;
        }
        int returnValue = nums.size() - counter[val];
        int j = 0;
        for (int i = 0; i <= 50; i++)
        {
            if (i == val)
                continue;
            while (counter[i] > 0)
            {
                nums[j] = i;
                j++;
                counter[i]--;
            }
        }

        return returnValue;
    }
};

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
int val = 2;
cout<<S->removeElement(nums,val);
pv(nums);

return 0;
}