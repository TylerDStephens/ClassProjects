#include <stdio.h>
#include <string.h>
struct Student{
    char firstName[10];
    double grade;
};
int main() {
    struct Student student[10];
    char ch[10];
    double x;
    int i = 0;
    while(scanf("%s %lf", ch, &x) != EOF )
    {
        strcpy(student[i].firstName, ch);
        student[i].grade = x;
        i = i + 1;
    }
    int j;
    for(j=0; j <= i; j++){
        if( student[j].grade > 3.0) {
            printf("\n%s", student[j].firstName);
        }
    }
    printf("\n");
    return 0;
}
