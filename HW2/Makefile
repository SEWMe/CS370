CC = gcc
CFLAGS = -Wall

objects = Starter Fibb Prime Total
all: $(objects)

$(objects): %: %.c
	$(CC) $(CLAGS) -o $@ $<


package:
	zip -r Hirigoyen.zip Starter.c Fibb.c Prime.c Total.c
	Makefile Make

clean:
	rm -f *.o *~ Starter Fibb Prime Total

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
