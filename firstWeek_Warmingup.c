#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//100�� �ֻ����� ������ �󵵼��� ���ϴ� ���α׷� �ۼ�



int main()
{
	int freq[6] = { 0 };
	int n;

	printf("�ֻ����� ���� Ƚ�� ���� : ");
	scanf("%d", &n);

	srand(time(NULL));//�����Ҷ����� �ٸ� ������ ������ �ϴ� ����

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