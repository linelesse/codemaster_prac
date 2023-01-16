#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//���� n�� �Ű������� �־��� �� n�� �� �ڸ� ������ ���� return�ϵ��� solution �Լ��� �ϼ����ּ���
//0 �� n �� 1,000,000
//����� ��
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
    //���Ȯ���ϱ�
    int answer = solution(930211);
    printf("answer is %d\n", answer);
}