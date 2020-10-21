void swap(Node* root)
{
    Node* temp;
    
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    
}

void mirror(Node* root) 
{
    if(root!=NULL)
    {
        swap(root);
        
        mirror(root->left);
        
        mirror(root->right);
    }
}

//draw fig 
