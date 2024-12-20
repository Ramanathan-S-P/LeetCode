/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void reversal (struct TreeNode** bfs,int turn,int size){
    struct TreeNode* *bfs1=malloc(sizeof(struct TreeNode*)*(2*size));
    int i=0;
    int j=size-1;

    if(turn){
        
    
    while (i<j){
        bfs[i]->val=bfs[i]->val+bfs[j]->val;
        bfs[j]->val=bfs[i]->val-bfs[j]->val;
        bfs[i]->val=bfs[i]->val-bfs[j]->val;
        i++;
        j--;
    }
}
    int ind=-1;
    if(bfs[0]->left!=NULL){
        
    
    for(int i=0;i<size;i++){
        bfs1[++ind]=bfs[i]->left;
        bfs1[++ind]=bfs[i]->right;
    }
    reversal(bfs1,!turn,2*size);
    
    }
    
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    int size=1;
    struct TreeNode* *bfs=malloc(sizeof(struct TreeNode*)*(2*size));
    
    bfs[0]=root->left;
    bfs[1]=root->right;
    int turn=0;
    reversal(bfs,!turn,2*size);

    return root;
}
