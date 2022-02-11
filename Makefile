CC = g++
CFLAGS = -g -Wall -std=c++11

a.out: main.o Song.o Playlist.o date.o
	$(CC) $(CFLAGS) main.o Song.o Playlist.o date.o -o a.out

main.o: main.cc Song.h Playlist.h
	$(CC) $(CFLAGS) -c main.cc

Song.o: Song.cc Song.h date.h
	$(CC) $(CFLAGS) -c Song.cc

Playlist.o: Playlist.cc Playlist.h Song.h
	$(CC) $(CFLAGS) -c Playlist.cc

date.o: date.cc date.h
	$(CC) $(CFLAGS) -c date.cc

clean:
	rm -rf main.o Song.o Playlist.o date.o a.out