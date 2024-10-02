/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TABLE_SIZE 100001
int cmp(int *a,int *b){
    return *a-*b;
}
struct h{
    int val;
    int indx [900];
    int len;
     struct h *next;
};
// Hash function for integers in the range from 10^9 to -10^9
int hash_function(int element) {
    // Handle negative numbers by using (element % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE
    return (element % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
  struct h * hash[100001];
    for(int i=0;i<100001;i++){
        hash[i]=NULL;
    }
  for(int i=0;i<arrSize;i++){
    int index=hash_function(arr[i]);
    if(hash[index]==NULL){
         hash[index]=malloc(sizeof(struct h));
         hash[index]->val=arr[i];
         hash[index]->len=0;
         hash[index]->indx[hash[index]->len]=i;
         hash[index]->next=NULL;
    }
    else{
        struct h* temp=hash[index];
        while(temp){
            if(temp->val==arr[i]){
                temp->len+=1;
                temp->indx[temp->len]=i;
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL){
        temp=malloc(sizeof(struct h));
        temp->val=arr[i];
        temp->len=0;
        temp->indx[temp->len]=i;
        temp->next=hash[index];
        hash[index]=temp;
        }
    }

  }
  qsort(arr,arrSize,sizeof(int),cmp);
    for(int i=0;i<arrSize;i++){
        printf("%d->",arr[i]);
    }
    int *count =malloc(sizeof(int)*arrSize);
    int rank=1;
     int it=0;
    while(it<arrSize){
    int t=arr[it];
      int index =hash_function(arr[it]);
      struct h* temp=hash[index];
      while(temp){
          if(temp->val==arr[it]){
              break;
          }
          temp=temp->next;
      }
        printf("\n%d->%d->%d",arr[it],temp->val,temp->len);
        printf("\n");
      for(int i=0;i<=temp->len;i++){
          printf("%d=",temp->indx[i]);
          count[temp->indx[i]]=rank;
      }
        while(++it<arrSize&&arr[it]==t){
            
        }
        rank++;
    }
      
      
      
  
   *returnSize=arrSize; 
  return count;
}
