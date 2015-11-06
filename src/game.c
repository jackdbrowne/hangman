/*
 * game.c
 *
 *  Created on: 15 Nov 2014
 *      Author: jack
 */

#include <ctype.h>
#include <list.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int state = 0;

struct Word {
	size_t length;
	char *text;
};

int guess(char c, char *word, linked_list *guessed, char *comp) {
	if (!add_list_item(guessed, c)) {
		printf ("You have already guessed that character, please try a different one");
		return -1;
	} else {
		int success = 0;

		char *found;
		found = strchr(word, c);
		while (found!=NULL) {
			success = 1;

			int pos = found-word;
			*(comp + pos) = c;

			found=strchr(found+1,c);
		}
		return success;
	}
}

int gameWon(struct Word *word, char *comp) {
	return strcmp(word->text, comp) == 0;
}

int gameLost(int state) {
	return state == 6;
}

int gameOver(struct Word *word, char *comp, int state) {
	return gameWon(word, comp) || gameLost(state);
}


int main(int argc, char **argv) {

	// List of already guessed characters
	// TODO: implement with more efficient data structure, BST based set
	linked_list *guessed = create_list();

	//	Get word for the game
	//	TODO: find for terminals without echo-free mode
	char *prompt = "Enter a word: ";
	struct Word *word = malloc(sizeof(struct Word));
	word->text = getpass(prompt);
	word->length = strlen(word->text);

	// A string representing the correctly guessed characters
	char *comp = malloc(word->length + 1);
	memset(comp, '-', word->length);

	// read individual characters
	size_t nbytes = 1;
	char *input = (char*) malloc(nbytes + 1);
	int memory_read;
	do {

		do {
			printf("Enter a character: ");
			memory_read = getline(&input, &nbytes, stdin);
		} while (memory_read != 2 || !isalpha(*input));

		int success = guess(*input, word->text, guessed, comp);

		if (success) {
			printf("%s\n", comp);
		} else if (success == 0) {
			state++;
			printf("Unlucky, currently at state %i\n", state);
		}
		printf("Guessed: ");
		print_list(guessed);
	} while (!gameOver(word, comp, state));

	delete_list(guessed);
	free(word);
	free (input);
	return 0;
}
