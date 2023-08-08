#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
 

 
using namespace std;



class Solution {
    public :
        int FindDuplicateInAnArray(const vector<int> A);
};

int Solution::FindDuplicateInAnArray(const vector<int> A)
{
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] == A[i + 1])
                return A[i];
        }

        return -1;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

vector<int> K = {0, 1, 6, 2, 3, 4, 5, 5, 7};
auto m = new Solution;
cout << m->FindDuplicateInAnArray(K);

return 0 ;
}