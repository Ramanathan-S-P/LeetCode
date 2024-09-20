int check (char*s ,int right){
    int left=0;
    while(left<=right && s[left]==s[right]){
        left++;
        right--;
    }
if(left>right){
    return 1;
}
    else{
        return 0;
    }
}



char* shortestPalindrome(char* s) {
    char *str=malloc(sizeof(char)*500000);
    
    int len=strlen(s);
    int i;
    for( i=strlen(s)-1;i>=0;i--){
        if(check(s,i)){
            break;
        }
    }
    int ind=-1;
    for(int j=strlen(s)-1;j>i;j--){
        *(str+(++ind))=s[j];
    }
    for(int i=0;i<strlen(s);i++){
        *(str+(++ind))=s[i];
    }
    *(str+(++ind))='\0';
    //str[++ind]='\0';
    printf("%s",str);
    
    return  str;
}
