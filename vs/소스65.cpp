#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STUDENT_NUM 5
#define COURSE_NUM 3

int main()
{
    float grade[STUDENT_NUM][COURSE_NUM];
    float sumS[STUDENT_NUM] = { 0, };
    float sumC[COURSE_NUM] = { 0, };
    int i, j;

    for (i = 0; i < STUDENT_NUM; i++)
    {
        printf("Type %d th student grade\n", i + 1);
        for (j = 0; j < COURSE_NUM; j++)
        {
            scanf_s("%f", &grade[i][j]);
            sumS[i] += grade[i][j];
            sumC[j] += grade[i][j];
        }
    }

    for (i = 0; i < STUDENT_NUM; i++)
        printf("Student(%d) average: %f\n", i + 1, sumS[i] / COURSE_NUM);
    for (j = 0; j < COURSE_NUM; j++)
        printf("Course (%d) average: %f\n", j + 1, sumC[j] / STUDENT_NUM);

    return 0;
}
