// Question:- https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem

/* Approach:- 
1. Height of binary tree is the height of root node plus maximum of height of left subtree and right subtree.
2. So, we will calculate height of left and right subtree through recursion and add one in maximum of that subtree.
*/

int heightOfBinaryTree(node* root)
{
    //Height of Null Subtree is Zero
    if(root == NULL)
        return 0;
        
   return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}