int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
long long dividePlayers(int* skill, int skillSize) {
    int hash[100001]={0};
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<skillSize;i++){
        hash[skill[i]]+=1;
        printf("%d=%d\n",skill[i],hash[skill[i]]);
        if(skill[i]>max){
            max=skill[i];
        }
        if(skill[i]<min){
            min=skill[i];
        }
    }
    printf("%d,%d\n",max,min);
    int sum=max+min;
    //qsort(skill,skillSize,sizeof(int),cmp);
    long long mul=0;
    int i;
    
    for( i=0;i<skillSize;i++){
        if(hash[skill[i]]){
            
        
        if(hash[sum-skill[i]]){
            
            hash[sum-skill[i]]-=1;
            hash[skill[i]]-=1;
            printf("%d-%d-%d-%d\n",skill[i],hash[skill[i]],sum-skill[i],hash[sum-skill[i]]);
            mul+=skill[i]*(sum-skill[i]);
        }
            else{
                return -1;
            }
        }
    }
return mul;
    //WITHOUT USING HASH MAP BRUTEFORCE
    
   /* long long mul=skill[0]*skill[skillSize-1];
    int sum=skill[skillSize-1]+skill[0];
    int i,j;
    for( i=1,j=skillSize-2;i<skillSize/2;i++,j--){
        if(skill[i]+skill[j]!=sum){
            break;
        }
        mul+=skill[i]*skill[j];
    }
    if(i==skillSize/2){
        return mul;
    }
    return -1;*/

}
