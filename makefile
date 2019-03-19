HEADERS_PATH = .
SOURCES_PATH = .

SOURCES = $(SOURCES_PATH)/triple.cpp $(SOURCES_PATH)/triplestore.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CC = g++
EXECUTABLE = main.exe
CVERSION = -std=c++14

all:$(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) -I $(HEADERS_PATH) $^ -o $@ $(CVERSION)
.cpp.o: $(SOURCES)
	$(CC) -I $(HEADERS_PATH) -c $^ -o $@ $(CVERSION)

clean:
	$(RM) $(EXECUTABLE) *.o $(SOURCES_PATH)/*.o
