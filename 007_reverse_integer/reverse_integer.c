#include <stdio.h>

int reverse(int x){
#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)
    int r;
    while(1) {
        int d = x % 10;
        r += d;
        x /= 10;
        if(!x) break;
        if(r > INT_MAX/10 || (r == INT_MAX / 10 && d == 7)) return 0;
        if(r < INT_MIN/10 || (r == INT_MIN / 10 && d == 8)) return 0;
        r *= 10;
    }
    return r;
}

int main(int argc, char* argv[]) {
    int r = reverse(-123);
    printf("%d\n", r);

    return 0;
}