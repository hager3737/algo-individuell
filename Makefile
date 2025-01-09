PROG = main.exe 
SRC = main.cpp src/SensorData.cpp src/UtilityFunctions.cpp src/Customer.cpp src/Queue.cpp src/MenuFunctions.cpp src/ATM.cpp src/Account.cpp src/LRUCache.cpp src/HockeyPlayer.cpp
CFLAGS = -g -std=c++17
LIBS = 
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean