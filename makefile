#   <https://github.com/AnthonyDugarte/TripleStore/blob/master/LICENSE>\
\
    TripleStore, save and search for triplets sentences\
    Copyright (C) 2021  Anthony Dugarte contact@anthonydugarte.dev\
\
    This program is free software: you can redistribute it and/or modify\
    it under the terms of the GNU General Public License as published by\
    the Free Software Foundation, either version 3 of the License, or\
    (at your option) any later version.\
\
    This program is distributed in the hope that it will be useful,\
    but WITHOUT ANY WARRANTY; without even the implied warranty of\
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\
    GNU General Public License for more details.\
\
    You should have received a copy of the GNU General Public License\
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
