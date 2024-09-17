/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const char** a,const char **b){

    return strcmp(*a,*b);
}
void strcpy_i(char *v,char * s){
   // *v=malloc(sizeof(char)*(strlen(s)+1));
    while(*s!='\0'){
        *v++=*s++;
    }
    *v='\0';
}
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    char *arr[100];
    int ind=0;
    arr[0]=strtok(s1," ");
    int i=0;
    while(arr[i++]!=NULL){
        arr[i]=strtok(NULL," ");
    }
   
  int len1=i-1;
    qsort(arr,i-1,sizeof(char*),cmp);
    for(int ind=0;ind<i-1;ind++){
       printf("%s\n",arr[ind]);
    }
      printf("\n");
    char brr[100][100];
    int j=-1;
    ind=0;
    int count=0;
    int m;
      printf("appind:%d",i);
    while(ind <i-1){
     m=ind;
        
        while(ind+1<i-1&&!(strcmp(arr[ind],arr[ind+1]))){
            
            ind++;
        }
        if(m==ind){
         //   brr[j]=NULL;
           // brr[j]=malloc(sizeof(char)*(strlen(arr[ind-1])+1));
            strcpy(brr[++j],arr[ind]);
            printf("inside dupfindeer: %s\n",brr[j]);
            
        }
        ind++;
        
    }
   
    int c1=j;
    
    char *sarr[100];
    ind=0;
    sarr[0]=strtok(s2," ");
     i=0;
    while(sarr[i++]!=NULL){
        sarr[i]=strtok(NULL," ");
    }
    int len2=i-1;
    qsort(sarr,i-1,sizeof(char*),cmp);
    for(int ind=0;ind<i-1;ind++){
        printf("%s\n",sarr[ind]);
    }
    printf("\n");
    
    char sbrr[100][100];
     j=-1;
    ind=0;
     count=0;
  
    while(ind<i-1){
        m=ind;
        while(ind+1<i-1&&!(strcmp(sarr[ind],sarr[ind+1]))){
            printf("hiaspp");
            
            ind++;
        }
        if(m==ind){
         //   brr[j]=NULL;
           // brr[j]=malloc(sizeof(char)*(strlen(arr[ind-1])+1));
            strcpy(sbrr[++j],sarr[ind]);
            printf("in dupfinder : %s\n",sbrr[j]);
            
        }
        ind++;
        
    }
   
    
        int c2=j;
    char **ans=malloc(sizeof(char*)*100);
    *returnSize=-1;
    int flag;
    for(int i=0;i<=c1;i++){
        flag=0;
        for(j=0;j<len2;j++){
           int check = strcmp(brr[i],sarr[j]);
            if(check<0){
                //strcpy(ans[++*returnSize],brr[i]);
                break;
            }
            if(check==0){
            flag=1;
                break;
            }
        }
         if(!flag){
            ans[++*returnSize]=malloc((strlen(brr[i])+1)*sizeof(char));
            strcpy_i(ans[*returnSize],brr[i]);
        }
    }
    
    for(int i=0;i<=c2;i++){
        flag=0;
        for(j=0;j<len1;j++){
           int check = strcmp(sbrr[i],arr[j]);
            if(check<0){
               // strcpy(ans[++*returnSize],sbrr[i]);
                break;
            }
            if(check==0){
                 flag=1;
                break;
            }
        }
        if(!flag){
            ans[++*returnSize]=malloc((strlen(sbrr[i])+1)*sizeof(char));
            strcpy_i(ans[*returnSize],sbrr[i]);
        }
    }
    printf("ans:\n");
    for(int i=0;i<=*returnSize;i++){
        printf("%s ",ans[i]);
    }
    printf("\n");
    ++*returnSize;
return ans;
}
