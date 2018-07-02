PROGRAM_NAME=SUSQueue
CXX=g++
RM=rm -f

SRCS=main.cpp SUSQueue.cpp
OBJS=SUSQueue.o main.o

all: $(OBJS)
	$(CXX) -o $(PROGRAM_NAME) $(OBJS)

main.o: main.cpp SUSQueue.h
	$(CXX) -c main.cpp

SUSQueue.o: SUSQueue.cpp SUSQueue.h
	$(CXX) -c SUSQueue.cpp

$(PROGRAM_NAME): $(OBJS)
	$(CXX) -o $(PROGRAM_NAME) $(OBJS)
	
run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

clean:
	$(RM) $(OBJS)
