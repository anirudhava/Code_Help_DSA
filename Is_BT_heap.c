bool compare_child(Node* root) 
{
    if(root->right)
    {
        if(root->data > root->right->data && root->data > root->left->data)
            return true;
        else
            return false;
    }
    else
    {
        if(root->data > root->left->data)
            return true;
        else
            return false;
    }
}

bool isHeap(Node * root)
{
    if(root==NULL)
        return true;
    
    if(root->left==NULL && root->right==NULL)
        return true;
    
    if(root->left==NULL)//&& root->right!=NULL obvious...... cannot be a complete BT
        return false;
        
    if(compare_child(root) && isHeap(root->left) && isHeap(root->right))// parental dominance and recursion
        return true;
    else
        return false;
    
}
