#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
	if (x < 0) return false;

	unsigned int tmp = x;
	unsigned int reverse = 0;

	while (tmp != 0) {
		reverse *= 10;
		reverse += tmp % 10;
		tmp /= 10;
	}
	printf("%d == %d\n", x, reverse);

	return (unsigned int)x == reverse;
}

int main(int argc, char* argv[]) {
	if (isPalindrome(121)) {
		printf("palindrome\n");
	} else {
		printf("not palindrome\n");
	}

	if (isPalindrome(-121)) {
		printf("palindrome\n");
	} else {
		printf("not palindrome\n");
	}

	if (isPalindrome(10)) {
		printf("palindrome\n");
	} else {
		printf("not palindrome\n");
	}

	if (isPalindrome(2147483647)) {
		printf("palindrome\n");
	} else {
		printf("not palindrome\n");
	}

	return 0;
}