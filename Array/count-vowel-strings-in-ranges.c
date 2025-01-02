/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int vowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
        return 1;
    }
    return 0;
}
int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int prefix[wordsSize];
    prefix[0]=0;
    if(vowel(words[0][0]) && vowel(words[0][strlen(words[0])-1])){
        prefix[0]=1;
    }
    for(int i=1;i<wordsSize;i++){
       if(vowel(words[i][0]) &&vowel(words[i][strlen(words[i])-1])){
        prefix[i]=prefix[i-1]+1;
       }
       else{
        prefix[i]=prefix[i-1];
       }
    }
    int *arr=malloc(sizeof(int)*queriesSize);
    for(int i=0;i<queriesSize;i++){
        if(queries[i][0]==0){
            arr[i]=prefix[queries[i][1]];
        }
        else{
            arr[i]=prefix[queries[i][1]]-prefix[queries[i][0]-1];
        }
    }
 *returnSize=queriesSize;
 return arr;
    }
