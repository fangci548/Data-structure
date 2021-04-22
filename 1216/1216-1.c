#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **newarray(int vertex){
    int **array;
    array = calloc(vertex, sizeof(int*));
    for(int i = 0; i < vertex; i++){
        array[i] = calloc(vertex, sizeof(int));
    }
    return array;
}

void dfs(int **array, int num, int ans[], int vertex){
    int i, j;
    printf("%d ", num);
    ans[num] = 1;
//    for(i = 0; i < vertex; i++){
//
//                printf("%d ", ans[i]);
//        }
//        printf("\n");
    for(i = 0; i < vertex; i++){
        if(array[num][i] == 1 && ans[i] != 1){
            dfs(array, i, ans, vertex);
        }
    }
}

int main(){
    FILE *fp = fopen("input.txt", "r");
    int temp1, temp2, vertex;
    int i, j,now = 0;
    int **array;
    while(fscanf(fp, "%d", &vertex) != EOF){
        now = 0;
        printf("Number of vertex: %d\n",vertex);
        array = newarray(vertex);
//        for(i = 0; i < vertex; i++){
//            for(j = 0; j < vertex; j++){
//                printf("%d ", array[i][j]);
//            }
//            printf("\n");
//        }
        while(1){
            fscanf(fp, "%d->%d", &temp1, &temp2);
            printf("edge %d: %d -> %d\n", now + 1,temp1, temp2);
            if(temp1 == 0 && temp2 == 0){
                break;
            }
            if(array[temp1][temp2] == 1){
                printf("It failed to add¡I\n");
            }
            else if(temp1 == temp2){
                printf("It failed to add¡I\n");
            }
            else{
                now++;
                array[temp1][temp2] = 1;
            }
        }
        printf("\nAdjacency Matrix:\n");
        for(i = 0; i < vertex; i++){
            for(j = 0; j < vertex; j++){
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
        printf("\nDFS: ");
        int ans[20] = {0};
        dfs(array, 0, ans, vertex);
        printf("\n\n--------------------------------------------\n\n");

    }
}
