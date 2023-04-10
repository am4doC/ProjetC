CC = gcc
CFLAGS = -Wall -W  -pedantic -std=c89 -O2
LDFLAGS = -lm
MLV1=`pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
MLV2= `pkg-config --libs-only-l MLV`

all: KPPV

KPPV: main.o kppv.o mlv.o
	$(CC) $(MLV1)  $^ $(MLV2) -o $@ $(LDFLAGS)

main.o: main.c kppv.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(MLV1) -c $< $(MLV2) -o $@

kppv.o: kppv.c kppv.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@	

mlv.o: mlv.c mlv.h
	$(CC) $(CFLAGS) $(MLV1) -c $< $(MLV2) -o $@	

clean:
	rm -f *.o KPPV
