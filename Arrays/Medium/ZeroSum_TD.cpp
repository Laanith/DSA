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
Given an integer array, check if it contains a contiguous subarray having zero-sum.

Input : [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
Output: true
Explanation: The subarrays with zero-sum are

[3, 4, -7]
[4, -7, 3]
[-7, 3, 1, 3]
[3, 1, -4]
[3, 1, 3, 1, -4, -2, -2]
[3, 4, -7, 3, 1, 3, 1, -4, -2, -2]

Input : [4, -7, 1, -2, -1]
Output: false
Explanation: The subarray with zero-sum doesn't exist.

*/



/*NOTE -  solution explanation using test cases



Sure! Let's test this function on a few different test cases to understand how it works in practice. Here are some examples:

### Test Case 1
**Input:** `nums = {1, 2, -3, 4, 5}`, `n = 5`
- `sum` progresses as: `1, 3, 0, 4, 9`
- When `sum` becomes `0`, the function returns `true`.

### Test Case 2
**Input:** `nums = {1, 2, 3, 4, 5}`, `n = 5`
- `sum` progresses as: `1, 3, 6, 10, 15`
- No repeating or zero sum, so the function returns `false`.

### Test Case 3
**Input:** `nums = {-1, 1, 2, -2}`, `n = 4`
- `sum` progresses as: `-1, 0, 2, 0`
- When `sum` becomes `0` (after adding `-1 + 1`), the function returns `true`.

### Test Case 4
**Input:** `nums = {1, -1, 1, -1}`, `n = 4`
- `sum` progresses as: `1, 0, 1, 0`
- When `sum` becomes `0` (after adding `1 + -1`), the function returns `true`.

### Test Case 5
**Input:** `nums = {1, 2, -3, 3}`, `n = 4`
- `sum` progresses as: `1, 3, 0, 3`
- When `sum` becomes `0` (after adding `1 + 2 - 3`), the function returns `true`.

### Test Case 6
**Input:** `nums = {4, 2, -3, 1, 6}`, `n = 5`
- `sum` progresses as: `4, 6, 3, 4, 10`
- When `sum` becomes `4` again, the function returns `true`.

Let's run this corrected version.

Here are the results for the test cases:

1. **Input:** `nums = [1, 2, -3, 4, 5]`, `n = 5`
   - **Output:** `True`
   - **Explanation:** The subarray `[1, 2, -3]` sums to `0`.

2. **Input:** `nums = [1, 2, 3, 4, 5]`, `n = 5`
   - **Output:** `False`
   - **Explanation:** There is no subarray that sums to `0`.

3. **Input:** `nums = [-1, 1, 2, -2]`, `n = 4`
   - **Output:** `True`
   - **Explanation:** The subarray `[-1, 1]` sums to `0`.

4. **Input:** `nums = [1, -1, 1, -1]`, `n = 4`
   - **Output:** `True`
   - **Explanation:** The subarray `[1, -1]` sums to `0`.

5. **Input:** `nums = [1, 2, -3, 3]`, `n = 4`
   - **Output:** `True`
   - **Explanation:** The subarray `[1, 2, -3]` sums to `0`.

6. **Input:** `nums = [4, 2, -3, 1, 6]`, `n = 5`
   - **Output:** `True`
   - **Explanation:** The subarray `[4, 2, -3, 1]` sums to `0`.

These results confirm that the function correctly identifies if there is a subarray with a sum of zero.
*/

class Solution
{
public:
    bool hasZeroSumSubArray(vi A)
    {
        set<int> s;
        s.insert(0);
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if (s.find(sum) != s.end())
                return true;
            s.insert(sum);
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi A = {4,2,1,-3,6};
    cout<<boolalpha<<S->hasZeroSumSubArray(A)<<endl;
    vi B = {1,2,3,4,5};
    cout<<boolalpha<<S->hasZeroSumSubArray(B)<<endl;

    return 0;
}