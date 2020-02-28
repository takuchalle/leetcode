#include <stdio.h>

int reverse(int x){
#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)
    int r;
    while(1) {
        r += x % 10;
        x /= 10;
        if(!x) break;
        if(r > INT_MAX/10 || r < INT_MIN/10) {
            r = 0;
            break;
        }
        r *= 10;
    }
    return r;
}

int main(int argc, char* argv[]) {
    int r = reverse(-123);
    printf("%d\n", r);

    return 0;
}