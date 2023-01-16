#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 마지막 원소 다음으로 올 숫자를 return 하도록 solution 함수를 완성해보세요.


//    2 < common의 길이 < 1, 000
//    - 1, 000 < common의 원소 < 2, 000
//    common의 원소는 모두 정수입니다.
//    등차수열 혹은 등비수열이 아닌 경우는 없습니다.
//    등비수열인 경우 공비는 0이 아닌 정수입니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int signA = 0;
    int signB = 0;

    //등차확인
    if (common[2] + common[0] == common[1] * 2)
    {
        signA = 1;
    }

    //등차아니면 등비이다.
    else
    {
        signB = 1;
    }



    //결과도출
    if (signA == 1 && signB == 0)
    {
        answer = common[common_len - 1] + (common[1] - common[0]);
    }

    if (signB == 1)
    {
        answer = common[common_len - 1] * (common[1] / common[0]);
    }


    return answer;
}

void main()
{
    int array[4] = { -2,4,-8,16 };
    //출력확인하기
    int answer = solution(array,4);
    printf("answer is %d\n", answer);
}