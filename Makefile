CC = gcc
TARGET = market
OBJECTS = market.o manager.o product.o

market : $(OBJECTS)
	$(CC) -o $@ $^	

clean :
	rm *.o market
