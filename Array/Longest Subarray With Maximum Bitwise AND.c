
int longestSubarray(int* nums, int numsSize) {
    int max=INT_MIN;
    int count=0;
    int ind=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]>max){
            max=nums[i];
            ind=i;
        }
    }
   // printf("%d-%d",max,ind);
    int max_c=0;
    int i=ind;
    while(i<numsSize){
        
        while( i<numsSize && nums[i++]==max){
        
            count++;
        }
        max_c=max_c<count?count:max_c;
    count=0;
    }
    return max_c;
}
