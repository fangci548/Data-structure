#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int now = 10,  path[10] ;//-1 Left  1 Right
    int i = 0;
    while(now > 1){
        if(now % 2 == 0){
            path[i] = -1;
        }
        else{
            path[i] = 1;
        }
        now = now / 2;
        i+=1;
        printf("@@@@ = %d",i);
    }
    printf("@@@@ = %d",path[2]);
}

