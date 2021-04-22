#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int poly[100][2],int start, int end){
    int i, j, tmp;
    for(i = start; i < end-1;i++){
        for(j = start; j < end-1; j++){
            if(poly[j][1] < poly[j+1][1]){
                tmp = poly[j][0];
                poly[j][0] = poly[j+1][0];
                poly[j+1][0] = tmp;
                tmp = poly[j][1];
                poly[j][1] = poly[j+1][1];
                poly[j+1][1] = tmp;
            }
        }
    }
}

void print(int poly[100][2], int start, int end){
    int flag = 0, i;
	for(i = start; i < end; i++){
        if(poly[i][0] == 0){
            flag = 0;
        }
        else{
            flag = 1;
            if(poly[i][0] == 1){
            }
            else{
                printf("%d",poly[i][0]);
            }
            if(poly[i][1] == 1){
                printf("x ");
            }
            else if(poly[i][1] == 0 ){
                flag = 0;
            }
            else{
                printf("x^%d ", poly[i][1]);
            }
            if(poly[i][0] == 1 && poly[i][1] == 0){
                printf("1");
            }
        }
        if(flag == 1 && poly[i + 1][0] > 0 && i < end - 1){
            printf("+ ");
        }
    }
    printf("\n\n");
}

int add(int poly[100][2], int now, int head2){
    int i, power = poly[head2][1], j;
    int ans_head = now, tmp = 0;

    if(poly[0][1] > poly[head2][1]){
        power = poly[0][1];
    }


    for(i = power; i >= 0; i--){
        poly[ans_head + i][1] = tmp++;
        poly[ans_head + i][0] = 0;

    }

    for(i = 0; i < now; i++){
        for(j = 0; j <= power;j++){
            if(poly[i][1] == poly[ans_head + j][1]){
                poly[ans_head + j][0] += poly[i][0];
            }
        }
    }
    return power + 1 + ans_head;

}
int main(){
    int i, j, number, power, flag = 0, now = 0, stop = 0;
    int head2, poly[100][2], last; //0 為係數 1 為次方

	while(stop == 0){
		printf("輸入多項式1(係數 次方)(0 0結束多項式輸入): ");
		scanf("%d %d", &number, &power);
		if(number == 0 && power == 0){
			stop = 1;
			head2 = now;
		}
		else{
            flag = 0;
            for(i = 0; i < now; i++){ //次方相同 係數相加
                if(poly[i][1] == power){
                    poly[i][0] += number;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                poly[now][0] = number;
                poly[now][1] = power;
                now++;
            }
		}
	}

	sort(poly, 0, now);
	printf("--多項式1為: ");
    printf("\n");
    print(poly, 0, now);


    stop = 0;
    while(stop == 0){
		printf("輸入多項式2(係數 次方)(0 0結束多項式輸入): ");
		scanf("%d %d", &number, &power);
		if(number == 0 && power == 0){
			stop = 1;
		}
		else{
            flag = 0;
		    for(i = head2; i < now; i++){
                if(poly[i][1] == power){
                    poly[i][0] += number;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                poly[now][0] = number;
                poly[now][1] = power;
                now++;
            }
		}
	}

	sort(poly, head2, now);
    printf("--多項式2為: ");
    printf("\n");
    print(poly, head2, now);

    last = add(poly, now, head2);
    printf("相加結果: \n");
    print(poly, now, last);

}

