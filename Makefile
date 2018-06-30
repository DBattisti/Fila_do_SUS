PROGRAM_NAME = SUSQueue.exe
CXX=g++
RM=rm -f

SRCS=SUSQueue.cpp

all: $(SRCS)
	$(CXX) -o $(PROGRAM_NAME) $(SRCS)

run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

clean:
	$(RM) $(PROGRAM_NAME)
