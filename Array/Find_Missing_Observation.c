/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int check(int g,int n) {
  //int g=(n+m)*mean-sum;
   // printf("%d",g);
    if(g>0&&n<=g){
      return   n*6>=g?1:0;
    }
    else{
        return 0;
    }
}

int* missingRolls(int* rolls, int m, int mean, int n, int* returnSize) {
    int *arr=malloc(sizeof(int)*n);
    int sum=0;
    for(int i=0;i<m;i++){
        sum+=rolls[i];
    }
    int diff;
    //    if(check(mean,n,m,sum)) {
        diff=(n+m)*mean-sum;
       if(check(diff,n)){
        int val=diff/n;
            for(int i=0; i<n; i++) {
                arr[i]=val;
            
            }
            int count=diff%n;
            if(count){
                for(int i=0;i<n;i++){
                    if(count==0){
                        break;
                    }
                    while(arr[i]<6&&count!=0){
                        arr[i]+=1;
                        count-=1;
                        
                    }    
                }
            }
        
            *returnSize=n;
            return arr;
    }
    else {
        *returnSize=0;
        return NULL;
    }
    
}