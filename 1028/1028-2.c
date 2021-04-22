#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, j, flag = 0, now = 0, stop = 0, ans;
    char str1[20], str2[20];

	while(stop == 0){
        flag = 0;
		printf("•ÿº–¶r¶ÍT: ");
		scanf("%s", str1);
		printf("§«∞t¶r¶ÍS: ");
		scanf("%s", str2);
		if(str1[0] == '0' && str2[0] == '0'){
			stop = 1;
		}
		else{
            for(i = 0; i < strlen(str1); i++){
                j = 0;
                if(str1[i] == str2[0]){
                    for(j = 0; j < strlen(str2); j++){
                        if(str1[i + j] != str2[j]){
                            break;
                        }
                    }
                }
                if(j == strlen(str2)){
                    ans = i;
                    flag = 1;
                    break;
                }
            }
            printf("\n");
            if(flag == 1){
                printf("∑j¥Msuccess°AØ¡§ﬁ≠» = %d\n", ans);
            }
            else{
                printf("∑j¥M•¢±—°I\n");
            }
            printf("------------------------------------------\n");
		}
	}
}


