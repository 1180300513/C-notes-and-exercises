#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 10
#define NAME_LEN 30

typedef struct {
    int stu_id;
    char name[NAME_LEN];
    int total_socre;
} Student;

int main(void) {

    // 使用malloc函数在堆上申请空间,创建一个长度为10的int数组
    // 如果malloc成功会返回数组首元素地址
    int* arr_p = malloc(ARR_LEN * sizeof(int));     // 一定要用sizeof(int),而不是直接写4,因为不同平台int大小可能不同

    // 检查malloc是否成功,即检查arr_p是否是一个空指针
    if (arr_p == NULL) {
        printf("memory allocation failed!\n");
        return -1;  // 也可以exit(-1);结束程序
    }

    // malloc并不会初始化内存块，所以需要手动为动态分配的数组元素赋值
    for (int i = 0; i < ARR_LEN; i++) {
        arr_p[i] = i;
    }

    // 利用一个临时指针来遍历数组
    int* p = arr_p;     // p指针指向数组首元素
    for (int i = 0; i < ARR_LEN; i++) {
        printf("%d\n", *p++);
    }

    // 使用malloc函数在堆上申请空间,创建一个Student对象
    Student* s1 = malloc(sizeof(Student));

    if (s1 == NULL) {
        printf("memory allocation failed!\n");
        return -1;
    }

    s1->stu_id = 8;

    // 给结构体变量的name成员赋值
    // name的类型是一个字符数组类型,数组名是不允许直接"="赋值改变的,所以需要使用字符串复制函数
    strncpy(s1->name, "Jack", NAME_LEN - 1);
    s1->name[NAME_LEN - 1] = '\0';

    s1->total_socre = 700;

    return 0;
}