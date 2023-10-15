#include <stdio.h>

int main () {
	int i;
	for (i = 0; i <= 10; i++) {
		printf("%.3d\n", i);
	}
	while (i-- > 0) {
		printf("%.3d\n", i);
	}
	printf("Int %lu bytes.\n", sizeof(i));
	return 0;
}
