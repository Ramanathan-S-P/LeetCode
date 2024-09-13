/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *ans=malloc(sizeof(int)*queriesSize);
    
    for(int i=1;i<arrSize;i++){
        arr[i]^=arr[i-1];
    }
    for(int i=0;i<queriesSize;i++){
        if(queries[i][0]){
       ans[i]=arr[queries [i][1]]^arr[queries[i][0]-1];
        }
        else{
            ans[i]=arr[queries [i][1]];
        }
        
    }
    *returnSize=queriesSize;
    return ans;
}