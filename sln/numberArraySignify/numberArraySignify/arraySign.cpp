#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//�������� Ȥ�� ������ common�� �Ű������� �־��� ��, ������ ���� �������� �� ���ڸ� return �ϵ��� solution �Լ��� �ϼ��غ�����.


//    2 < common�� ���� < 1, 000
//    - 1, 000 < common�� ���� < 2, 000
//    common�� ���Ҵ� ��� �����Դϴ�.
//    �������� Ȥ�� �������� �ƴ� ���� �����ϴ�.
//    �������� ��� ����� 0�� �ƴ� �����Դϴ�.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len�� �迭 common�� �����Դϴ�.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len�� �迭 common�� �����Դϴ�.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int signA = 0;
    int signB = 0;

    //����Ȯ��
    if (common[2] + common[0] == common[1] * 2)
    {
        signA = 1;
    }

    //�����ƴϸ� ����̴�.
    else
    {
        signB = 1;
    }



    //�������
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
    //���Ȯ���ϱ�
    int answer = solution(array,4);
    printf("answer is %d\n", answer);
}