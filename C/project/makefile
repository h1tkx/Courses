CC=gcc
CFLAGS=-Wall -Wextra -g
OBJ=bloc.o inode.o repertoire.o sf.o gerer_sf_v4.o
EXEC=gerer_sf_v4

all: $(EXEC)

$(EXEC): $(OBJ)
$(CC) $(CFLAGS) -o $@ $^

bloc.o: bloc.c bloc.h
inode.o: inode.c inode.h bloc.h
repertoire.o: repertoire.c repertoire.h inode.h
sf.o: sf.c sf.h repertoire.h inode.h
gerer_sf_v4.o: gerer_sf_v4.c sf.h

clean:
rm -f *.o $(EXEC) backup.dat