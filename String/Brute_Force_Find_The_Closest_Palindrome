long int check(char *a,char *b) {
    printf ("%s---%s",b,a);
    printf("\n");
    long int x,y;
    sscanf(a,"%ld",&x);
    sscanf(b,"%ld",&y);
    printf ("%ld\n",labs(x-y));
    return labs(x-y);
}

int ispalindrome(char *s) {
    long    int len=strlen(s);
    long  int l=0;
    long int r=len-1;

    while(l<r) {
        if(s[l]!=s[r]) {
            return 0;
        }
        l++;
        r--;
    }
    return 1;

}
char* nearestPalindromic(char* s) {
    int ind=0;
    int flag=0;
    char *w=malloc(sizeof(char)*10000);
    char *z=malloc(sizeof(char)*10000);
    char* s2=malloc(sizeof(char)*10000);

    strcpy(s2,s);
    long   int len=strlen(s);
    long int l=0;
    long int r=len-1;
    long int n;
    sscanf(s,"%ld",&n);
    long   int p=(int)log10(n);
    long  int i;
    char *a=malloc(sizeof(char)*10000);
    if(( long int)pow(10,len)-1==n && len>1) {

        sprintf(a,"%ld",n+2);
        return a;
    }

    else {
        if(ispalindrome(s)) {


            while(l<r) {
                l++;
                r--;
            }
            if(s[l]!='0') {

                s[l]=s[l]-1;
                s[r]=s[l];
            }
            else {
                s[l]=s[l]+1;
                s[r]=s[l];
            }
        }

        else {
            char prev;
            char next;
            char evenext;
            while(l<r) {

                if(s[l]!=s[r]) {
                    if(r-l!=1) {
                        prev=s[l];
                        next=s[r];
                        s[r]=s[l];

                    }
                    else {
                        char one=s[l];
                        char two=s[r];
                        s[r]=s[l];
                        long int a= check(s,s2);
                        s[l]=one+1;
                        s[r]=s[l];
                        long int b=check(s,s2);
                        long int c=n-0;
                        if(one!='0') {
                            s[l]=one-1;
                            s[r]=s[l];
                            c=check(s,s2);
                        }
                        if(a<=b) {
                            if(a<c) {
                                printf("a<c");
                                s[l]=one;
                                s[r]=s[l];
                            }
                            else {
                                printf("a>c");
                                s[l]=one-1;
                                s[r]=s[l];
                            }
                        }
                        else {
                            if(b<c) {
                                printf("b<c");
                                s[l]=one+1;
                                s[r]=s[l];
                            }
                            else {
                                printf("b>c");
                                s[l]=one-1;
                                s[r]=s[l];
                            }
                        }



                    }

                }

                l++;
                r--;
            }
            if(l==r) {

                char test=s[l];
                long int a=check(s,s2);
                s[l]=test+1;
                long int b=check(s,s2);
                long int c=n-0;
                if(test!='0') {
                    s[l]=test-1;
                    c=check(s,s2);
                }

                if(a<=b) {
                    if(a<c) {
                        printf("a<c");
                        s[l]=test;
                    }
                    else {
                        printf("a>c");
                        s[l]=test-1;
                    }
                }
                else {
                    if(b<c) {
                        printf("b<c");
                        s[l]=test+1;

                    }
                    else {
                        printf("b>c");
                        s[l]=test-1;
                    }
                }

            }


        }


        for(i=0; i<len-1; i++) {

            a[i]='9';
        }
        a[i]='\0';

        if(ispalindrome(s2)) {
            strcpy(z,s2);
        }
        else {

            int left=0;
            int right=strlen(s2)-1;
            while(left<right) {
                z[left]=s2[left];
                z[right]=s2[left];
                left++;
                right--;
            }
        }
        z[strlen(s2)]='\0';
        int mid=strlen(z)/2;
        if(z[mid]=='0') {
            flag=1;
            int i=mid-1;
            while(i>0&&z[i]=='0') {
                z[i]='9';
                i--;
            }
            z[i]=z[i]-1;
            i=mid;
            while(i<strlen(z)-1&&z[i]=='0') {
                z[i]='9';
                i++;
            }
            z[i]=z[i]-1;
        }
        if(ispalindrome(s2)) {
            strcpy(w,s2);
        }
        else {

            int left=0;
            int right=strlen(s2)-1;
            while(left<right) {
                w[left]=s2[left];
                w[right]=s2[left];
                left++;
                right--;
            }
            if(left==right){
                w[left]=s2[left];
            }
        }
        w[strlen(s2)]='\0';
        mid=strlen(w)/2;
        if(w[mid]=='9'&&strlen(s2)>2) {
            ind=1;
            int i=mid-1;
            while(i>0&&w[i]=='9') {
                w[i]='0';
                i--;
            }
            w[i]=w[i]+1;
            i=mid;
            while(i<strlen(w)-1&&w[i]=='9') {
                w[i]='0';
                i++;
            }
            w[i]=w[i]+1;
        }

        long int num4=0;
        if(ind){
            sscanf(w,"%ld",&num4);
        }
        long int num3=0;
        
        if(flag){
        sscanf(z,"%ld",&num3);
        }
        long int num;
        sscanf(a,"%ld",&num);
        long int num2;
        sscanf(s,"%ld",&num2);
        long int arg;
        sscanf(s2,"%ld",&arg);
        
        long int min1=labs(num-arg);
        long int min2=labs(num2-arg);
        long int min3=labs(num3-arg);
        long int min4=labs(num4-arg);
        if(flag) {
            if(min4<min3) {
                min3=min4;
                sprintf(z,"%ld",num4);
            }
        }
        else {
            min3=min4;
            sprintf (z,"%ld",num4);
        }
        

        if(strlen(a)!=0) {
            
            printf("\n%s--%s--%s\n",s,z,a);
             if(min1<=min2&&min1<=min3) {
                printf("min1");
                return a;
            }
            else if(min2<=min1&&min2<=min3) {
                printf ("min2");
                return s;
            }
            else {
                printf ("min3");
                return z;
            }
        }

        else {
            return s;
        }
    }
    return s;
}
