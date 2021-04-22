#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polynomial1{
	int number;
	int power;
	struct polynomial *next;
}Poly;

void save(int number, int power, Poly **head){
    Poly *now, *previous, *next;
    int num = 0, i, flag = 0;
	if(number != 0){
        if(*head == NULL){
            *head = malloc(sizeof(Poly));
            now = *head;
            now->number = number;
            now->power = power;
            now->next = NULL;
        }
        else{
            now = *head;
            while(now != NULL){ //����ۦP �Y�Ƭۥ[
                if(now->power == power){
                    now->number += number;
                    flag = 1;
                    break;
                }
                now = now->next;
            }
            if(flag == 0){
                now = 0;
                if(power > (*head)->power){ //�Y����j��Ĥ@�� �hhead����{�b��J�o��
                    previous = malloc(sizeof(Poly));
                    previous->number = number;
                    previous->power = power;
                    previous->next = *head;
                    *head = previous;
                }
                else{  //�M�����b�����J�}�C
                    now = *head;
                    previous = *head;
                    while(now != NULL){
                        if(power > now->power){
                            break;
                        }
                        num++;
                        now = now->next;
                    }
                    for(i = 1; i < num; i++){
                        previous = previous->next;
                    }
                    next = previous->next;
                    previous->next = malloc(sizeof(Poly));
                    now = previous->next;
                    now->number = number;
                    now->power = power;
                    now->next = next;
                }
            }
        }
    }
}

void print(Poly *head){
    Poly *nowptr = head;
    int flag = 0;
	while(nowptr != NULL){
        if(nowptr->number == 0){
            flag = 0;
        }
        else{
            flag = 1;
            if(nowptr->number == 1){
            }
            else{
                printf("%d",nowptr->number);
            }
            if(nowptr->power == 1){
                printf("x ");
            }
            else if(nowptr->power == 0){
                flag = 0;
            }
            else{
                printf("x^%d ", nowptr->power);
            }
            if(nowptr->number == 1 && nowptr->power == 0){
                printf("1");
            }
        }
        nowptr = nowptr->next;
        if(flag == 1 && nowptr->number >= 0){
            printf("+ ");
        }
    }
    printf("\n");
}

void plus(Poly *head1, Poly *head2){
    Poly *ans_head = NULL, *now;
    now = head1;
    while(now != NULL){
        save(now->number, now->power, &ans_head);
        now = now->next;
    }

    now = head2;
    while(now != NULL){
        save(now->number, now->power, &ans_head);
        now = now->next;
    }
    print(ans_head);

}
int main(){
	int i, j, number, power, flag = 0, now, stop = 0;
	Poly *head1 = NULL, *nowptr = NULL, *head2 = NULL, *previous = NULL, *next;
	while(stop == 0){
		printf("��J�h����1(�Y�� ����): ");
		scanf("%d %d", &number, &power);
		if(number == 0 && power == 0){
			stop = 1;
		}
		else{
            save(number, power, &head1);
		}
	}
	printf("--�h����1��: ");
    print(head1);
    printf("\n");

    stop = 0;
    while(stop == 0){
		printf("��J�h����2(�Y�� ����): ");
		scanf("%d %d", &number, &power);
		if(number == 0 && power == 0){
			stop = 1;
		}
		else{
            save(number, power, &head2);
		}
	}
    printf("--�h����2��: ");
    print(head2);
    printf("\n");

    printf("�ۥ[���G: ");
    plus(head1,head2);
}
