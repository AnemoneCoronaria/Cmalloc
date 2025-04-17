//
// Created by Anemone on 25. 4. 17.
//

#define MAX_SIZE 8
typedef int Element;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

typedef struct digits {
    int* x1;
    int* x2;
} digits;

// 전달받은 정수 n의 각 자릿수를 분리하여 배열 arr에 저장하는 함수
void split_number(int n, int* arr, int size)
// n 자릿수 분리할 정수, arr 동적 할당된 배열, size 정수의 자릿수(배열크기)
{
    for (int i = size - 1; i >= 0; i--) // 역순 저장
    {
        arr[i] = n % 10;
        n /= 10;    // 마지막 자릿수 제거
    }
}

// 자릿수 구하는 함수
int get_size(int n) {
    if (n == 0) return 1;   // n이 0이면 1을 반환

    int size = 0;
    while (n > 0)
    {
        n /= 10;    // 10으로 나누며 몫을 구하고(0부터 9까지 10개니까...)
        size++;    // 카운트 증가
    }
    // if (size != 0)
    // {
    //     return size;      이거 필요 없음
    // }

    return size;    // 반환하는거 없었어서 추가함
}



int main() {
    int num1 = 500;
    int num2 = 10000;

    //scanf("%d %d", &num1, &num2);   // 입력 받고

    // size1, size2에
    int size1 = get_size(num1);
    int size2 = get_size(num2);

    digits d;   // 구조체 생성

    // d.x1 = (int*)malloc(sizeof(int) * get_size(num1));
    // d.x2 = (int*)malloc(sizeof(int) * get_size(num2));

    // 동적 할당 (사실상 기존 코드와 동일... 다만 위에 따로 변수로 선언했을 뿐)
    d.x1 = (int*)malloc(sizeof(int) * size1);
    d.x2 = (int*)malloc(sizeof(int) * size2);


    split_number(num1, d.x1, size1);
    split_number(num2, d.x2, size2);


    printf("num1의 자릿수 : %d 자리\n", get_size(num1));
    printf("num2의 자릿수 : %d 자리\n", get_size(num2));
    // printf("%d\n", sizeof(d.x1) * sizeof(int));
    // printf("%d\n", sizeof(d.x2) * sizeof(int));
    // printf("%d\n", sizeof(d) * sizeof(int));
    printf("num1 배열을 위한 메모리 크기 : %d\n", size1 * (int)sizeof(int));  // 자릿수 * 정수(4바이트) -> 2자리면 4바이트짜리 2개 -> 즉, 8바이트 필요
    printf("num2 배열을 위한 메모리 크기 : %d\n", size2 * (int)sizeof(int));
    printf("구조체 digits의 크기 : %d\n", (int)sizeof(d));
    printf("구조체 digits의 크기 (동적) : %d\n", size1 * sizeof(int) + size2 * sizeof(int));
    //printf("Usable: %lu bytes\n", malloc_usable_size(d.x1));         // 리눅스에서 malloc 할당 크기 구하기
    printf("Allocated (usable) d.x1 : %zu bytes\n", _msize(d.x1));    // 윈도우에서 malloc 할당 크기 구하기
    printf("Allocated (usable) d.x2 : %zu bytes\n", _msize(d.x2));


    free(d.x1);
    free(d.x2);


}

// void split_number(int n)
// {
//     int temp = n;
//     int size = 0;
//
//     for (int i = 0; temp > 9; i++)
//     {
//         temp /= 10;
//         size = i;
//     }
// }

