/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {

       if(m*n==originalSize){
          *returnSize=m;
           returnColumnSizes[0]=malloc(sizeof(int)*m);
     int **a=malloc(sizeof(int *)*m);
    for(int i=0;i<m;i++){
    a[i]=malloc(sizeof(int)*n);
        returnColumnSizes[0][i]=n;
    }
    int ind=0;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    a[i][j]=original[ind++];
    printf("%d",a[i][j]);
    }
        printf("\n");
    }
           return a;
       }
    else{
        *returnSize=0;
        return NULL;
    }
           
}
