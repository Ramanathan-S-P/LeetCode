/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *post;
int ind;
void recur(struct TreeNode* root){
    if(root!=NULL){
        recur(root->left);
        recur(root->right);
        post[++ind]=root->val;
    }
    return ;
    }
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    
  post=malloc(sizeof(int)*101);
    ind=-1;
  recur(root);
    /*for(int i=0;i<=ind;i++){
        printf("%d-",post[i]);
    }*/
    ++ind;
    
    *returnSize=ind;
     printf("%d",*returnSize);
    
    return post;




        
}
