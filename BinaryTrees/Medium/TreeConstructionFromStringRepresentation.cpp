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

//NOTE - Template code to construct a tree from string representation.

*/
 
#include <iostream>
#include <string>

// Define the structure of the tree node
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize the node
    TreeNode(char value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to build the tree recursively
TreeNode* buildTree(const std::string& s, int& index) {
    // Base case: If the index exceeds the string length, return nullptr
    if (index >= s.length()) {
        return nullptr;
    }

    // Read the current character (which is the node value)
    char nodeValue = s[index];
    
    // If the node is a dot, it's null, return nullptr
    if (nodeValue == '.') {
        return nullptr;
    }

    // Create a new TreeNode for the current value
    TreeNode* node = new TreeNode(nodeValue);
    
    // Move the index to the next character after '('
    index += 2;  // Skip over "n("
    
    // Recursively build the left child
    node->left = buildTree(s, index);
    
    // Move the index to the next character after the left child
    index++;  // Skip over the space or ')'
    
    // Recursively build the right child
    node->right = buildTree(s, index);
    
    // Move the index to the next character after the right child
    index++;  // Skip over the ')'
    
    return node;
}

// Helper function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (!root){cout<<". "; return;}
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Example input
    std::string input = "b(.q(k(.r(e(..).)).))";
    
    // Starting index for parsing
    int index = 0;
    
    // Build the tree from the input string
    TreeNode* root = buildTree(input, index);
    
    // Print the tree using in-order traversal
    std::cout << "In-order traversal of the constructed tree: ";
    printTree(root);
    std::cout << std::endl;
    
    return 0;
}
