cflags=-std=c17
dflags=-g -Wall -Werror -std=c17
target="dice"

make:
	gcc dice.c $(cflags) -o $(target)

debug:
	gcc dice.c $(dflags) -o $(target)

clean:
	rm $(target)  