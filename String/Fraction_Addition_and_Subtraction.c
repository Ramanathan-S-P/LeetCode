int gcd(a,b) {
    while(a!=0&&b!=0) {
        if(b>a) {
            b=b%a;
        }
        else {
            a=a%b;
        }
    }
    if(a==0) {
        return b;
    }
    else {
        return a;
    }
}



char* fractionAddition(char* q) {
    int lcm=1;
    int flag=0;
    float dec[100][2];
    int ind=-1;
    int i=0;
    char op[100];
    int opcnt=-1;
    float fin;
    float ans=0;
    float ans2=0;
    char ch;
    
    if(!isdigit(q[i])) {
        flag=1;
        ++i;
    }
    while(i<strlen(q)-1) {
        while(isdigit(q[i])) {
            ans=(ans*10)+(q[i]-'0');
            i++;
        }

        i++;
        while(isdigit(q[i])) {
            ans2=(ans2*10)+(q[i]-'0');
            i++;
        }


        ++ind;
        dec[ind][0]=ans;
        dec[ind][1]=ans2;
        lcm*=dec[ind][1];
        op[++opcnt]=q[i];
        i++;
        ans=0;
        ans2=0;


    }
    if(flag) {
        dec[0][0]=-dec[0][0];
    }
   
    for(int j=0; j<=ind; j++) {
        dec[j][0]=dec[j][0]*(lcm/dec[j][1]);
    }
    int num;
    if(op[0]=='+') {

        num=dec[0][0]+dec[1][0];
    }
    else {
        num=dec[0][0]-dec[1][0];
    }
    int k=2;
    for(int j=1; j<=opcnt; j++,k++) {
        if(op[j]=='+') {
            num+=dec[k][0];
        }
        else {
            num-=dec[k][0];
        }
    }
    int dup;
    if(num<0){
    dup=-num;
    }
    else{
    dup=num;
    }
    
    int div=gcd(dup,lcm);
  
static char s[100];
sprintf(s,"%d/%d",num/div,lcm/div);
    printf("%s\n",s);
return &s;
    
}
