//Jose Lopez
//4/21/26
//project 10

#include <stdio.h>

#define WORDFILE "word.txt"
#define LENGTH 5

int open_file(FILE* fp, int opened);
void collect_word(FILE* fp, char letter, char file_word[]);
void convert_capitals(char letter, char file_word[]);
void users_guess(char users_word[],int guesses, int matches, char file_word[]);
void convert_guess(char users_word[]);
int compare_words(char users_word[], char file_word[], int matches);

int main(){
	
	int opened = 0, guesses = 1, matches = 0;
	char letter, file_word[LENGTH], users_word[LENGTH];
	
	FILE* fp;
	
	open_file(fp, opened);
	
	if(opened == 1){
	
	collect_word(fp, letter, file_word);
	convert_capitals(letter, file_word);
	
	}
	
	users_guess(users_word, guesses, matches, file_word);
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

int open_file(FILE* fp, int opened){
		
	fp = fopen(WORDFILE, "r");
	if(WORDFILE == NULL){
		printf("The file did not open");
	}
	else{
		opened = 1;
	}	
		
	return opened;
}

void collect_word(FILE* fp, char letter, char file_word[]){
	
	int ind = 0;
	while(fscanf(fp, "%c", &letter) == 1){
	
		file_word[ind] = letter;
		ind++;
	
	}
	
}
void convert_capitals(char letter, char file_word[]){

	char LOW_Letter_ind = 'a';
	
	for(int CAP_Letter_ind = 'A'; CAP_Letter_ind <= 'Z'; CAP_Letter_ind++){
		
		for(int ind = 0; ind < 5; ind++){
			if(file_word[ind] == CAP_Letter_ind){
			
				file_word[ind] = LOW_Letter_ind;
			
			}
		
		}
		
		
		LOW_Letter_ind++;
		
	}


}

void users_guess(char users_word[],int guesses,int matches, char file_word[]){
	
		for(int ind = 0; ind < 6; ind++){
	
		printf("GUESS %d Enter your guess: ", guesses);
	
		scanf("%s", users_word);
	
	
	
	
	
		convert_guess(users_word);
		matches = compare_words(users_word, file_word, matches);
		
		if(matches == 1){
			ind = 5;
		}
		
		guesses++;
		printf(" %d\n", ind);
	}
	
	
}


void convert_guess(char users_word[]){
	char LOW_Letter_ind = 'a';
	
	for(int CAP_Letter_ind = 'A'; CAP_Letter_ind <= 'Z'; CAP_Letter_ind++){
		
		for(int ind = 0; ind < 5; ind++){
			if(users_word[ind] == CAP_Letter_ind){
			
				users_word[ind] = LOW_Letter_ind;
			
			}
		
		}
		
		
		LOW_Letter_ind++;
		
	}
}
int compare_words(char users_word[], char file_word[], int matches){
	
	matches = 0;
	for(int ind = 0; ind < 5; ind++){
		if(users_word[ind] == file_word[ind]){
			matches++;
		}
		else{
			matches = 0;
		}
	}
	
	if(matches == 5){
		matches = 1;
	}
	else{
		matches = 0;
	}
	return matches;
}





















