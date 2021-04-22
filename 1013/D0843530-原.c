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
	while(nowptr != NULL){
        if(nowptr->number > 0 && nowptr != head){
            printf("+");
        }
        if(nowptr->power == 0){
            printf("%d", nowptr->number);
        }
        else if(nowptr->power == 1){
            printf("%dx", nowptr->number);
        }
        else if(nowptr->number == 1){
            printf("x^%d", nowptr->power);
        }
        else if(nowptr->number == 0){
        }
        else{
            printf("%dx^%d", nowptr->number, nowptr->power);
        }
        nowptr = nowptr->next;
    }
    printf("\n");
}

int main(){
	int i, j, number, power, flag = 0, now, stop = 0;
	Poly *head1 = NULL, *nowptr = NULL, *head2 = NULL, *previous = NULL, *next;
	while(stop == 0){
		flag = 0;
		printf("��J�h����1(�Y�� ����): ");
		scanf("%d %d", &number, &power);
		if(number == 0 && power == 0){
			stop = 1;
		}
		else{
            save(number, power, &head1);
//			if(number != 0){
//				if(head1 == NULL){
//					head1 = malloc(sizeof(Poly));
//					nowptr = head1;
//					nowptr->number = number;
//					nowptr->power = power;
//					nowptr->next = NULL;
//				}
//				else{
//					nowptr = head1;
//					while(nowptr != NULL){ //����ۦP �Y�Ƭۥ[
//						if(nowptr->power == power){
//							nowptr->number += number;
//							flag = 1;
//							break;
//						}
//						nowptr = nowptr->next;
//					}
//					if(flag == 0){
//						now = 0;
//						if(power > head1->power){ //�Y����j��Ĥ@�� �hhead����{�b��J�o��
//                            previous = malloc(sizeof(Poly));
//                            previous->number = number;
//                            previous->power = power;
//                            previous->next = head1;
//                            head1 = previous;
//						}
//						else{  //�M�����b�����J�}�C
//                            nowptr = head1;
//                            previous = head1;
//                            while(nowptr != NULL){
//                                if(power > nowptr->power){
//                                    break;
//                                }
//                                now++;
//                                nowptr = nowptr->next;
//                            }
//                            for(i = 1; i < now; i++){
//                                previous = previous->next;
//                            }
//                            next = previous->next;
//                            previous->next = malloc(sizeof(Poly));
//                            nowptr = previous->next;
//                            nowptr->number = number;
//                            nowptr->power = power;
//                            nowptr->next = next;
//						}
//					}
//				}
//			}
		}
	}
    print(head1);
}
