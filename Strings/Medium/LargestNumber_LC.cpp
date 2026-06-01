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
void pv(vi A, int width = 4){for(auto x : A) cout << setw(width) << right << x; cout << endl; }
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}cout << endl;}

/*!SECTION : Problem Description ::
179. Largest Number
Medium

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/


// Why am I such an asshole !!!! 🏃‍♂️🏃‍♂️
bool lexCompare(const int &a, const int &b)
{
    // Compare by concatenating in both orders: if a+b > b+a, then a should come before b
    // This correctly handles cases like 3 vs 30: "330" > "303", so 3 comes first
    // and cases like 9 vs 5: "95" > "59", so 9 comes first
    string aString = to_string(a);
    string bString = to_string(b);
    return aString + bString > bString + aString;
}

class Solution{
public :
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), lexCompare);
        string ans = "";
        for (auto num : nums)
            ans += to_string(num);
        // If the highest number is '0', the entire number is 0 (handles cases like [0,0])
        if (!ans.empty() && ans[0] == '0') return string("0");
        return ans;
    }
};
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi nums = {3,30,34,5,9};
cout << S->largestNumber(nums) << endl; // ans is 9534330
 
return 0 ;
}