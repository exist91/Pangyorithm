//
//  숫자 골라내기
//  같은 숫자를 두번 XOR연산하면 0
//

#include <stdio.h>

int main(void) {
   	
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    int i;
    int count;
    int input;
    int result = 0;
    
    scanf("%d", &TC);
    
    for(test_case = 1; test_case <= TC; test_case++)
    {
        scanf("%d", &count);
        
        for(i = 0; i < count; i++)
        {
            scanf("%d", &input);
            
            result ^= input;
        }
        
        printf("Case #%d\n", test_case);
        
        printf("%d\n", result);
        
        result = 0;
    }
    
    return 0;
}