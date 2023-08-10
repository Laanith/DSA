#include<bits/stdc++.h>
#define ll long long
#include<map>
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl

/*!SECTION : Problem Description ::
You are given an integer array A.

You have to find the number of occurrences of each number.

Return an array containing only the occurrences with the smallest value's occurrence first.

For example, A = [4, 3, 3], you have to return an array [2, 1], where 2 is the number of occurrences for element 3,
and 1 is the number of occurrences for element 4. But, 2 comes first because 3 is smaller than 4.
*/

using namespace std;

class Solution {
    public :
        vi findOccurrenes(vi &A);
};

vi Solution::findOccurrenes(vi &A){
        vi B;
        sort(A.begin(), A.end());
        map<int,int> m;
        for(auto x : A){
            m[x]++;
        }
        for(auto p : m){
            B.push_back(p.second);
        }

        return B;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

vi X = {1, 2, 3};
vi Y = {3, 4, 3};

auto m = new Solution();
for(auto p : m->findOccurrenes(X)){
            cout << p << " ";
}
cout << endl;
for (auto q : m->findOccurrenes(Y))
{
            cout << q << " ";
}

return 0 ;
}