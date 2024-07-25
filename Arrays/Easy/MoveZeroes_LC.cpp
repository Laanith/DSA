#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define PMINUS cout << -1 << endl
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A)
{
    cout << endl;
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
}

/*!SECTION : Problem Description ::
*/


/*NOTE - TWO POINTERS ARE FUCKING SHIT.*/

class Solution
{
public:
    void moveZeroes(vi &nums)
    {
        int left = 0;
        for(int right = 0; right<nums.size(); right++){
            if(nums[right]!=0){
                swap(nums[right], nums[left]);
                left++;
            }
        }

        return;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution S;
    vi A = {0, 1, 2, 0, 3, 0, 0};
    S.moveZeroes(A);
    pv(A);
    return 0;
}