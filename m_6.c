void levelOrder(Node*root)
{
    Node* queue[3000];
    
    int f=0;
    int r=0;
    
    queue[r]=root;
    r++;
    
    Node* t;
    
    int k=0;
    
    while(f!=r)
    {
        
        t=queue[f];
        f++;
        
        printf("%d ",t->data);
        
            if(t->left)
                queue[r++]=t->left;
            if(t->right)
                queue[r++]=t->right;
    }
}

