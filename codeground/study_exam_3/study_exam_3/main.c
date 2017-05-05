//
//  시험 공부
//  N개 입력 받은후 정렬해서 상위 K개의 합 출력
//

#include <stdio.h>
#include <stdlib.h>

//내림차순
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
    
    int TC, N, K;
    int test_case;
    int i, result, score;
    int *arr;
    
    scanf("%d", &TC);
    for(test_case = 1; test_case <= TC; test_case++)
    {
        result = 0;
        
        scanf("%d %d", &N, &K);
        
        arr = (int *)malloc(sizeof(int) * N);
        
        for(i = 0; i < N; i++)
        {
            scanf("%d", &score);
            
            arr[i] = score;
        }
        
        qsort(arr, N, sizeof(int), compare);
        
        for(i = 0; i < K; i++)
        {
            result += arr[i];
        }
            
        printf("Case #%d\n", test_case);
        printf("%d\n", result);
    }
    
    return 0;
}