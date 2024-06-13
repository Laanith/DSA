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
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/

/*NOTE -
- Trivial approach uses O(m+n) space and O(m+n) time. The merging part in Merge sort algorithm.
*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    vi A = {1,3,5,0,0,0};
    vi B = {2,4,6};
    S->merge(A,3,B,3);
    pv(A);

    return 0;
}