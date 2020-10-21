/*
 checking each of the node->data > node->left->data && node->data < node->right->data is a wrong approach
 there might be a node somewhere which satisfies this condition but node->right->data should be at the root->right because it is very large
*/

/* To chaeck whether a given binary tree is bst or not
   approach 1:
	-check if all the nodes on the left are lesser than the current node's data
	-check if all the nodes on the right are greater than the current node's data
	
	is_bst(root){
		if(root==NULL)
			return true;
	if(is_left_lesser(root->left,root->data) && is_right_greater(root->right,root->data) && is_bst(root->left) && is_bst(root->right))
			return true;

	else
		return false;
	}

	bool is_left_lesser(Node* r,int val)
	{
		if(r==NULL)
			return true;
		if(r->data < val && is_left_lesser(r->left,val) && is_left_lesser(r->right,val))
			return true;
		else
			return false;
	}

	bool is_right_greater(Node* r,int val)
	{
		if(r==NULL)
			return true;
		if(r->data > val && is_right_greater(r->left,val) && is_right_greater(r->right,val))
			return true;
		else
			return false;
	}

	But this approch is of O(n^2) and has alot of comparisons
*/

//O(n) solution: giving each of the node a range of values ,if all node->data falls between that range then it is bst

bool is_BST_r(Node* root,int min,int max)
{
    if(root==NULL)
        return true;
    
    if(root->data > min && root->data < max && is_BST_r(root->left,min,root->data) && is_BST_r(root->right,root->data,max))
        return true;
    
    return false;
}
bool isBST(Node* root) {
    
    return is_BST_r(root,INT_MIN,INT_MAX);
}

