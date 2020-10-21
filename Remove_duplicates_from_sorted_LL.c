Node *removeDuplicates(Node *root)
{
    if(!root)
        return root;
    
    Node* p;
    Node* q;
    
    p=root;
    q=root->next;
    
    while(q)
    {
        if(p->data == q->data)//del
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else//simply traverse
        {
            p=q;
            q=q->next;
        }
    }
    
    return root;
}
