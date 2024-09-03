long int sod(long int num){
    long int x=num;
   long int sum=0;
    if(num>9){
        do{
            x=num%10;
            sum+=x;
        }while((num/=10)!=0);
            return sum;
        }
    return num;
    }

long int getLucky(char* s, int k) {
 long int num=0;
    long int len=strlen(s);
    for(int i=0;i<len;i++){
           num+=sod(s[i]-'a'+1); 
    }
    for(int i=1;i<k;i++){
        num=sod(num);
    }
    return num; 
}