#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::
 Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

// Wrote the code for inorder traversal to check the correctness of BST built.
*/
class treenode{
    public :
        int val;
        treenode *left;
        treenode *right;
        treenode(int x) : val(x) , left(NULL), right(NULL){};
};

treenode *insertBST(treenode *root, int val)
{
        if (root == NULL)
        {
            return new treenode(val);
        }

        if (val < root->val)
        {
            root->left = insertBST(root->left, val);
        }
        else
        {
            root->right = insertBST(root->right, val);
        }

        return root;
}

treenode *buildBST(vector<int> &nums)
{
        treenode *root = NULL;

        for (int num : nums)
        {
            root = insertBST(root, num);
        }

        return root;
}

treenode *buildBalancedBST(vector<int> &nums, int start, int end)
{
        if (start > end)
        {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        treenode *root = new treenode(nums[mid]);

        root->left = buildBalancedBST(nums, start, mid - 1);
        root->right = buildBalancedBST(nums, mid + 1, end);

        return root;
}

void inorderTraversal(treenode *root)
{
        if (root == NULL)
        {
            return;
        }

        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
}

class Solution{
public :
    int MaxDepth(treenode *A);
};
 
int Solution::MaxDepth(treenode *A){
    if(!A)
            return 0;
    int lh = MaxDepth(A->left);
    int rh = MaxDepth(A->right);
    return 1 + max(lh, rh);
}
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vi x = {1,2,3,4,5,6,7};
auto k = buildBST(x);
auto l = buildBalancedBST(x, 0, x.size() - 1);
cout << S->MaxDepth(k) << endl;
cout << S->MaxDepth(l) << endl;
cout << "Inorder traversal : ";
inorderTraversal(k);

return 0 ;
}