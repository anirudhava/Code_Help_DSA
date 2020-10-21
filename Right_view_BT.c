int height(Node*root)
{
    if(root==NULL)
        return -1;
    
    if(root->left==NULL && root->right==NULL)
        return 0;
    
    int l=height(root->left);
    int r=height(root->right);
    
    return (l>r)?l+1:r+1;
}

void print_right_view(Node* root,int* visited,int level)
{
    if(root==NULL)
        return;
    
    if(visited[level]==0)
    {
        visited[level]=1;
        printf("%d ",root->data);
    }
    
    print_right_view(root->right,visited,level+1);
    print_right_view(root->left,visited,level+1);
}

void rightView(Node *root)
{
   int h=height(root);
   
   int visited[h+1];
   
   for(int i=0;i<=h;i++)
   {
       visited[i]=0;
   }
   
   print_right_view(root,visited,0);
}

