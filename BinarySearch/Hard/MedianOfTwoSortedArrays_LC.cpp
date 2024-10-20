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
4. Median of Two Sorted Arrays
Solved
Hard
Topics
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
 
 
class Solution{
public :
    double findMedianOfTwoSortedArrays(vi & nums1, vi & nums2){
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianOfTwoSortedArrays(nums2,nums1);
        int n = n1 + n2;
        int half_size = (n + 1)/2;
        int l = 0, r = n1;
        while(l <= r){
            int mid1 = l + (r-l)/2;
            int mid2 = half_size - mid1;
            int l1 = imi, l2 = imi, r1 = ima, r2 = ima;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1){
                if(n%2) return max(l1,l2);
                else return ((double)(max(l1,l2) + min(r1,r2)))/2;
            }
            else if(l1>r2) r = mid1-1;
            else l = mid1+1;
        }
        return -1;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,3};
vi B = {2};
cout<<S->findMedianOfTwoSortedArrays(A,B)<<endl;
A = {1,3,5};
B = {4,5, 6};
cout<<S->findMedianOfTwoSortedArrays(A,B)<<endl;


 
return 0 ;
}