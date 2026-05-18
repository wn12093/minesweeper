#include<stdlib.h>
#include <time.h>
extern int size[2], mine, select;

void create(int map[][50], int level) {
	srand((unsigned)time(NULL));
	int r1, r2;
	if (level == 1) {
		size[0] = 9;
		size[1] = 9;
		mine = 10;
	}
	else if (level == 2) {
		size[0] = 16;
		size[1] = 16;
		mine = 40;
	}
	else {
		size[0] = 16;
		size[1] = 30;
		mine = 99;
	}
	for (int i = 0;i < size[0];i++) {
		for (int j = 0;j < size[1];j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0;i < mine;i++) {
		do {
			r1 = rand() % size[0];
			r2 = rand() % size[1];
		} while (map[r1][r2] == -1);
		map[r1][r2] = -1;
	}
	for (int i = 0;i < size[0];i++) {

		for (int j = 0;j < size[1];j++) {
			if (map[i][j] != -1) {
				map[i][j] = count(map, i, j);
			}
		}
	}
}

int count(int map[][50], int x, int y) {
	int c = 0;
	if (map[x - 1][y - 1] == -1) {
		c++;
	}
	if (map[x - 1][y] == -1) {
		c++;
	}
	if (map[x - 1][y + 1] == -1) {
		c++;
	}
	if (map[x][y + 1] == -1) {
		c++;
	}
	if (map[x + 1][y + 1] == -1) {
		c++;
	}
	if (map[x + 1][y] == -1) {
		c++;
	}
	if (map[x + 1][y - 1] == -1) {
		c++;
	}
	if (map[x][y - 1] == -1) {
		c++;
	}
	return c;
}
void print_map(char map[][50]) {
	printf(" ");
	for (int j = 0;j < size[1];j++) {
		printf("_%d", j % 10);
	}
	printf("\n");
	for (int i = 0;i < size[0];i++) {
		printf("%d|", i % 10);
		for (int j = 0;j < size[1];j++) {
			if (map[i][j] == 'O')
				printf("_|");
			else {
				printf("%c", map[i][j]);
				if (map[i][j + 1] == 'O')
					printf("|");
				else  printf(" ");
			}
		}
		printf("\n");
	}
}

void flood_fill(int map[][50], char see[][50], int x, int y) {
	if (x >= 0 && x < size[0] && y >= 0 && y < size[1] && see[x][y] == 'O') {
		select++;
		if (map[x][y] != 0) {
			if (map[x][y] == -1) {
				for (int i = 0;i < size[0];i++) {
					for (int j = 0;j < size[1];j++) {
						if (map[i][j] == -1)
							see[i][j] = 'x';
					}
				}
				see[x][y] = 'X';
			}
			else	see[x][y] = map[x][y] + 48;
		}
		else {
			see[x][y] = ' ';
			flood_fill(map, see, x + 1, y);
			flood_fill(map, see, x - 1, y);
			flood_fill(map, see, x, y - 1);
			flood_fill(map, see, x, y + 1);
			flood_fill(map, see, x + 1, y + 1);
			flood_fill(map, see, x - 1, y - 1);
			flood_fill(map, see, x + 1, y - 1);
			flood_fill(map, see, x - 1, y + 1);
		}
	}
}