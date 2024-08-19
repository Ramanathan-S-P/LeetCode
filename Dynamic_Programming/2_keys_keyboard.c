int  fact(n) {
    for(int i =n/2; i>=1; i--) {
        if(n%i==0) {
            return i;
        }
    }
    return 1;
}




int minSteps(int n) {
    if(n==1){
        return 0;
    }
  


    else{
        
    int ans=fact(n);
        if(ans==1){
            return n;
            }
        else{
    int count=0;
    int num;
    while(ans!=1) {
    num=ans;
        count+=n/ans;
        n=ans;
        ans=fact(ans);
    }
    count+=num;
    return count;
}
}
    }
