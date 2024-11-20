long long map[100001];
long long sum=0;
int hash[100001]={0};
int check(int l,int r,int *nums){
    memset(hash,0,sizeof(int)*100001);
    int ind=-1,prev=-1;
    long long temp=0;
    for(int i=l;i<=r;i++){
        if(!hash[nums[i]]){
            hash[nums[i]]=1;
        }
        else{
            for(int x=i-1;x>=l;x--){
                if(nums[x]==nums[i]){
                    ind=x;
                    break;
                }
            }
        }
    }
    if(ind==-1){
        temp=map[r]-map[l]+nums[l];
        if(temp>sum){
            sum=temp;
        }
        
    }
    
        return ind;
}
long long maximumSubarraySum(int* nums, int numsSize, int k) {
    map[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        map[i]=map[i-1]+nums[i];
    }
    sum=0;
    int i=0;
    int j=i+k-1;
    int ind=check(i,j,nums);
    while(j<numsSize){
        
        if(ind==-1){
            hash[nums[i]]=0;
            if(j+1<numsSize&&!hash[nums[j+1]]){
                hash[nums[j+1]]=1;
                long long temp=map[j+1]-map[i+1]+nums[i+1];
                if(temp>sum){
                    sum=temp;
                }
                i=i+1;
                j=j+1;
            }
            else{
                i=i+1;
                j=j+1;
                if(j<numsSize){
                    ind=check(i,j,nums);
                }
            }
        }
        else{
            i=ind+1;
            j=i+k-1;
            if(j<numsSize){
                ind=check(i,j,nums);
            }
        }
    }
    
    return sum;
            
}
