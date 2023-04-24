
# Compiler
CXX = g++
CFLAGS= -Wall -Werror # makes all warnings errors


# Libraries
CFLAGS=-02 $(shell pkg-config --cflags netcdf)
LDFLAGS=$(shell pkg-config --libs netcdf)

marketwatch: driver.o market.o position.o stock.o account.o user.o timeSeriesDB.o
	g++ -o marketwatch driver.o market.o position.o stock.o account.o user.o timeSeriesDB.o

driver.o: driver.cpp 
	g++ -c driver.cpp

timeSeriesDB.o: timeSeriesDB.h timeSeriesDB.cpp
	g++ -c timeSeriesDB.cpp

market.o: market.h market.cpp stock.h
	g++ -c market.cpp

position.o: position.h position.cpp stock.h
	g++ -c position.cpp


stock.o: stock.cpp stock.h 
	g++ -c stock.cpp

account.o: account.cpp account.h position.h
	g++ -c account.cpp

user.o: user.cpp user.h account.h
	g++ -c user.cpp

clean:
	rm *.o marketwatch