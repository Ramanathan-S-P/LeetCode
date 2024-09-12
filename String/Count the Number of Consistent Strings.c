

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
int hash[125]={0};
    for(int i=0;i<strlen(allowed);i++){
        hash[allowed[i]]=1;
    }
    int count=0;
    for(int i=0;i<wordsSize;i++){
        for(int j=0;j<strlen(words[i]);j++){
            if(hash[words[i][j]]!=1){
                --count;
                break;
            }
        }
        ++count;
    }
    return count;
}