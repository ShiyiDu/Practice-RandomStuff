#include <stdio.h>

int main(void) {
	short puzzle[4][4];
	short merge_mark[4][4];
	short direction;
	
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++){
			scanf("%hd", &puzzle[r][c]);
			merge_mark[r][c] = 0;
		}
	}
	
	scanf("%hd", &direction);
	
	switch (direction) {
		case 0:
			for (int r = 0; r < 4; r++) {
				for(int c = 0; c < 4; c++){
					if(puzzle[r][c] != 0){
						for(int i = c; i > 0; i--){
							if(puzzle[r][i - 1] == 0) {
								puzzle[r][i - 1] = puzzle[r][i];
								puzzle[r][i] = 0;
							}else if(puzzle[r][i - 1] == puzzle[r][i] && puzzle[r][i - 1] != 2048){
								if(merge_mark[r][i - 1]) break;
								puzzle[r][i]= 0;
								puzzle[r][i - 1] *= 2;
								merge_mark[r][i - 1] = 1;
								break;
							}else {
								break;
							}
						}
					}
				}
			}
			break;
		case 1:
			for (int c = 0; c < 4; c++) {
				for(int r = 0; r < 4; r++){
					if(puzzle[r][c] != 0){
						for(int i = r; i > 0; i--){
							if(puzzle[i - 1][c] == 0) {
								puzzle[i - 1][c] = puzzle[i][c];
								puzzle[i][c] = 0;
							}else if(puzzle[i - 1][c] == puzzle[i][c] && puzzle[i - 1][c] != 2048){
								if(merge_mark[i - 1][c]) break;
								puzzle[i][c]= 0;
								puzzle[i - 1][c] *= 2;
								merge_mark[i - 1][c] = 1;
								break;
							}else {
								break;
							}
						}
					}
				}
			}
			break;
		case 2:
			for (int r = 0; r < 4; r++) {
				for(int c = 3; c >= 0; c--){
					if(puzzle[r][c] != 0){
						for(int i = c; i < 3; i++){
							if(puzzle[r][i + 1] == 0) {
								puzzle[r][i + 1] = puzzle[r][i];
								puzzle[r][i] = 0;
							}else if(puzzle[r][i + 1] == puzzle[r][i] && puzzle[r][i + 1] != 2048){
								if(merge_mark[r][i + 1]) break;
								puzzle[r][i]= 0;
								puzzle[r][i + 1] *= 2;
								merge_mark[r][i + 1] = 1;
								break;
							}else {
								break;
							}
						}
					}
				}
			}
			break;
		case 3:
			for (int c = 0; c < 4; c++) {
				for(int r = 3; r >= 0; r--){
					if(puzzle[r][c] != 0){
						for(int i = r; i < 3; i++){
							if(puzzle[i + 1][c] == 0) {
								puzzle[i + 1][c] = puzzle[i][c];
								puzzle[i][c] = 0;
							}else if(puzzle[i + 1][c] == puzzle[i][c] && puzzle[i + 1][c] != 2048){
								if(merge_mark[i + 1][c]) break;
								puzzle[i][c]= 0;
								puzzle[i + 1][c] *= 2;
								merge_mark[i + 1][c] = 1;
								break;
							}else {
								break;
							}
						}
					}
				}
			}
			break;
		default:
			break;
	}
	
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++){
			printf("%hd ", puzzle[r][c]);
		}
		printf("\n");
	}
}