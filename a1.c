#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 따로 이름을 지정하고 싶다면 typedef 사용할것! 
typedef struct employee{
    char *name;
    int num;
    char *phone_num;
    int age;
}EMPLOYEE;

void get_min_max_age(char *cond, int input[2]){
    char *ptr = strtok(cond," ");
    input[0]=atoi(ptr);
    ptr = strtok(NULL," ");
    input[1]=atoi(ptr);
}


int main(){
    char *all_cond;
    int search_type;
    char *search_cond;

    // 예시로 2개만 사용합니다. 
    EMPLOYEE employ_list[2]={
        {"Jeon",123, "2345-7890",32},
        {"Kim",125, "3458-9990", 22}
    };

    scanf("%[^\n]s",all_cond); // 공백으로 입력받음 

    // 한줄로 입력받아야 하므로 첫번재 숫자는 type으로 두 번째부터 마지막은 조건으로 나눈다. 
    char *ptr = strtok(all_cond," ");
    search_type = atoi(ptr);
    search_cond = strtok(NULL,"\n");
    // printf("Type:%d, Cond: %s\n",,search_type,search_cond);
    int cond[2];
    get_min_max_age(search_cond,cond);
    
    // printf("%d %d",cond[0],cond[1]);

    
    for(int i = 0 ; i < 2; i++){
        int check = 0;

        if(search_type==4){
            // int *age_cond = get_min_max_age(search_cond);
            if(cond[0] <=employ_list[i].age && employ_list[i].age<=cond[1]){
                check = 1;
            }
        }

        if(check==1){
            printf("%s %d %s %d\n",employ_list[i].name, employ_list[i].num, employ_list[i].phone_num, employ_list[i].age);
        }

    }

}