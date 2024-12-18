/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *ans=malloc(pricesSize*sizeof(int));
    
    int arr[pricesSize];
    int ind[pricesSize];
    int top=-1;
    for(int i=0;i<pricesSize;i++){
        if(top==-1){
            arr[++top]=prices[i];
            ind[top]=i;
        }
        else{
            if(arr[top]>=prices[i]){
                while(top!=-1&&arr[top]>=prices[i]){
                    
                ans[ind[top]]=prices[ind[top]]-prices[i];
                top--;
            
            }
                arr[++top]=prices[i];
                ind[top]=i;
            }
            else{
                arr[++top]=prices[i];
                ind[top]=i;
            }
        }
    }
 while(top!=-1){
     ans[ind[top]]=prices[ind[top]];
     top--;
 }
    *returnSize=pricesSize;
    return ans;
                

    
}
