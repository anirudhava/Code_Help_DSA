int height(Node* root)
{
    if(root==NULL)
        return -1;
    
    if(root->left==NULL && root->right==NULL)
    {
        return 0;
    }
    
    int l=height(root->left);
    int r=height(root->right);
    
    return (l>r)?l+1:r+1;
}

void print_left_view(Node* root,int* v,int level)
{
    if(root==NULL)
    {
        return;
    }
    
    if(v[level]==0)
    {
        v[level]=1;
        printf("%d ",root->data);
    }
    
    print_left_view(root->left,v,level+1);
    print_left_view(root->right,v,level+1);
}

void leftView(Node *root)
{
    int h=height(root);
    
    int visited[h+1];
    
    for(int i=0;i<=h;i++)
    {
        visited[i]=0;
    }
    
    print_left_view(root,visited,0);
}

