#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#include "card.h"

//Creates a card, each card can have a subsequent card, creating a linked list, currently deprecated.
Card * createCard(wchar_t icon) {
  Card * temp = NULL;
  temp = malloc(sizeof(Card));
  temp->icon = icon;
  temp->next = NULL;
  return temp;
}

//Creates a card, each card can have a subsequent card, creating a linked list.
Card * createCard_Full(wchar_t icon, int rank, char suit) {
  Card * temp = NULL;
  temp = malloc(sizeof(Card));
  temp->icon = icon;
  temp->rank = rank;
  temp->suit = suit;
  temp->next = NULL;
  return temp;
}

//An obselete method for adding cards on to subsequent cards.
Card * addNextCard(Card * foot, Card * head) {
  head->next = &foot;
  return head;
}

//An inefficient method to retrieve the card at a given index.
Card * retrieveIndex(Card * deck, int  index) {
  for (int i = 0; i < index; i++) {
    deck = deck->next;
    if(!deck){
      return NULL;
    }
  }
  return deck;
}

//Used to trim the deck to a set length, returns the next card so as to not lose it.
Card * trimToLength(Card * deck, int length) {
  if(length < 1) {
    return NULL;
  } else {
    length = length - 1;
  }

  Card * pointer = deck;
  for(int i = 0; i < length; i++) {
    pointer = pointer->next;
  }
  Card * temp = pointer->next;
  pointer->next = NULL;

  return temp;
}

//Frees the memory of the car used.
void freeDeck(Card * deck) {
  Card * temp = deck;
  while(deck->next) {
    temp = deck->next;
    free(deck);
    deck = temp;
  }
  free(deck);
}

//A nice formatting system for printing cards as intended.
void printCard(Card * c) {

  extern theme;

  if(c) {
    switch (theme) {
      case (1) : //The first theme. Classic
        if(c->suit == 'H' || c->suit == 'D'){
          printf(TEXT_WHITE "%s ",c->icon);
        } else {
          printf(TEXT_WHITE "%s ",c->icon);
        }
        break;
      case (2) : //The second theme. Casino
        if(c->suit == 'H' || c->suit == 'D'){
          printf(TEXT_RED "%s " TEXT_WHITE ,c->icon);
        } else {
          printf(TEXT_BLACK "%s " TEXT_WHITE ,c->icon);
        }
        break;
      case (3) : //The second theme. Winter
        if(c->suit == 'H' || c->suit == 'D'){
          printf(TEXT_CYAN "%s " TEXT_WHITE ,c->icon);
        } else {
          printf(TEXT_BLUE "%s " TEXT_WHITE ,c->icon);
        }
        break;
    }
  }
}

//Prints the Cards Information in text format.
void printCardInfo(Card * card) {
  printf("The ");
  switch(card->rank) {
    case (1) :
      printf("ace");
      break;
    case (2) :
      printf("two");
      break;
    case (3) :
      printf("three");
      break;
    case (4) :
      printf("four");
      break;
    case (5) :
      printf("five");
      break;
    case (6) :
      printf("six");
      break;
    case (7) :
      printf("seven");
      break;
    case (8) :
      printf("eight");
      break;
    case (9) :
      printf("nine");
      break;
    case (10) :
      printf("ten");
      break;
    case (11) :
      printf("jack");
      break;
    case (12) :
      printf("queen");
      break;
    case (0) :
      printf("king");
      break;
  }

  printf(" of ");

  switch(card->suit) {
    case('H') :
      printf("hearts.\n");
      break;
    case('D') :
      printf("diamonds.\n");
      break;
    case('C') :
      printf("clubs.\n");
      break;
    case('S') :
      printf("spades.\n");
      break;
  }
}
