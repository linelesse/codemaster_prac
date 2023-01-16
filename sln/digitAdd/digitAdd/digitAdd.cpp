#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//정수 n이 매개변수로 주어질 때 n의 각 자리 숫자의 합을 return하도록 solution 함수를 완성해주세요
//0 ≤ n ≤ 1,000,000
//입출력 예
//  n	        result
//  1234	    10
//  930211	    16

int solution(int n) {
    int answer = 0;
    int numcount = 0;
    int num = n;

    while (num != 0)
    {
        num = num / 10;
        numcount++;
    }
    if (n > 0)
    {
        int* number = (int*)calloc(numcount - 1, sizeof(int));
        for (int i = 0; i < numcount; i++)
        {
            int digit = 1;
            for (int j = 0; j < numcount - 1 - i; j++)
            {
                digit = digit * 10;
            }
            number[i] = n / digit;
            n = n % digit;
            answer = answer + number[i];
        }

    }

    return answer;
}

void main()
{
    //출력확인하기
    int answer = solution(930211);
    printf("answer is %d\n", answer);
}