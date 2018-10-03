// card.h
#ifndef CARD_H
#define CARD_H

//All of the colours used for the 3 themes.
#define TEXT_BLACK          "\x1b[30m"
#define TEXT_RED            "\x1b[31m"
#define TEXT_BLUE           "\x1b[34m"
#define TEXT_CYAN           "\x1b[36m"
#define TEXT_WHITE          "\x1b[37m"
#define BACKGROUND_GREEN    "\x1b[42m"
#define ANSI_COLOR_RESET    "\x1b[0m"

//The card structure. rank is only used for the user's card, and suit is used to determine the card's colour.
typedef struct card {
  wchar_t icon;
  int rank;
  char suit;
  struct card *next;
} Card;

Card * createCard(wchar_t icon);
Card * createCard_Full(wchar_t icon, int rank, char suit);
Card * addNextCard(Card * foot, Card * head);
void printDeck(Card * c);
void printCard(Card * c);
void printThreeDecks(Card * c1, Card * c2, Card * c3);
Card * mergeThreeDecks(Card * c1, Card * c2, Card *c3);
Card * shuffleDeck(Card * deck);
Card * createFullDeck();
Card * retrieveIndex(Card * deck, int index);
Card * riffle(Card * topHalf, Card * bottomHalf);
Card * getSelection(Card * deck);
Card * trimToLength(Card * deck, int length);
void freeDeck(Card * deck);
void printCardInfo(Card * card);
int getLength();
#endif
