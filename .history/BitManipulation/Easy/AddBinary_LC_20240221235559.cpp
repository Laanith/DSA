#include <bits/stdc++.h>
#define ll long long
#include <algorithm>
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
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
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution
{
public:
    string solve(string A, string B);
};

string Solution::solve(string A, string B)
{
    string result = "";
    int carry = 0;
    int i = A.length() - 1;
    int j = B.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digitA = (i >= 0) ? A[i--] - '0' : 0;
        int digitB = (j >= 0) ? B[j--] - '0' : 0;

        int sum = digitA + digitB + carry;
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();

    return 0;
}