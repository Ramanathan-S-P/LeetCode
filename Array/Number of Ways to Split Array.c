int waysToSplitArray(int* nums, int numsSize) {
 
   int count=0;
   long num[numsSize];
   num[0]=nums[0];
   for(int i=1;i<numsSize;i++){
    num[i]=nums[i]+num[i-1];
   }
   for(int i=0;i<numsSize-1;i++){
    if(num[i]>=num[numsSize-1]-num[i]){
        count ++;
    }
   }
   return count;


}
