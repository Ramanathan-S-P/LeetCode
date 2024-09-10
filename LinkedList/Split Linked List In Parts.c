/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void createll(struct ListNode** head, int val){
  //  printf("%d",(*head)->val);
    struct ListNode* temp=malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    if((*head)==NULL){
        *head=temp;
       // printf("head\n");
       // printf("head:%d\n",(*head)->val);
    }
    
    //struct ListNode* x=head;
    else{
        
        struct ListNode*x=*head;
       // printf("%p->%p\n",&(*head),&x);
        while((x)->next!=NULL){
          // printf("insideloop:%d->",(*x)->val);
            (x)=(x)->next;
        }

        (x)->next=temp;
      //  printf("else\n");;
      //  printf("%dover\n",((*x)->next)->val);
    }
    //*head=temp;
  //printf("%d",(*head)->val);*/
    
    
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
struct ListNode**arr=malloc(sizeof(struct ListNode *)*k);
    
    int rem=0;
    int returnsize[k];
    struct ListNode *temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    rem=n%k;
    for(int i=0;i<k;i++){
        returnsize[i]=n/k;
    }
    int i=0;
    while(rem!=0){
        if(i>=n){
            i=0;
        }
        returnsize[i]+=1;
    
        i++;
        rem--;
    }
    temp=head;
    for(int i=0;i<k;i++){
 //    struct ListNode* arr[i];
        arr[i]=NULL;
    
    
        for(int j=0;j<returnsize[i];j++){
            createll(&arr[i],temp->val);
           // printf("%d\n",arr[i]->val);
                     temp=temp->next;
        }
        struct ListNode*tem=arr[i];
      //  printf("%d->",arr[i]->val);
        while(tem!=NULL){
         //   printf("%d->",tem->val);
            tem=tem->next;
        }
        //printf("\n");
    }
   *returnSize=k;
   // printf("\n");
    return arr;
}
