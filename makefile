CC=g++
CFLAGS=-Wall
TARGET=printerSim
all: $(TARGET)
$(TARGET): printerListType.o printerSimulation.o printerType.o printRequestType.o waitingQueue.o
	$(CC) $(CFLAGS) -o $(TARGET) printerListType.o printerSimulation.o printerType.o printRequestType.o waitingQueue.o
printerListType.o: printerListType.cpp printerListType.h printerType.h printRequestType.h
	$(CC) $(CFLAGS) -c printerListType.cpp 
printerSimulation.o: printerSimulation.cpp printerListType.h printerType.h printRequestType.h waitingQueue.h 
	$(CC) $(CFLAGS) -c printerSimulation.cpp
printerType.o: printerType.cpp printerType.h printRequestType.h
	$(CC) $(CFLAGS) -c printerType.cpp
printRequestType.o: printRequestType.cpp printRequestType.h
	$(CC) $(CFLAGS) -c printRequestType.cpp
waitingQueue.o: waitingQueue.cpp waitingQueue.h printRequestType.h
	$(CC) $(CFLAGS) -c waitingQueue.cpp
clean: 
	rm *.o $(TARGET)
