#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
 
 
/*!SECTION : Problem Description ::
 
*/

/**!SECTION :: SOLUTION APPROACH
 *


 Approach:
To directly count the subarrays with exactly B different integers is hard but to find the count of subarrays with at most B different integers is easy.

So the idea is to find the count of subarrays with at most B different integers, let it be C(B), and the count of subarrays with at most (B - 1) different integers, let it be C(B - 1) and finally take their difference, C(B) – C(B – 1) which is the required answer.

Count of subarrays with at most B different elements can be easily calculated through the sliding window technique.
The idea is to keep expanding the right boundary of the window till the count of distinct elements in the window is less than or equal to B and when the count of distinct elements inside the window becomes more than B, start shrinking the window from the left till the count becomes less than or equal to B. Also for every expansion, keep counting the subarrays as right – left + 1 where right and left are the boundaries of the current window.

Time Complexity: O(|A|)

Space Complexity: O(|A|)
*/

class Solution{
public :

};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}