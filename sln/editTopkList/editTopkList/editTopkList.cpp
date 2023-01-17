#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//이 프로그램에서는 매일 "명예의 전당"의 최하위 점수를 발표합니다.예를 들어, k = 3이고, 7일 동안 진행된 가수의 점수가[10, 100, 20, 150, 1, 100, 200]이라면,
//명예의 전당에서 발표된 점수는 아래의 그림과 같이[10, 10, 10, 20, 20, 100, 100]입니다.
//명예의 전당 목록의 점수의 개수 k, 1일부터 마지막 날까지 출연한 가수들의 점수인 score가 주어졌을 때, 매일 발표된 명예의 전당의 최하위 점수를 return하는 solution 함수를 완성해주세요.

void quickSort(int arr[], int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
    int temp;
    do
    {
        while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
            left++;
            right--;
        }
    } while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

  /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

    if (left < R)
        quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(score_len * sizeof(int));
    int* tmpScore = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
    {
        tmpScore[i] = score[i];
    }

    answer[0] = score[0];

    for (int i = 1; i < k; i++)
    {
        if (score[i] < score[0])
        {
            score[0] = score[i];
        }
        answer[i] = score[0];
    }

    quickSort(tmpScore, 0, k - 1);


    for (int i = k; i < score_len; i++)
    {
        if (score[i] > tmpScore[0])
        {
            tmpScore[0] = score[i];
            quickSort(tmpScore, 0, k - 1);

        }
        answer[i] = tmpScore[0];
    }


    return answer;
}

void main()
{
    int k = 4;
    int score[10] = { 0,300,40,300,20,70,150,50,500,1000 };
    int score_len = 10;
    //출력확인하기
    int* answer = solution(k, score, score_len);
    
    for (int i = 0; i < score_len; i++)
    {
        printf("%d ", answer[i]);
    }

}