#include<stdbool.h>
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
int i=0;
int count=0;
    if(flowerbedSize==1){
if(flowerbed[0]==0){
    count++;
    }
    return count>=n;
    }
        


   if(flowerbed[0]==0 && flowerbed[1]==0){
        flowerbed[0]=1;
        count++;
        i+=2;
    }
 else{
        i++;
        }
    
    
while(i<flowerbedSize-1){
    if(count==n){
        return 1;
        }
     

if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0){

count++;
    flowerbed[i]=1;

i+=2;

}

else{

i++;

}

}
if(  flowerbed[flowerbedSize-1]==0 && flowerbed[flowerbedSize-2]==0){
    count++;
    }

    return count>=n;
    }









    
