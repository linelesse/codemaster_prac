#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//정수 n과 정수 배열 numlist가 매개변수로 주어질 때, numlist에서 n의 배수가 아닌 수들을 제거한 배열을 return하도록 solution 함수를 완성해주세요.

// numlist_len은 배열 numlist의 길이입니다.
int* solution(int n, int numlist[], size_t numlist_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int count = 0;
    int index = 0;

    for (int i = 0; i < numlist_len; i++)
    {
        if (numlist[i] % n == 0)
        {
            count++;
        }
    }
    int* answer = (int*)calloc(count, sizeof(int));
    for (int i = 0; i < numlist_len; i++)
    {
        if (numlist[i] % n == 0)
        {
            answer[index] = numlist[i];
            index++;
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    int numlist[9] = {4,5,6,7,8,9,10,11,12};
    int numlist_len = 9;

    //출력확인하기?
    solution(n, numlist, numlist_len);
;
}