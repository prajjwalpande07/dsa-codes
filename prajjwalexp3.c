#include<stdio.h>

struct student
{
    int roll_no;
    float per;
    char name[20];
}s1;

void main()
{
    struct student s3;
    printf("Enter student name: ");
    scanf("%s", s1.name); 

    printf("Enter student roll_no: ");
    scanf("%d", &s1.roll_no); 

    printf("Enter student percentage: ");
    scanf("%f", &s1.per); 

    printf("\nStudent details are as follows:\n");
    printf("Roll No = %d\n", s1.roll_no);
    printf("Percentage = %.2f\n", s1.per); 
    printf("Name = %s\n", s1.name);
}