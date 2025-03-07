NAME	= readTTF
SRC		= ./src
HEADER	= ./includes
OBJ		= ./obj
CC		= clang
CFLAG	= -Wall -O2


all: readTTF.o OffsetTable.o DirectoryTable.o FontTTF.o
	$(CC) -o $(NAME) $(OBJ)/readTTF.o $(OBJ)/OffsetTable.o $(OBJ)/DirectoryTable.o $(OBJ)/FontTTF.o

readTTF.o: $(SRC)/readTTF.cpp $(HEADER)/readTTF.h
	$(CC) $(CFLAG) -c $(SRC)/readTTF.cpp -I $(HEADER) -o $(OBJ)/readTTF.o

OffsetTable.o: $(SRC)/OffsetTable.cpp $(HEADER)/OffsetTable.h
	$(CC) $(CFLAG) -c $(SRC)/OffsetTable.cpp -I $(HEADER) -o $(OBJ)/OffsetTable.o

DirectoryTable.o: $(SRC)/DirectoryTable.cpp $(HEADER)/DirectoryTable.h
	$(CC) $(CFLAG) -c $(SRC)/DirectoryTable.cpp -I $(HEADER) -o $(OBJ)/DirectoryTable.o

FontTTF.o: $(SRC)/FontTTF.cpp $(HEADER)/FontTTF.h
	$(CC) $(CFLAG) -c $(SRC)/FontTTF.cpp -I $(HEADER) -o $(OBJ)/FontTTF.o

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all