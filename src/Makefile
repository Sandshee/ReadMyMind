readmymind: readmymind.o cardsPointers.o readMyMindUtility.o
							clang readmymind.o cardsPointers.o readMyMindUtility.o -o readmymind -Wall -Wextra -g

cardsPointers.o: cardsPointers.c card.h
							clang cardsPointers.c -c -o cardsPointers.o -Wall -Wextra -g

readmymind.o: readmymind.c card.h
							clang readmymind.c -c -o readmymind.o -Wall -Wextra -g

readMyMindUtility.o: readMyMindUtility.c card.h
							clang readMyMindUtility.c -c -o readMyMindUtility.o -Wall -Wextra -g

clean :
							rm *.o readmymind
