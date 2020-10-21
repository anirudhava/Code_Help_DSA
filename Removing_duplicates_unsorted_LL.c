Node *removeDuplicates(Node *root)
{
    if(!root)
        return root;
        
    int f[1000001]={0};
    
    Node*p;
    p=root;
    
    Node*prev;
    prev=NULL;
    
    while(p)
    {
        if(f[p->data]==0)//then inc count and traverse
        {
            f[p->data]+=1;
            prev=p;
            p=p->next;
        }
        else//del
        {
            prev->next=p->next;
            free(p);
            p=prev->next;
        }
    }
    
    return root;
}

