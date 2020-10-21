Node* sortedMerge(Node* p,   Node* q)
{
    Node* s;
    Node* strt;
    
    if(p==NULL)
        return q;
    if(q==NULL)
        return p;
    
    if(p->data < q->data)
    {
        s=strt=p;
        p=p->next;
    }
    else
    {
        s=strt=q;
        q=q->next;
    }
    
    while(p && q)
    {
        if(p->data < q->data)
        {
            s->next=p;
            s=p;
            p=p->next;
        }
        else
        {
            s->next=q;
            s=q;
            q=q->next;
        }
    }
    
    if(p==NULL)
    {
        s->next=q;
    }
    else
    {
        s->next=p;
    }
    
    return strt;
}

