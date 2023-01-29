//0부터 9까지의 숫자 중 일부가 들어있는 정수 배열 numbers가 매개변수로 주어집니다.
//numbers에서 찾을 수 없는 0부터 9까지의 숫자를 모두 찾아 더한 수를 return 하도록 solution 함수를 완성해주세요.
//
//1 ≤ numbers의 길이 ≤ 9
//0 ≤ numbers의 모든 원소 ≤ 9
//numbers의 모든 원소는 서로 다릅니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int* blanknum = (int*)calloc(10, sizeof(int));

    for (int i = 0; i < numbers_len; i++)
    {
        if (numbers[i] == 0)
        {
            blanknum[0] = 1;
        }
        if (numbers[i] == 1)
        {
            blanknum[1] = 1;
        }
        if (numbers[i] == 2)
        {
            blanknum[2] = 1;
        }
        if (numbers[i] == 3)
        {
            blanknum[3] = 1;
        }
        if (numbers[i] == 4)
        {
            blanknum[4] = 1;
        }
        if (numbers[i] == 5)
        {
            blanknum[5] = 1;
        }
        if (numbers[i] == 6)
        {
            blanknum[6] = 1;
        }
        if (numbers[i] == 7)
        {
            blanknum[7] = 1;
        }
        if (numbers[i] == 8)
        {
            blanknum[8] = 1;
        }
        if (numbers[i] == 9)
        {
            blanknum[9] = 1;
        }


    }
    for (int i = 0; i < 10; i++)
    {
        if (blanknum[i] == 0)
        {
            answer += i;
        }
    }




    return answer;
}

void main()
{
    int numbers_len = 8;
    int numbers[8] = { 1,2,3,4,6,7,8,0 };
    int answer = 0;

    answer = solution(numbers, numbers_len);
    
    //출력확인하기?
    printf("%d\n", answer);
}