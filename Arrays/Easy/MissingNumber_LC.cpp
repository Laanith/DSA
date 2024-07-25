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
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


*/

class Solution
{
public:
    int missingNumberUsingSummation(vi nums)
    {   
        int n = nums.size();
        int sum = (n*(n+1))/2;
        for(int x : nums) sum-=x;
        return sum;
    }

    int missingNumberUsingXOR(vi nums){
        int n = nums.size();
        int xor1=0,xor2 = 0;
        for(int i =0; i <= n; i++) xor1^=i;
        for(auto x : nums) xor2^=x;
        return xor1^xor2;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    cout<<S->missingNumberUsingXOR({1,2,3,5,0});

    return 0;
}