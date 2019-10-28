#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int RunSimulation(int number, int times);
int WonTheGame(int dia_index);
int GetDiagnal(int exclude_tie);
int CheckDiagnal(int dia_index);
int ContainNum(int num);
int GetNewNumber();
int GetNewSpot();
int Play(int start_num);

int num_map[9];
int player_map[9];
int possible_win[8][3] = {
	0,3,6,
	1,4,7,
	2,5,8,
	0,1,2,
	3,4,5,
	6,7,8,
	0,4,8,
	2,4,6
};

//0 = first player, 1 = second player
int main(int argc, char *argv[]) {
//	printf("%d\n", Play(5));
	
//	int result = Play(5);
//	int counter = 0;
//	while (result == 2) {
//		result = Play(5);
//		counter ++;
//		if(counter >= 10000) break;
//	}
//	
//	printf("%d\n", result);
//	
//	for(int i = 0; i < 9; i++){
//		if(i%3==0)printf("\n");
//		printf("(%d,", num_map[i]);
//		printf("%d)", player_map[i]);
//	}
	
//	RunSimulation(5, 1000);
	for(int i = 1; i <= 5; i++){
		printf("\nSimulation %d", i);
		for(int j = 1; j <= 9; j++){
			RunSimulation(j, 1000000);
		}	
	}
}

int RunSimulation(int number, int times){
	int win = 0, lose = 0, tie = 0;
	for(int i = 0; i < times; i++){
		switch (Play(number)) {
			case 0:
				lose++;
				break;
			case 1:
				win++;
				break;
			case 2:
				tie++;
				break;
		}
	}
	
	printf("\n Simulation with number %d for %d times, win: %d, lose: %d, tie: %d", number, times, win, lose, tie);
	return 1;
}

//0 lose, 1 win, 2 tie
//generate a number map randomly and a player map accordingly
int Play(int start_num){
	//initialize the map
	int result = 2;
	
	for(int i = 0; i < 9; i++){
		num_map[i] = -100;
		player_map[i] = -1;
	}
	
	//if diagnal exists, check the belonging player
	//if no diagnal, tie
	num_map[4] = start_num;
	player_map[4] = 0;
	
	int current_player = 1;
	for(int i = 0; i < 8; i++) {
		int new_num = GetNewNumber();
		int new_spot = GetNewSpot();
		
		num_map[new_spot] = new_num;
		player_map[new_spot] = current_player;
		
		current_player = !current_player;
		
		int diagnal = GetDiagnal(i!=7);
		if(diagnal == -1) continue;
//		printf("diagnal: %d\n", diagnal);
		result = WonTheGame(diagnal);
		break;
	}
	
	return result;
}

int GetNewSpot(){
	int result = rand() % 9;
	while(num_map[result] != -100) result = rand() % 9;
	return result;
}

//get a new number that hasn't been there before
int GetNewNumber(){
	int result = rand() % 9 + 1;
	while (ContainNum(result)) {
		result = rand() % 9 + 1;
	}
	return result;
}

int ContainNum(int num){
	for(int i = 0; i < 9; i++){
		if(num_map[i] == num) return 1;
	}
	return 0;
}

//check if there is a diagnal line that adds up to 15 and return that diagnal line
int GetDiagnal(int exclude_tie){
	for(int i = 0; i < 8; i++){
		if(CheckDiagnal(i)) {
			if(exclude_tie){
				if(WonTheGame(i) == 2) continue;
				return i;
			}else {
				return i;
			}
		}
	}
	return -1;
}

//check if the specified diagnal line adds up to 15
int CheckDiagnal(int dia_index){
	int sum = 0;
	
	for(int i = 0; i < 3; i++){
		sum += num_map[possible_win[dia_index][i]];
	}
	
//	foreach(int i in possible_win[dia_index]){
//		sum += num_map[i];
//	}
	return sum == 15;
}

//if belongs to player 1, lose, return 0, if player 0, win return 1, else tie
int WonTheGame(int dia_index){
	int player_on_first_square = player_map[possible_win[dia_index][0]];
	
	for(int i = 0; i < 3; i++){
		if(player_map[possible_win[dia_index][i]] == player_on_first_square) continue;
		return 2;
	}
//	
//	foreach(int i in possible_win[dia_index]){
//		if(player_map[i] == player_on_first_square) continue;
//		return 2;
//	}
	return player_on_first_square == 0;
}

