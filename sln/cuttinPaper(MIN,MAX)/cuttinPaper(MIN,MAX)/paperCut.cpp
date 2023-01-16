#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

int solution(int M, int N) {
    int answer = 0;
    int first = 0;
    int second = 0;
    int firstcut = 0;
    int secondcut = 0;

    if (M == 1 && N == 1)
    {

    }

    else
    {
        first = MIN(M, N);
        second = MAX(M, N);

        firstcut = first - 1;
        secondcut = first * (second - 1);
    }


    answer = firstcut + secondcut;

    return answer;
}

void main()
{
    //출력확인하기
    int M = 3;
    int N = 5;
    int answer = solution(M,N);
    printf("answer is %d\n", answer);
}