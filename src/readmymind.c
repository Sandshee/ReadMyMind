#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include "card.h"

int theme = 1;

//Both prints the cards, and then asks the user which column their card is in.
Card* printAndMerge(Card * deck){

  //Sets up column 1.
  Card * deck1;
  Card * pointer1;
  pointer1 = deck1 = deck;
  deck = deck->next;

  //Sets up column 2.
  Card * deck2;
  Card * pointer2;
  pointer2 = deck2 = deck;
  deck = deck->next;

  //Sets up column 3.
  Card * deck3;
  Card * pointer3;
  pointer3 = deck3 = deck;
  deck = deck->next;

  //Iterates through the deck, creating 3 columns, from each node.
  while(deck != NULL) {
    pointer1->next = deck;
    pointer1 = deck;
    if(deck != NULL) {
      deck = deck->next;
    } else{
      printf("Error in Ptr 1");
      printCard(pointer1);
      break;
    }

    pointer2->next = deck;
    pointer2 = deck;
    if(deck != NULL) {
      deck = deck->next;
    } else{
      printf("Error in Ptr 2");
      break;
    }

    pointer3->next = deck;
    pointer3 = deck;
    if(deck != NULL) {
      deck = deck->next;
    } else{
      printf("Error in Ptr 3");
      break;
    }
  }

  //Finally prints out the 3 decks.
  printThreeDecks(deck1, deck2, deck3);

  //Asks the user which column their card is in, then collects the decks in the appropriate manner.
  switch(getNumbers()) {
    case(1) :
      deck = deck2;
      pointer2->next = deck1;
      pointer1->next = deck3;
      pointer3->next = NULL;
      break;
    case(2) :
      deck = deck1;
      pointer1->next = deck2;
      pointer2->next = deck3;
      pointer3->next = NULL;
      break;
    case(3) :
      deck = deck1;
      pointer1->next = deck3;
      pointer3->next = deck2;
      pointer2->next = NULL;
      break;
  }

  printf("\n");

  return deck;
}

//Retrieves numbers and validates the input, all 3 user input methods are very similar.
int getNumbers() {
  int input, temp, status;

	printf("Which column is your card in? ");
	status = scanf("%d", &input);
	while(status!=1 || (input < 0 || input > 3)){
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input: ");
		status = scanf("%d", &input);
	}
	return input;
}

//Allows the user to select which theme they want to use.
void selectTheme() {
  int input, temp, status;

	printf("(1) - Classic\n(2) - Casino\n(3) - Winter\nWhich theme would you like? ");
	status = scanf("%d", &input);
	while(status!=1 || (input < 0 || input > 3)){
		while((temp=getchar()) != EOF && temp != '\n');
		printf("Invalid input: ");
		status = scanf("%d", &input);
	}
  theme = input;
}

//Asks the user if they want to go again.
_Bool goAgain() {
  char input, temp;

	while(toupper(input) != 'Y' || toupper(input) != 'N'){
    if(toupper(input) == 'Y' || toupper(input) == 'N') {
      break;
    }
		while((temp=getchar()) != EOF && temp != '\n');
	  printf("Would you like to go again? (Y/N) ");
		scanf("%c", &input);
	}
  return (toupper(input) == 'Y');
}

//The main code and loop.
int main() {

  //The user is prompted to select a theme, this then selects the background.
  selectTheme();
  switch(theme) {
    case (1) :
      printf("\n");
      break;
    case (2) :
      printf("\n"BACKGROUND_GREEN );
      break;
    case (3) :
      printf("\n");
      break;
  }

  //The deck of cards is then created, this will be the same every time, and is only called once per execution.
  Card * deck = createFullDeck();
  Card * remDeck;

  //The program then runs the main loop of attempting to guess the user's card.
  while(1) {
    //First off the program shuffles the deck, and takes the first 21 cards.
    deck = shuffleDeck(deck);
    remDeck = trimToLength(deck, 21); //The last 31 cards are not removed, so that other runs can use these cards, and so that their memory can be freed at the end.

    printf("Think of a card from the following 21:\n");

    //The program then runs the questions 3 times, to ascertain which card is the user's.
    deck = printAndMerge(deck);
    deck = printAndMerge(deck);
    deck = printAndMerge(deck);

    //The program then prints the card's icon, and the cards information.
    printf("Your card you were thinking of was:\n");
    printCard(retrieveIndex(deck, 10));
    printCardInfo(retrieveIndex(deck, 10));

    //The program then shuffles the deck and the remaining deck back together.
    deck = riffle(deck, remDeck);

    //And asks the user if they want to go again.
    if(!goAgain()) {
      break;
    }
  }

  //If not, the program frees the memory of the 52 cards, and closes.
  printf("\n\n");
  freeDeck(deck);

  //It then prints a message, thanking the user.
  printf("Thank you for playing!\n" ANSI_COLOR_RESET );
  return 0;
}
