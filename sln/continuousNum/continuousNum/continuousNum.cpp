#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num, int total) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(num, sizeof(int));
    int avgNum = 0;
    int digit;
    int firstNum;

    if (num % 2 == 0)
    {
        digit = num / 2;
        avgNum = total / num;
        firstNum = avgNum - digit + 1;
        for (int i = 0; i < num; i++)
        {
            answer[i] = firstNum + i;
        }
    }

    else
    {
        digit = num / 2;
        avgNum = total / num;
        firstNum = avgNum - digit;
        for (int i = 0; i < num; i++)
        {
            answer[i] = firstNum + i;
        }
    }




    return answer;
}

void main()
{
    //출력확인하기
    int num = 3;
    int total = 12;
    int* answer = (int*)calloc(num, sizeof(int));
    answer = solution(num, total);
    for (int i = 0; i < num; i++)
    {
        printf("answer is %d\n", answer[i]);
    }
    
}