bool checkInclusion(char* s1, char* s2) {
    if(strlen(s1)>strlen(s2)){
        return false;
    }
 int hash[26]={0};
    for(int i=0;i<strlen(s1);i++){
        hash[s1[i]-'a']+=1;
        }
    int i=0;
    while(i+strlen(s1)-1<strlen(s2)){
        int hash2[26];
        for(int i=0;i<26;i++){
            hash2[i]=hash[i];
        }
        int j=i;
        printf("%d\n",hash2[s2[j]-'a']);
        while(j<strlen(s2)&&hash2[s2[j]-'a']){
            hash2[s2[j]-'a']-=1;
            j++;
        }
        if(j-i==strlen(s1)){
            return true;
        }
        if(j<strlen(s2)&&hash[s2[j]-'a']==0){
            i=j;
        }
     i++;
        
    }
    return false;
}
