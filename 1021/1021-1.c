#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int row; //列
    int col; //行
    int value;
}term;


int **sca(int m, int n, char arr_name){
    int **Arr, i, j;
    Arr = malloc(sizeof(int*) * m);
    for(i = 0; i < m; i++){
        Arr[i] = calloc(n, sizeof(int));
    }
    printf("請依序輸入二維陣列%c(%d * %d)的元素內容:\n", arr_name, m, n);

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &Arr[i][j]);
        }
    }
    return Arr;
}

int **Ans(int **A, int **B, int m, int n, int p){
    int i, j, k;
    int **ans;
    ans = malloc(sizeof(int*) * m);
    for(i = 0; i < m; i++){
        ans[i] = calloc(p, sizeof(int));
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            ans[i][j] = 0;
            for(k = 0; k < n; k++){
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ans;
}



int main(){
    int i, j, flag = 0;
    int ma, na, mb, nb, **A, **B, **ans;
    while(flag == 0){
        printf("請輸入矩陣A(m*n)的大小:");
        scanf("%d %d", &ma, &na);
        if(ma == 0 || na == 0){
            printf("錯誤，請重新輸入!\n\n");
        }
        else{
            flag = 1;
            A = sca(ma, na, 'A');
//            for(i = 0; i < ma; i++){
//                for(j = 0; j < na; j++){
//                    printf("%d ",A[i][j]);
//                }
//                printf("\n");
//            }
        }
    }
    printf("---------------------------------------\n\n");
    flag = 0;
    while(flag == 0){
        printf("請輸入矩陣B(m*n)的大小:");
        scanf("%d %d", &mb, &nb);
        if(mb == 0 || nb == 0 || mb != na){
            printf("錯誤，請重新輸入!\n\n");
        }
        else{
            flag = 1;
            B = sca(mb, nb, 'B');
//            for(i = 0; i < mb; i++){
//                for(j = 0; j < nb; j++){
//                    printf("%d ",B[i][j]);
//                }
//                printf("\n");
//            }
        }
    }
    printf("---------------------------------------\n\n");
    printf("矩陣相乘結果:\n");
    ans = Ans(A, B, ma, na, nb);
    for(i = 0; i < ma; i++){
        for(j = 0; j < nb; j++){
            printf("%-5d",ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    term arr[ma*nb];
    arr[0].row = nb;
    arr[0].col = ma;
    arr[0].value = 0;
    for(i = 0; i < ma; i++){
        for(j = 0; j < nb; j++){
            if(ans[i][j] != 0){
                arr[0].value++;
                arr[arr[0].value].col = j;
                arr[arr[0].value].row = i;
                arr[arr[0].value].value = ans[i][j];
            }
        }
    }
    printf("稀疏矩陣:\n"); //row 橫列 col 直行
    printf("尺寸: %d * %d  項目數:%d\n", arr[0].col, arr[0].row, arr[0].value);
    printf("index   row     col     value\n");
    for(i = 1; i <= arr[0].value; i++){
        printf("  %d     %d        %d        %d", i, arr[i].row, arr[i].col, arr[i].value);
        printf("\n");
    }
    printf("---------------------------------------\n\n");
    int row_term[ma];
    int now = 0;
    int start[ma];

    for(i = 0; i < arr[0].value; i++){
        row_term[i] = 0;
        start[i] = 0;
    }
    for(i = 1; i <= arr[0].value; i++){
        row_term[arr[i].col]++;
    }
    start[0] = 1;
    for(i = 1; i <= arr[0].value; i++){
        start[i] = start[i-1] + row_term[i-1];
    }

    //轉置矩陣!!!!!
    term arrB[arr[0].value + 1];
    arrB[0].row = ma;
    arrB[0].col = nb;
    arrB[0].value = arr[0].value;

    for(i = 1; i <= arr[0].value; i++){
        arrB[i].value = 0;
    }

    printf("\n");
    for(i = 1; i <= arr[0].value; i++){
        int now_ = arr[i].col;
        if(arrB[start[now_]].value == 0){
            arrB[start[now_]] = arr[i];
            arrB[start[now_]].col = arr[i].row;
            arrB[start[now_]].row = arr[i].col;
        }
        else{
            j = 1;
            while(1){
                if(arrB[start[now_] + j].value != 0){
                    j++;
                }
                else{
                    break;
                }
            }
            arrB[start[now_] + j] = arr[i];
            arrB[start[now_] + j].col = arr[i].row;
            arrB[start[now_] + j].row = arr[i].col;
        }
    }
    printf("稀疏矩陣轉置:\n"); //row 橫列 col 直行
    printf("尺寸: %d * %d  項目數:%d\n", arrB[0].col, arrB[0].row, arrB[0].value);
    printf("index   row     col     value\n");
    for(i = 1; i <= arrB[0].value; i++){
        printf("  %d     %d        %d        %d", i, arrB[i].row, arrB[i].col, arrB[i].value);
        printf("\n");
    }
    printf("---------------------------------------\n\n");
    now = 1;
    for(i = 0; i < arrB[0].col; i++){
        for(j = 0; j < arrB[0].row; j++){
            if(i == arrB[now].row && j == arrB[now].col){
                printf("%-5d", arrB[now].value);
                now++;
            }
            else{
                printf("%-5d",0);
            }
        }
        printf("\n");
    }


}
