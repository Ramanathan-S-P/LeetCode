
int main(){
//int n;
//scanf("%d",&n);
int cnt=(int) log2(n)+1;
int a[cnt];
int ind=cnt;
int num=n;
do{
a[--ind]=num%2;
//printf("%d%%2=%d\n",num,num%2);
}while((num/=2)!=0);
int ans=0;
int  inc=0;
for(int i=cnt-1;i>=0;i--){
ans+= !a[i]*(int ) (pow(2,inc++));

}
//printf("%d",ans);
return ans;

/*
Alternate method is to generate 1's to length of bin value of given num say 5=(101)..then generate(111) and xor both to get 1's complement...there are also other ways to do this ...

int find compliment(num)
{
long int cnt=(int) log2(n)+1;
long int num=(int) pow(2,cnt)-1;
return n^num;
}
*/

}