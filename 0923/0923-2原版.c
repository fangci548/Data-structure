#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student{
    char name[15];
    char sex;
    int number;
    int score_com;
    int score_math;
    float score_ave;
}stu;

FILE *openfile(int mode){
    if(mode == 0){
        return fopen("name.txt","r");
    }
    else{
        return fopen("student.txt","w");
    }
}

void case1(int i,int* num,char* sex,int* com,int* math){
    int tmp;
    *num = i+1;
    tmp = (rand() % 2);
    if(tmp == 0){
        *sex = 'F';
    }
    else{
        *sex = 'M';
    }
    *com = (rand() % 31) + 70;
    *math = (rand() % 31) + 70;
}
void case2(FILE *f,char name[15],int num,char sex){
//    f = fopen("student.txt","w");
//    if(f == NULL){
//        printf("開檔錯誤!");
//        break;
//    }
    int i;
    fprintf(f , "%-14s %-5d %c\n",name,num,sex);
}
void case3(){

}
void case4(){

}
int main(){
    float ave_com;
    float ave_math;
    int high_com = 0;
    int high_math = 0;
    int total_com = 0,total_math = 0;
    int high_score_com;
    int high_score_math;
    FILE* fp_r;
    FILE* fp_w;
    srand(time(NULL));
    int menu,i,tmp,j;
    stu tmp_stu;
    stu student[50];
    while(1)
    {
        printf("\n[1]Create [2]Print_Student [3]Print_Rank [4]Print_Avg [0]End : ");
        scanf(" %d",&menu);
        switch(menu)
        {
            case 1:  //原始資料產生
//                fp_r = fopen("name.txt","r");
//                if(fp_r == NULL){
//                    printf("開檔錯誤!");
//                    break;
//                }
                fp_r = openfile(0);
                if(fp_r == NULL){
                    printf("開檔錯誤!");
                    break;
                }
                for(i = 0;i < 50;i++){
                    fscanf(fp_r, "%s" ,student[i].name);
                }
                for(i = 0;i < 50;i++){
//                    student[i].number = i+1;
//                    tmp = (rand() % 2);
//                    if(tmp == 0){
//                        student[i].sex = 'F';
//                    }
//                    else{
//                        student[i].sex = 'M';
//                    }
//                    student[i].score_com = (rand() % 31) + 70;
//                    student[i].score_math = (rand() % 31) + 70;
                    case1(i,&student[i].number,&student[i].sex,&student[i].score_com,
                    &student[i].score_math);
                }
                for(i = 0;i < 50;i++){
                    printf("%s %c %d %d\n",student[i].name,student[i].sex,student[i].score_math,student[i].score_com);
                }
                fclose(fp_r);
                break;
            case 2:  //輸出學生資料
//                fp_w = fopen("student.txt","w");
//                if(fp_r == NULL){
//                    printf("開檔錯誤!");
//                    break;
//                }
                fp_w = openfile(1);
                if(fp_w == NULL){
                    printf("開檔錯誤!");
                    return -1;
                }
                fputs("學生姓名      號碼  性別\n-------------------------\n",fp_w);
//                for(i = 0;i < 50;i++){
//                    fprintf(fp_w , "%-14s %-5d %c\n",student[i].name,student[i].number,student[i].sex);
//                }

                for(i = 0;i < 50;i++){
                    case2(fp_w,student[i].name,student[i].number,student[i].sex);
                }
                fclose(fp_w);
                break;
            case 3:  //列印排序成績
                for(i = 0;i < 50;i++){
                    student[i].score_ave = ((float)student[i].score_com + (float)student[i].score_math)/2;
                }
                for(i = 0;i < 50;i++){
                    for(j = 0;j < 50-i;j++){
                        if(student[j].score_ave < student[j+1].score_ave){
                            tmp_stu = student[j];
                            student[j] = student[j+1];
                            student[j+1] = tmp_stu;
                        }
                        if(student[j].score_ave == student[j+1].score_ave){
                            if(student[j].score_com < student[j+1].score_com){
                                tmp_stu = student[j];
                                student[j] = student[j+1];
                                student[j+1] = tmp_stu;
                            }
                        }
                    }
                }
//                for(i = 0;i < 50;i++){
//                    if(student[i].score_ave == student[i+1].score_ave){
//                        if(student[i].score_com > student[i+1].score_com){
//                            tmp_stu = student[j];
//                            student[j] = student[j+1];
//                            student[j+1] = tmp_stu;
//                        }
//                    }
//                }
                printf("學生姓名  計概成績   微積分成績  平均成績   名次 \n------------------------------------------------\n");
                for(i = 0;i < 50;i++){
                    printf("%-14s %-10d %-10d %.1f %5d\n"
                    ,student[i].name,student[i].score_com,student[i].score_math,student[i].score_ave,i+1);
                }
                break;
            case 4:  //印出各科平均成績和該科目成績最高者
                high_score_com = student[0].score_com;
                high_score_math = student[0].score_math;
                for(i = 0;i < 50;i++){
                    total_com += student[i].score_com;
                    total_math += student[i].score_math;
                    if(high_score_com < student[i].score_com){
                        high_score_com = student[i].score_com;
                        high_com = i;

                    }
                    if(high_score_math < student[i].score_math){
                        high_score_math = student[i].score_math;
                        high_math = i;
                    }
                }
                ave_com = (float)total_com/50;
                ave_math = (float)total_math/50;
                printf("%.1f ,%.1f ,%s ,%s",ave_com,ave_math,student[high_com].name,student[high_math].name);
                break;
            case 0:  //結束程式執行
                printf("Exit!\n");
                exit(1);
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
}
