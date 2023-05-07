# C++ Compiler (Default: g++)
CXX = g++
CFLAGS = -Wall -Werror

# Librarys
INCLUDE = -Iusr/local/include
LDFLAGS = -Lusr/local/lib 
LDLIBS = -lcurl

# Details
SOURCES = driver.o market.o position.o stock.o account.o user.o timeSeriesDB.o libstructs.o
OUT = marketwatch

all: build

build: $(SOURCES)
	$(CXX) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS) $(SOURCES) $(LDLIBS)

driver.o: driver.cpp libstructs.h json.hpp
	g++ -c driver.cpp

timeSeriesDB.o: timeSeriesDB.h timeSeriesDB.cpp
	g++ -c timeSeriesDB.cpp

market.o: market.h market.cpp stock.h
	g++ -c market.cpp

position.o: position.h position.cpp stock.h
	g++ -c position.cpp

libstructs.o: libstructs.cpp libstructs.h
	g++ -c libstructs.cpp

stock.o: stock.cpp stock.h 
	g++ -c stock.cpp

account.o: account.cpp account.h position.h
	g++ -c account.cpp

user.o: user.cpp user.h account.h
	g++ -c user.cpp
clean:
	rm *.o marketwatch