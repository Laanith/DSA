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
 You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5
*/

/*NOTE -  Solution Approach

We can try to remove the common factors of A and B from A by finding the greatest common divisor (gcd) of A and B and dividing A with that gcd.

Mathematically, A = A / gcd(A, B) —— STEP1
Now, we repeat STEP1 till we get gcd(A, B) = 1.
Atlast, we return X = A

How does this work ?

On doing prime factorisation of A and B, we get :

A = p1x1 . p2x2 . … . pkxk
B = q1y1 . q2y2 . … . qlyl
Where pi ; i = 1, 2, …, k are prime factors of A and xi ; i = 1, 2, …, k are their respective powers
Similarly, qj ; i = 1, 2, …, l are prime factors of B and yi ; j = 1, 2, …, l are their respective powers

Let ri ; i = 1, 2, …, m be the common factors of A and B. By repeating STEP1, we are reducing the respective powers of ri by at least one, each time (Proof of this is left to the reader). Therefore, we reach a point where powers of ri become zero and product of the rest prime-powers in A form the largest divisor of A that is co-prime with B.*/

class Solution{
public :
    int cpFact(int A, int B);
};

int Solution::cpFact(int A,int B){
    int num = __gcd(A, B);
    if(num==1)
        return A;
    return cpFact(A / num, B);
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->cpFact(30, 12));

return 0;
}