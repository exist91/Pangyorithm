//
//  프로그래밍 경진대회
//  동시 우승 가능이 아니고 가능성만 있으면 카운트 된다..
//  가능성은 다음 상황일 때 판단 가능
//  1. 내가 N점을 얻는다.
//  2. 나머지 응시자들이 가장 낮은 점수부터 마지막 라운드에서 2등을 한다.(따라서 2등 N-1점, 3등 N-2점.. 식으로 획득)
//  3. 내 점수 + N >= 2번의 점수들의 최대값 이면 우승 가능하다.(마지막 직전 라운드에서 중복점수가 있을수있다.. 주의해야함)
//  ex) 9명이고 점수가 4 6 7 7 7 8 8 8 8 이면 14점을 넘어야 우승 가능
//

#include <stdio.h>
#include <stdlib.h>

#define MAX(A,B) A > B ? A : B

//오름차순
int compare(const void *first, const void *second)
{
    if(*(int*)first > *(int*)second)
        return -1;
    else if(*(int*)first < *(int*)second)
        return 1;
    else
        return 0;
}


int main(void)
{
    setbuf(stdout, NULL);
    
    int TC, N;
    int test_case;
    int i, score, max, result;
    int *arr;
    
    scanf("%d", &TC);
    
    for(test_case = 1; test_case <= TC; test_case++)
    {
        max = 0; result = 0;
        scanf("%d", &N);
        
        arr = (int *)malloc(sizeof(int) * N);
        
        for(i = 0; i < N; i++)
        {
            scanf("%d", &score);
            
            arr[i] = score;
        }
        
        qsort(arr, N, sizeof(int), compare);
        
        for(i = 0; i < N; i++)
        {
            score = arr[i] + (i + 1);
            
            max = MAX(max, score);
        }
        
        for(i = 0; i < N; i++)
        {
            if(max <= arr[i] + N)
                result++;
        }
        
        printf("Case #%d\n", test_case);
        
        printf("%d\n", result);
        
        free(arr);
    }
    
    return 0;
}