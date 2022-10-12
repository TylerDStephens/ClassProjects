#include <stdio.h>
#include <string.h>
struct Student{
    char firstName[10];
    double grade;
};

int main() {
    struct Student student[10];
    char ch[10];
    int i = 0;
    int j = 0;
    while(  scanf("%s", ch) != EOF )
    {
        strcpy(student[i].firstName, ch);
        i = i + 1;
    }
    printf("\n");
    //temp array
    char arr[i][10];
    int array[i];
    for(j = 0; j < i; j++){
        strcpy(arr[j], student[j].firstName);
    }
    //Bubble Sort
    char temp[10];
    char temp1;
    int tempN[i];
    int tem;
    int y = 0;
    for(j = 0; j < i; j++){
     for( y = j +1; y < i; y++){
       if(strcmp(arr[j], arr[y]) > 0){
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[y]);
        strcpy(arr[y], temp);
       }
     }
    }
    for(j = 0; j < i; j++){
        strcpy(student[j].firstName, arr[j]);
    }
    for(j = 0; j != i; j++) {
        printf("\n%s", student[j].firstName);
    }
    printf("\n");
    return 0;
}
