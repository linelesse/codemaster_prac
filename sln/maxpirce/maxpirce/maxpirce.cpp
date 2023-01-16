#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



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

//과일 장수가 사과 상자를 포장하고 있습니다.사과는 상태에 따라 1점부터 k점까지의 점수로 분류하며, k점이 최상품의 사과이고 1점이 최하품의 사과입니다.사과 한 상자의 가격은 다음과 같이 결정됩니다.
//
//한 상자에 사과를 m개씩 담아 포장합니다.
//상자에 담긴 사과 중 가장 낮은 점수가 p(1 ≤ p ≤ k)점인 경우, 사과 한 상자의 가격은 p* m 입니다.
//과일 장수가 가능한 많은 사과를 팔았을 때, 얻을 수 있는 최대 이익을 계산하고자 합니다.(사과는 상자 단위로만 판매하며, 남는 사과는 버립니다)
//
//예를 들어, k = 3, m = 4, 사과 7개의 점수가[1, 2, 3, 1, 2, 3, 1]이라면, 다음과 같이[2, 3, 2, 3]으로 구성된 사과 상자 1개를 만들어 판매하여 최대 이익을 얻을 수 있습니다.
//
//(최저 사과 점수) x(한 상자에 담긴 사과 개수) x(상자의 개수) = 2 x 4 x 1 = 8
//사과의 최대 점수 k, 한 상자에 들어가는 사과의 수 m, 사과들의 점수 score가 주어졌을 때, 과일 장수가 얻을 수 있는 최대 이익을 return하는 solution 함수를 완성해주세요.
//
//제한사항
//3 ≤ k ≤ 9
//3 ≤ m ≤ 10
//7 ≤ score의 길이 ≤ 1, 000, 000
//1 ≤ score[i] ≤ k
//이익이 발생하지 않는 경우에는 0을 return 해주세요.

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    int i, j, temp;
    int trash;
    int product;
    int price = 0;

    //quick sort
    quickSort(score, 0, score_len - 1);

    product = score_len / m;
    trash = score_len % m;
    int* num = (int*)malloc((score_len - trash) * sizeof(int));

    for (i = 0; i < score_len - trash; i++)
    {
        num[i] = score[i + trash];
    }

    for (i = 0; i < product; i++)
    {
        answer = answer + num[m * i] * m;
    }

    free(num);

    return answer;
}

void main()
{
    int k = 4;
    int m = 3;
    int score[12] = {4,1,2,2,4,4,4,4,1,2,4,2};
    int score_len = 12;
    //출력확인하기
    int answer = solution(k, m, score, score_len);
    printf("%d", answer);
    
}