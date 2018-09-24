	
all:
	gcc -c gfx.c -Wall -Wextra -pedantic
	gcc -c auxb.c -Wall -Wextra -pedantic
	gcc -c search.c -Wall -Wextra -pedantic
	gcc -c insertion.c -Wall -Wextra -pedantic
	gcc -c interface.c -Wall -Wextra -pedantic
	gcc -c file.c -Wall -Wextra -pedantic
	gcc -c used.c -Wall -Wextra -pedantic
	gcc -c del.c -Wall -Wextra -pedantic
	ar rcs libgfx.a *.o
	gcc -o ab ab.c -L. -lgfx -lSDL_gfx -lSDL_ttf -Wall -Wextra -pedantic
