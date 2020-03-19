#include <stdio.h>

int romanToInt(char* s) {
	int total = 0;
	while (*s != '\0') {
		char next = *(s + 1);
		switch (*s) {
		case 'I':
			if (next == 'V' || next == 'X') {
				total -= 1;
			} else {
				total += 1;
			}
			break;
		case 'V':
			total += 5;
			break;
		case 'X':
			if (next == 'L' || next == 'C') {
				total -= 10;
			} else {
				total += 10;
			}
			break;
		case 'L':
			total += 50;
			break;
		case 'C':
			if (next == 'D' || next == 'M') {
				total -= 100;
			} else {
				total += 100;
			}
			break;
		case 'D':
			total += 500;
			break;
		case 'M':
			total += 1000;
			break;
		default:
			break;
		}

		s++;
	}

	return total;
}

int main(int argc, char* argv[]) {
	printf("%d\n", romanToInt("III"));
	printf("%d\n", romanToInt("IV"));
	printf("%d\n", romanToInt("IX"));
	printf("%d\n", romanToInt("LVIII"));
	printf("%d\n", romanToInt("MCMXCIV"));
}