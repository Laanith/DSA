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

Problem Description



Given an array of integers, every element appears thrice except for one, which occurs once.
 Find that element that does not appear thrice.
 NOTE: Your algorithm should have a linear runtime complexity.
 Can you implement it without using extra memory?



Problem Constraints
2 <= A <= 5*106
0 <= A <= INTMAX



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer.



Example Input
Input 1:

 A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Input 2:

 A = [0, 0, 0, 1]


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 4 occurs exactly once in Input 1.
 1 occurs exactly once in Input 2.


*/

/*REVIEW -
Explanation provided by CHATGPT, an attempt by me to gain more knowledge about bit manipulation



This code snippet solves the "Single Number II" problem using bit manipulation. The problem statement is to find the number that appears exactly once in an array of integers, where all other numbers appear three times.

The key concept used here is counting the number of set bits at each position (0 to 31 bits for a 32-bit integer). The idea is to count the occurrence of bits for all numbers in the array and determine which bits have a count not divisible by 3 (the single number's bits).

Let's break down the approach:

- **Outer Loop (i):** This loop iterates through each bit position from 0 to 31 (for a 32-bit integer).

- **Inner Loop (j):** This loop iterates through each element in the input array `A`.

- **Bit Counting (cnt):** For each bit position (i), the inner loop counts the number of elements in the array where the i-th bit is set (1).

- **Determining Single Number Bits:** If the count `cnt` for a particular bit position (i) is not divisible by 3 (cnt % 3 == 1), it means that the single number has its i-th bit set.

- **Constructing the Answer (`ans`):** If the count for a bit position is not divisible by 3, it implies that this bit belongs to the single number. Therefore, we set this bit in the `ans` variable using bitwise operations (`ans = ans + (1 << i)`). This effectively constructs the single number bit by bit.

- **Final Answer (`ans`):** At the end of the outer loop (after considering all bit positions), `ans` will represent the binary representation of the single number, constructed using the bits that appear only once in the input array.

The underlying bit manipulation concepts used here are:

1. **Bitwise AND (&) and Right Shift (>>):** Used to isolate and check individual bits.
2. **Bitwise OR (|) and Left Shift (<<):** Used to construct the answer by setting individual bits in the answer based on the count of specific bits in the input array.

This approach operates in linear time O(32 * n), where n is the size of the input array, making it an efficient solution for finding the single number in an array where other numbers appear three times.


*/

class Solution{
public :
    int singleNumber(const vi &A);
};
 
 int Solution::singleNumber(const vi &A){
     int ans = 0;
     for (int i = 0; i < 32; i++){
         int cnt = 0;
         for (int j = 0; j < A.size(); j++){
             if ((A[j] >> i) & 1){
                 cnt++;
             }
         }
        if(cnt%3==1){
            ans = ans + (1 << i);
        }
     }

     return ans;
 }






int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
pint(S->singleNumber(A));

return 0;
}