/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool print(struct TreeNode*s, struct TreeNode* t){
    /*if(s&&t)
    printf("%d-%d^^",s->val,t->val);
    if(s&&s->left&&s->right){
    printf("%d->%d->%d",s->val,s->left->val,s->right->val);
    printf("==%d->%d->%d",t->val,t->left->val,t->right->val);}
    printf("\n");*/
    bool flag;
    if(s==NULL&&t==NULL){
        return true;
    }
    if(s&&t&&s->val==t->val){
       printf("%d-%d\n",s->val,t->val);
        if((s->left==NULL&&t->left==NULL)||((s->left&&t->left)&&s->left->val==t->left->val)){
          flag=print(s->left,t->left);
            if(!flag){
                return false;
            }
        }
        else{
            if((s->left==NULL&&t->right==NULL)||((s->left&&t->right)&&s->left->val==t->right->val)){
                struct TreeNode *x=t->left;
                t->left=t->right;
                t->right=x;
             flag=print(s->left,t->left);
                if(!flag){
                    return false;
                }
                
            }
            else{
                return false;
            }
        }
        if((s->right==NULL&&t->right==NULL)||((s->right&&t->right)&&s->right->val==t->right->val)){
           return  print(s->right,t->right);
        }
        else{
            return false;
        }
    
    }
            return false;
            
}
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
 if(root1==NULL&&root2==NULL){
     return true;
 }
    bool var=print(root1,root2);
    printf("return: %d",var);
    return var;
    
}
