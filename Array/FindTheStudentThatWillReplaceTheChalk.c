 int chalkReplacer(int* chalk, int chalkSize, int k) {
   long int sum=0;
    for(int i=0;i<chalkSize;i++){
       sum+=chalk[i];
        }
    int rem=k%sum;
    int ind=0;
    while(1){
        if(chalk[ind]>rem){
            return ind;
           }
        else{
            rem-=chalk[ind];
            ind++;
            }
        }
        
    
    
}