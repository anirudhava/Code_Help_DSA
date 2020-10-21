int height(Node* root)
{
    if(root==NULL)
        return 0;
    
    if(root->left==NULL && root->right==NULL)
        return 1;
    
    int l=height(root->left);
    int r=height(root->right);
    
    return (l>r)?l+1:r+1;
}

void print_level_node(Node* root,int flag,int lvl)
{
    if(!root)
        return;
    
    if(lvl==1)
    {
        printf("%d ",root->data);
        return;
    }
    
    if(flag)
    {
         print_level_node(root->left,flag,lvl-1);
         print_level_node(root->right,flag,lvl-1);
    }
    else
    {
        print_level_node(root->right,flag,lvl-1);
        print_level_node(root->left,flag,lvl-1);
    }
}

void printSpiral(Node *root)
{
    int h=height(root);
    
    int flag=0;
    
    for(int i=1;i<=h;i++)
    {
        print_level_node(root,flag,i);
        
        flag=!flag;
    }
}

