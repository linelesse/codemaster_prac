#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//
//머쓱이는 행운의 숫자 7을 가장 좋아합니다.정수 배열 array가 매개변수로 주어질 때, 7이 총 몇 개 있는지 return 하도록 solution 함수를 완성해보세요.
// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    int digit;
    int sevcnt;
    int count = 0;
    int k = 1;


    for (int i = 0; i < array_len; i++)
    {
        int num = array[i];
        digit = 0;
        while (num != 0)
        {
            num = num / 10;
            digit++;
        }
        if (digit < 2)
        {
            if (array[i] % 10 == 7)
            {
                count++;
            }
        }
        else
        {
            for (int j = 0; j < digit; j++)
            {
                if (array[i] % 10 == 7)
                {
                    count++;
                }
                array[i] = array[i] / 10;
            }

        }
    }

    answer = count;

    return answer;
}

void main()
{
    int array[3] = { 7,77,17 };
    //출력확인하기
    int answer = solution(array, 3);
    printf("answer is %d\n", answer);
}