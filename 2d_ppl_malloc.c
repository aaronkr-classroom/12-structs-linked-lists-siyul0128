// 2d_ppl_malloc.c
// 2d_ppl_arr.c
#include <stdio.h>

int main(void) {
	int ages, member, temp, sum;
	unsigned char limit_table[3]; // 변경
	unsigned char* p[3]; // 변경

	// 입력 받기
	for (ages = 0; ages < 3; ages++) {
		printf("\n%d0대 연령의 윗몸 일으키기 횟수\n", ages + 2);
		printf("이 연령대는 몇 명입니까? >>> ");

		scanf_s("%d", &temp);
		limit_table[ages] = (unsigned char)temp; // 추가

		// 추가: 입력 받은 인원수만큼 메모리 할당
		p[ages] = (unsigned char*)malloc(limit_table[ages]);

		// 순서대로 입력 받기
		for (member = 0; member < limit_table[ages]; member++) {
			printf("멤버 #%d: ", member + 1); // #1

			scanf_s("%d", &temp);
			*(p[ages] + member) = (unsigned char)temp; // 변경
		}
	}

	printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");

	// 출력
	for (ages = 0; ages < 3; ages++) {
		sum = 0;
		printf("%d0대: ", ages + 2);
		for (member = 0; member < limit_table[ages]; member++) {
			sum = sum + *(p[ages] + member);
		}

		printf("%5.2f\n", (double)sum / limit_table[ages]);

		free(p[ages]);
	}
	return 0;
}