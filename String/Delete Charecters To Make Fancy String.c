char* makeFancyString(char* s) {
    if(strlen(s)==1){
        return s;
    }
    char *s2=malloc(sizeof(char)*strlen(s)+1);
    
    int ind=0;
    int i=0;int j=1;
    while(j<strlen(s)){
        while(j<strlen(s)&&s[i]==s[j]){
            j++;
        }
      s2[ind++]=s[i];
        if(j-i>1){
            s2[ind++]=s[i+1];
        }
        i=j;
        j=j+1;
    }
    if(i<strlen(s)&&s[i]!=s[i-1]){
        s2[ind++]=s[i];
    }
    s2[ind]='\0';
    //printf("%s",s2);
    return s2;
}
            
