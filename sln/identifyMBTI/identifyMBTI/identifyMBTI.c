#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



//나만의 카카오 성격 유형 검사지를 만들려고 합니다.
//성격 유형 검사는 다음과 같은 4개 지표로 성격 유형을 구분합니다.성격은 각 지표에서 두 유형 중 하나로 결정됩니다.
//
//지표 번호	성격 유형
//1번 지표	라이언형(R), 튜브형(T)
//2번 지표	콘형(C), 프로도형(F)
//3번 지표	제이지형(J), 무지형(M)
//4번 지표	어피치형(A), 네오형(N)
//4개의 지표가 있으므로 성격 유형은 총 16(= 2 x 2 x 2 x 2)가지가 나올 수 있습니다.예를 들어, "RFMN"이나 "TCMA"와 같은 성격 유형이 있습니다.
//
//검사지에는 총 n개의 질문이 있고, 각 질문에는 아래와 같은 7개의 선택지가 있습니다.
//
//매우 비동의
//비동의
//약간 비동의
//모르겠음
//약간 동의
//동의
//매우 동의
//각 질문은 1가지 지표로 성격 유형 점수를 판단합니다.
//
//예를 들어, 어떤 한 질문에서 4번 지표로 아래 표처럼 점수를 매길 수 있습니다.
//
//선택지	성격 유형 점수
//매우 비동의	네오형 3점
//비동의	네오형 2점
//약간 비동의	네오형 1점
//모르겠음	어떤 성격 유형도 점수를 얻지 않습니다
//약간 동의	어피치형 1점
//동의	어피치형 2점
//매우 동의	어피치형 3점


// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(4 * sizeof(char));
    int type1;
    int type2;
    int add = 0;

    char* charArray[8] = { "RT","TR","FC", "CF", "MJ", "JM", "AN", "NA" };

    int typeR = 0;
    int typeT = 0;
    int typeC = 0;
    int typeF = 0;
    int typeJ = 0;
    int typeM = 0;
    int typeA = 0;
    int typeN = 0;

    for (int i = 0; i < survey_len; i++)
    {
        type1 = 0;
        type2 = 0;
        //점수 정하기
        if (choices[i] < 4)
        {
            type1 = (4 - choices[i]);
        }
        else if (choices[i] > 4)
        {
            type2 = (choices[i] - 4);
        }

        //성향정하기
        for (int j = 0; j < 8; j++)
        {
            if (strcmp(survey[i], charArray[j]) == 0)
            {
                if (j == 0)
                {
                    //RT
                    typeR += type1;
                    typeT += type2;
                }
                if (j == 1)
                {
                    //TR
                    typeT += type1;
                    typeR += type2;
                }
                if (j == 2)
                {
                    //FC
                    typeF += type1;
                    typeC += type2;
                }
                if (j == 3)
                {
                    //CF
                    typeC += type1;
                    typeF += type2;
                }
                if (j == 4)
                {
                    //MJ
                    typeM += type1;
                    typeJ += type2;
                }
                if (j == 5)
                {
                    //JM
                    typeJ += type1;
                    typeM += type2;
                }
                if (j == 6)
                {
                    //AN
                    typeA += type1;
                    typeN += type2;
                }
                if (j == 7)
                {
                    //NA
                    typeN += type1;
                    typeA += type2;
                }
            }
        }

    }
    if (typeR >= typeT)
    {
        add += 1000;
    }
    if (typeR < typeT)
    {
        add += 2000;
    }

    if (typeC >= typeF)
    {
        add += 100;
    }
    if (typeC < typeF)
    {
        add += 200;
    }

    if (typeJ >= typeM)
    {
        add += 10;
    }
    if (typeJ < typeM)
    {
        add += 20;
    }

    if (typeA >= typeN)
    {
        add += 1;
    }
    if (typeA < typeN)
    {
        add += 2;
    }

    if (add == 1111)
    {
        answer = "RCJA";
    }
    if (add == 1112)
    {
        answer = "RCJN";
    }
    if (add == 1121)
    {
        answer = "RCMA";
    }
    if (add == 1211)
    {
        answer = "RFJA";
    }
    if (add == 2111)
    {
        answer = "TCJA";
    }
    if (add == 1122)
    {
        answer = "RCMN";
    }
    if (add == 1212)
    {
        answer = "RFJN";
    }
    if (add == 2112)
    {
        answer = "TCJN";
    }
    if (add == 1221)
    {
        answer = "RFMA";
    }
    if (add == 2121)
    {
        answer = "TCMA";
    }
    if (add == 2211)
    {
        answer = "TFJA";
    }
    if (add == 1222)
    {
        answer = "RFMN";
    }
    if (add == 2122)
    {
        answer = "TCMN";
    }
    if (add == 2212)
    {
        answer = "TFJN";
    }
    if (add == 2221)
    {
        answer = "TFMA";
    }
    if (add == 2222)
    {
        answer = "TFMN";
    }
    printf("%s\n", answer);
    return answer;
}

int main()
{
    int survey_len = 5;
    char* survey[5] = { "AN","CF","MJ","RT","NA" };
    int choices[5] = { 5,3,2,7,5 };
    int choices_len = 5;

    //출력확인하기?
    solution(survey, survey_len,choices,choices_len);
    
}