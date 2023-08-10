#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl

/*!SECTION : Problem Description ::
There is given an integer array A of size N denoting the heights of N trees.

Lumberjack Ojas needs to chop down B metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Ojas is only allowed to cut a single row of trees.

Ojas's machine works as follows: Ojas sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Ojas then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Ojas raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Ojas will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Ojas is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade as high as possible. Help Ojas find the maximum integer height of the sawblade that still allows him to cut off at least B metres of wood.

NOTE:

The sum of all heights will exceed B, thus Ojas will always be able to obtain the required amount of wood.
*/
using namespace std;

bool check(int mid , vi &A, int B){
    int sum = 0;
    for (int i = 0; i < A.size(); i++){
        if(A[i] > mid){
            sum += (A[i] - mid);
        }
    }

    return sum >= B;
}



class Solution{
    public :
        int solve(vi A, int B);
};

int Solution::solve(vi A,int B){
        int lo = 0, hi = 1e6, ans = 0; 
        while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid, A,B)){
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
        }

        return ans;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

auto k = new Solution();
vi A = {4,42,40,26,46};
auto B = 20;
cout << k->solve(A, B);
return 0;
}