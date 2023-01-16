#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//콜라 빈 병 2개를 가져다주면 콜라 1병을 주는 마트가 있다.빈 병 20개를 가져다주면 몇 병을 받을 수 있는가 ?
//
//단, 보유 중인 빈 병이 2개 미만이면, 콜라를 받을 수 없다.
//
//이를 일반화하여라.

int solution(int a, int b, int n) {
    int answer = 0;
    int remain = n;
    int get = 0;
    int count = 0;

    while (remain >= a)
    {
        get = remain / a;
        remain = remain % a;
        get = get * b;
        count = count + get;
        remain = remain + get;
    }

    answer = count;

    return answer;
}

void main()
{
    //출력확인하기
    int a = 3;
    int b = 1;
    int n = 20;
    int answer = solution(a, b, n);
    printf("answer is %d\n", answer);
}