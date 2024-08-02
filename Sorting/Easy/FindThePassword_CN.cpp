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
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Spider Man needs to retrieve a secret file stored in the computer of Dr. Octavius. He finds a clue to the password, but since he is running short on time, he asks you for help. Following is the clue provided-

Given ‘N’ DIGITS valued from 0 to 9, the password is the minimum possible sum of two numbers formed by using all the DIGITS only once.

For example - For DIGITS = [4, 3, 2, 7, 1, 9], the minimum sum is 385 which is obtained by adding numbers 137 and 249.

Can you help Spider Man find the password?

Note - The number of DIGITS is always greater than or equal to 2. Hence, the answer will always exist.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
2 <= N <= 5000
0 <= DIGITS[i] <= 9

Where ‘N’ is the number of digits

Time Limit: 1sec
Sample Input 1 :
2
4
1 2 9 8
3
1 1 0
Sample Output 1 :
47
2
Sample Output 1 Explanation:
For the first test case, the password  is 47 which is the minimum sum obtained by adding numbers 18 and 29.

For the second test case, the password is 12 which is the minimum sum obtained by adding numbers 01 and 1.
Sample Input 2 :
1
2
2 8 
Sample Output 2 :
10
Spider Man needs to retrieve a secret file stored in the computer of Dr. Octavius. He finds a clue to the password, but since he is running short on time, he asks you for help. Following is the clue provided-

Given ‘N’ DIGITS valued from 0 to 9, the password is the minimum possible sum of two numbers formed by using all the DIGITS only once.

For example - For DIGITS = [4, 3, 2, 7, 1, 9], the minimum sum is 385 which is obtained by adding numbers 137 and 249.

Can you help Spider Man find the password?

Note - The number of DIGITS is always greater than or equal to 2. Hence, the answer will always exist.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
2 <= N <= 5000
0 <= DIGITS[i] <= 9

Where ‘N’ is the number of digits

Time Limit: 1sec
Sample Input 1 :
2
4
1 2 9 8
3
1 1 0
Sample Output 1 :
47
2
Sample Output 1 Explanation:
For the first test case, the password  is 47 which is the minimum sum obtained by adding numbers 18 and 29.

For the second test case, the password is 12 which is the minimum sum obtained by adding numbers 01 and 1.
Sample Input 2 :
1
2
2 8 
Sample Output 2 :
10

*/
 
 
class Solution{
public :
    vector<int> findPassword(vector<int> &digits, int n)
{	
	// int n = digits.size();
	sort(digits.begin(), digits.end());
	int n1=0,n2=0;
	for(int i = 0 ; i < n; i++ ){
		if(i%2){n2=(n2*10+digits[i]);}
		else n1=(n1*10+digits[i]);
	}
	int ans = n1 + n2;
    if(ans==0) return {0};
    vi ansVec;
    while(ans){
        ansVec.push_back(ans%10);
        ans/=10;
    }

    reverse(ansVec.begin(), ansVec.end());

    return ansVec;

	// Write your code here
	// Return sum of numbers in a vector without leading zeroes
	// Ex- For sum 0456, return vector {4, 5, 6}
} 
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {4,3,2,7,1,9};
pv(S->findPassword(A,6));
A = {1,2,9,8};
pv(S->findPassword(A,4));
A = {1,1,0};
pv(S->findPassword(A,3));


vi r = {3};
for(auto x : r) r.push_back(x);
pv(r);
 
return 0 ;
}