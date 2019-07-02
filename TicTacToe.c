#include <stdio.h>
void display(char* a){

	printf("%c | %c | %c\n", a[0], a[1], a[2]);
	puts("--+---+--");
	printf("%c | %c | %c\n", a[3], a[4], a[5]);
	puts("--+---+--");
	printf("%c | %c | %c\n", a[6], a[7], a[8]);
}
int check(char* a){
	if((a[0] == a[1]) && (a[1] == a[2]))
		return 1;
	else if((a[3] == a[4]) && (a[4]) == a[5])
		return 1;
	else if((a[6] == a[7]) && (a[7] == a[8]))
		return 1;
	else if((a[0] == a[3]) && (a[3] == a[6]))
		return 1;
	else if((a[1] == a[4]) && (a[4] == a[7]))
		return 1;
	else if((a[2] == a[5]) && (a[5] == a[8]))
		return 1;
	else if((a[0] == a[4]) && (a[4] == a[8]))
		return 1;
	else if((a[2] == a[4]) && (a[4] == a[6]))
		return 1;
	else
		return 0;
}

int turns(char* a){
	int remaining = 0;
	for(int i = 0; i < 9; i++){
		if((a[i] != 'X') && (a[i] != 'O'))
			remaining++;
	}
	return remaining;
}

int isvalid(int move, char* a){
	if(move != 1 && move != 2 && move != 3 && move != 4 && move != 5 && move != 6 && move != 7 && move != 8 && move != 9){
		printf("Gecersiz giris!\n");
		return 0;
	}
	else if(a[move - 1] == 'X'){
		puts("Dolu!");
		return 0;
	}
	else if (a[move - 1] == 'O'){
		puts("Dolu!");
		return 0;
	}
	else
		return 1;
}

int main(void){

	char player[2] = {'X', 'O'};
	char table[9] = {'1', '2' , '3', '4', '5', '6', '7', '8', '9'};
	int current = 0;
	int place = -1;
	while(turns(table) > 0){
		puts("----------------------------------------");
		printf("Sira oyuncu-%d'de (%c)!\n", current + 1, player[current]);
		puts("1 - 9 arasinda bir sayi secin!\n");
		display(table);
		printf("\n%d tur kaldi\n", turns(table));
		scanf("%1d", &place);
		while(getchar() != '\n')
			;
		if(!isvalid(place, table))
			continue;

		table[place - 1] = player[current];
		if(check(table)){
			puts("###############Tebrikler################");
			printf("Oyuncu-%d Kazandi!\n", current + 1);
			display(table);
			puts("########################################");
			break;
		}
		else
			current = current + 1;
		current = current % 2;

	}
	if(!turns(table)){
		puts("-------------Berabere!----------------\n");
		display(table);
	}
	getchar();
    return 0;
}