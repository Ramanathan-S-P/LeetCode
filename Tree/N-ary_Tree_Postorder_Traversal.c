/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *post;
int ind;
void recur(struct Node* root){
    if(root!=NULL){
        for(int i=0;i<root->numChildren;i++){
            recur(root->children[i]);
        }
        post[++ind]=root->val;
    }
    return ;
    }
int* postorder(struct Node* root, int* returnSize) {
post=malloc(sizeof(int)*100001);
    ind=-1;
  recur(root);
    /*for(int i=0;i<=ind;i++){
        printf("%d-",post[i]);
    }*/
    ++ind;
    
    *returnSize=ind;
     //printf("%d",*returnSize);
    
    return post;

}