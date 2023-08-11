#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
Given an sorted array A of size N. Find number of elements which are less than or equal to B.

NOTE: Expected Time Complexity O(log N)
*/

class Solution{
    public:
        int Solve(vi &A, int B);
};

int Solution::Solve(vi &A, int B){
        int start = 0, end = A.size();
        int mid;
        if (A[0] > B)
        {
            return 0;
        }
        if (A[end - 1] < B)
        {
            return end;
        }
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (A[mid] == B || (A[mid] <= B && A[mid] + 1 > B))
                break;
            else if( A[mid] < B)
                start = mid + 1;
            else
                end = mid - 1;
        }

        if(A[mid] == B){
            while(A[mid+1] == B){
                mid++;
            }
        }

        return mid + 1;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

auto S = new Solution();
vi A = {1,2,5,5};
auto B = 3;

cout << S->Solve(A, B);

return 0 ;
}