#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#include "card.h"

//A method for creating the entire deck, the only use of an array in the program.
Card * createFullDeck() {
  wchar_t icons[52] = {
  "🂡","🂢","🂣","🂤","🂥","🂦","🂧","🂨","🂩","🂪","🂫","🂭","🂮",
  "🂱","🂲","🂳","🂴","🂵","🂶","🂷","🂸","🂹","🂺","🂻","🂽","🂾",
  "🃑","🃒","🃓","🃔","🃕","🃖","🃗","🃘","🃙","🃚","🃛","🃝","🃞",
  "🃁","🃂","🃃","🃄","🃅","🃆","🃇","🃈","🃉","🃊","🃋","🃍","🃎"};
  Card * priorCard;
  Card * currentCard;
  char suit;
  for(int i = 51; i >= 0; i--){
    if (i < 13) {
      suit = 'S';
    } else if (i < 26) {
      suit = 'H';
    } else if (i < 39) {
      suit = 'C';
    } else {
      suit = 'D';
    }

    currentCard = createCard_Full(icons[i],(i+1)%13, suit);
    currentCard->next = priorCard;
    priorCard = currentCard;
    }
  return currentCard;
}

//A method to print out the three piles in such a way that the user can read them.
void printThreeDecks(Card * c1, Card * c2, Card * c3) {
    printf("\nDeck 1: Deck 2: Deck 3:\n=======================\n");
    while (c1 && c2 && c3) {
      printCard(c1);
      printf("      ");
      printCard(c2);
      printf("      ");
      printCard(c3);
      printf("\n");
      c1 = c1->next;
      c2 = c2->next;
      c3 = c3->next;
    }
}


//A method to "riffle shuffle" the deck as it were.
Card * shuffleDeck(Card * deck) {
  srand(time(NULL));

  //This dictates how many times the deck will be shuffled.
  for(int i = 0; i < 1000; i++){
    Card * bottomHalf;
    bottomHalf = trimToLength(deck, 26);
    deck = riffle(deck, bottomHalf);
  }

  return deck;
}

//Riffles two linked lists together, akin to a merge sort but without the sorting.
Card * riffle(Card * topHalf, Card * bottomHalf) {
  Card * returnDeck;
  //returnDeck = malloc(sizeof(Card));
  Card * pointer;

  //Opens the riffle shuffle by taking one card from the bottom of either deck, and placing it at the bottom.
  if((rand() % 2)== 1) {
    returnDeck = bottomHalf;
    bottomHalf = bottomHalf->next;
  } else {
    returnDeck = topHalf;
    topHalf = topHalf->next;
  }

  pointer = returnDeck;

  //Iterates over the rest of the deck, randomly taking one card from the bottom of either deck, until one deck runs out.
  while((bottomHalf->next != NULL) && (topHalf->next != NULL)) {
    if((rand() % 2)== 1) {
      pointer->next = bottomHalf;
      bottomHalf = bottomHalf->next;
    } else {
      pointer->next = topHalf;
      topHalf = topHalf->next;
    }
    pointer = pointer->next;
  }

  //Upon one deck running out, it adds the rest of the other deck to the bottom of the new deck.
  if(bottomHalf->next != NULL) {
    pointer->next = topHalf;
    pointer = pointer->next;
    pointer->next = bottomHalf;
  } else if(topHalf->next != NULL){
    pointer->next = bottomHalf;
    pointer = pointer->next;
    pointer->next = topHalf;
  }

  return returnDeck;
}
