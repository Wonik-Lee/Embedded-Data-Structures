#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//100번 주사위를 던져서 빈도수를 구하는 프로그램 작성



int main()
{
	int freq[6] = { 0 };
	int n;

	printf("주사위를 굴릴 횟수 지정 : ");
	scanf("%d", &n);

	srand(time(NULL));//실행할때마다 다른 난수가 나오게 하는 설정

	for (int i = 0; i < n; i++) {
		int random = 1 + rand() % 6;
		freq[random - 1]++;
	}

	printf("\n\n100 trials\n");
	for (int i = 0; i < 6; i++) {
		printf("freq[%d] = %d\n", i + 1, freq[i]);
	}

	return 0;
}