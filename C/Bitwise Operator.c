#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k)
{
    int max_AND = 0;
    int max_OR = 0;
    int max_XOR = 0;
    
    for (int a = 1; a <= k; ++a)
    {
        for (int b = (a + 1); b <= n; ++b)
        {
            //printf("Intermed results for: a = %d, b = %d; a & b = %d; a | b = %d; a + b = %d\n", a, b, (a & b), (a | b), (a ^ b));
            max_AND = ((a & b) > max_AND ? ((a & b) < k ? (a & b) : max_AND) : max_AND);
            max_OR = ((a | b) > max_OR ? ((a | b) < k ? (a | b) : max_OR) : max_OR);
            max_XOR = ((a ^ b) > max_XOR ? ((a ^ b) < k ? (a ^ b) : max_XOR) : max_XOR);
        }
    }
    printf("%d\n%d\n%d\n", max_AND, max_OR, max_XOR);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
