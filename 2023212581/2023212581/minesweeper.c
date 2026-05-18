#include<stdio.h>

int size[2], select = 0, mine;

extern void create(int map[][50], int level);
extern int count(int map[][50], int x, int y);
extern void print_map(int map[][50]);
extern void flood_fill(int map[][50], char see[][50], int x, int y);

int main() {

	int level;
	int map[50][50], i, j;
	char see[50][50];
	printf("난이도를 입력하시오(1~3) : ");
	scanf_s("%d", &level);
	system("cls");
	level = (level < 1) ? 1 : (level > 3) ? 3 : level;
	create(map, level);

	for (i = 0;i < size[0];i++)
		for (j = 0;j < size[1];j++)
			see[i][j] = 'O';
	print_map(see);
	do {
		printf("x,y 좌표를 입력하시오(남은 지뢰 : %d 남은 칸 : %d x 범위 : 0 ~ %d y 범위 : 0 ~ %d)\n", mine, size[0] * size[1] - select, size[0] - 1, size[1] - 1);
		scanf_s("%d %d", &i, &j);
		system("cls");
		if (see[i][j] == 'O') {
			flood_fill(map, see, i, j);
			print_map(see);
		}
	} while (select < size[0] * size[1] - mine && map[i][j] != -1);
	if (map[i][j] == -1) {
		printf("펑 터졌습니다.\n");
	}
	else {
		printf("성공!\n");
	}
}

