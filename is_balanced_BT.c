/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree
*/

int height_tree(Node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->right==NULL && root->left==NULL)
    {
        return 0;
    }
    
    int l=height_tree(root->left);
    int r=height_tree(root->right);
    
    return l>r?l+1:r+1;
}

int absol(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

bool isBalanced(Node *root)//O(n^2)
{
    if(root==NULL)
    {
        return true;
    }
    
    int l=height_tree(root->left);
    int r=height_tree(root->right);
    
    if(isBalanced(root->left) && isBalanced(root->right) && absol(l-r)<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBalanced(Node *root)//O(n)
{
    if(!root)
        return true;
    
    if(!root->left && !root->right)
        return true;
    
    if(root->left && !root->right)
    {
        if(root->left->right || root->left->left)
        {
            return false;
        }
        else
            return isBalanced(root->left);
    }
    
    if(!root->left && root->right)
    {
        if(root->right->left || root->right->right)
        {
            return false;
        }
        else
            return isBalanced(root->right);
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

