#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node* right;
    struct Node* left;
};

struct Node* create_Node(struct Node* node,int k)
{
    node=(struct Node*)malloc(sizeof(struct Node));
    node->right=node->left=NULL;
    node->key=k;
    return node;
}

struct Node* insert_BST(struct Node* root,int x)
{
    struct Node* temp;
    temp=create_Node(temp,x);
    
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    
    struct Node* prev;
    struct Node* pres;
    
    prev=NULL;
    pres=root;
    
    while(pres)
    {
        prev=pres;
        
        if(x < pres->key)
        {
            pres=pres->left;
        }
        else
        {
            pres=pres->right;
        }
    }
    
    if(x < prev->key)
    {
        prev->left=temp;
    }
    else
    {
        prev->right=temp;   
    }
    
    return root;
}

void post_order(struct Node* root)
{
    if(root)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->key);
    }
}

void convert_pre_post(int* arr,int n)
{
    struct Node* root;
    root=NULL;
    
    for(int i=0;i<n;i++)
    {
        root=insert_BST(root,arr[i]);
    }
    
    post_order(root);
    printf("\n");
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    int* arr;
	    arr=(int*)malloc(sizeof(int)*n);
	    
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    convert_pre_post(arr,n);
	}
	return 0;
}
