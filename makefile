marketwatch: driver.o market.o position.o stock.o
	g++ -o marketwatch driver.o market.o position.o stock.o

driver.o: driver.cpp 
	g++ -c driver.cpp

market.o: market.h market.cpp stock.h
	g++ -c market.cpp

position.o: position.h position.cpp stock.h
	g++ -c position.cpp

stock.o: stock.cpp stock.h 
	g++ -c stock.cpp