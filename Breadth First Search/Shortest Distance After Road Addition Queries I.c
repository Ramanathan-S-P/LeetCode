/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int mat[n+1][n+1];
    
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<i+1;j++){
            mat[i][j]=0;
        }
        for(int j=i+1;j<n;j++){
            mat[i][j]=++count;
        }
       
    }
    
    printf("\n");
    int *ans=malloc(sizeof(int)*queriesSize);
    int i;
    int flag=0;
    for( i=0;i<queriesSize;i++){
        int x=queries[i][0];
        int y=queries[i][1];
        mat[x][y]=1;
        
        int p=y;
        for(int q=y+1;q<n;q++){
         if(mat[p][q]+1<mat[x][q]){   
             mat[x][q]=mat[p][q]+1;
        }
        }
        for(int r=0;r<x;r++){
         for(int s=y;s<n;s++){
             if(mat[r][x]+mat[x][s]<mat[r][s]){
                 mat[r][s]=mat[r][x]+mat[x][s];
             }
         }
        }
            ans[i]=mat[0][n-1];
        
    }
    *returnSize=queriesSize;
        return ans;
        
}
