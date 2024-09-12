int minBitFlips(int a, int b) {
int c=a^b;
int count=0;
while(c!=0){
count+=c&1;
c>>=1;
}
    return count;
}
/*rather than introducing  if(c&1)count+=1 do count +=c&1 as this reduces the time utilized  when compared to introducing a conditional branch (i.e if(c&1) ).*/