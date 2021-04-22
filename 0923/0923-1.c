#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int *num = malloc(30 * sizeof(int));
    int randnum , i , j , flag = 0 , tmp;
    for(i = 0 ; i < 30 ; i++){
        flag = 0;
        randnum = (rand() % 100) + 1;
        for(j = 0 ; j <= i ; j++){
            if(randnum == *(num + j)){
                i--;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            *(num + i) = randnum;
        }
    }
    for(i = 0 ; i < 30 ; i++){
        for(j = 0 ; j < 30-i ; j++){
            if( *(num + j) < *(num + j + 1) ){
                tmp = *(num + j);
                *(num + j) =*(num + j + 1);
                *(num + j + 1) = tmp;
            }
        }
    }
    for(i = 0 ; i < 30 ; i++){
        printf("%d\n",*(num + i));
    }
}
