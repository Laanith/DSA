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
A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].


Constraints:

1 <= heights.length <= 100
1 <= heights[i] <= 100

*/

/*NOTE -
Approaches :

1. The easiest way to solve the problem is to sort the array using inbuilt std::sort method and then use linear search to find the unequal elements and return their count. O(nlogn + n)

2. Another approach is to use bubble sort and count the number of swaps that are made. (This is inappropriate for the solution. I tried and tested it but this idea striked my mind too,. )
[O(n^2)]

3. The correct solution is to use count sort, keeping in mind the constraints.
--> Space compelxity : O(100) = O(1)
--> Time complexity : O(n)

*/

class Solution
{
public:
    int heightChecker(vi &heights)
    {
        int freq[101] = {0};
        for (int x : heights)
            freq[x]++;
        int cnt = 0, ans = 0;
        for (int x = 1; x <= 100; x++)
        {
            int f = freq[x];
            for (int i = cnt; i < cnt + f; i++)
                ans += heights[i] != x;
            cnt += f;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi A = {1, 4, 3, 4};
    cout << S->heightChecker(A) << endl;

    return 0;
}