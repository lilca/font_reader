NAME	= readTTF
SRC		= ./src
HEADER	= ./src/header
OBJ		= ./obj
CC		= clang
CFLAG	= -Wall -O2


all: readTTF.o OffsetTable.o DirectoryTable.o font_ttf.o
	$(CC) -o $(NAME) $(OBJ)/readTTF.o $(OBJ)/OffsetTable.o $(OBJ)/DirectoryTable.o $(OBJ)/font_ttf.o

readTTF.o: $(SRC)/readTTF.cpp $(HEADER)/readTTF.h
	$(CC) $(CFLAG) -c $(SRC)/readTTF.cpp -o $(OBJ)/readTTF.o

OffsetTable.o: $(SRC)/OffsetTable.cpp $(HEADER)/OffsetTable.h
	$(CC) $(CFLAG) -c $(SRC)/OffsetTable.cpp -o $(OBJ)/OffsetTable.o

DirectoryTable.o: $(SRC)/DirectoryTable.cpp $(HEADER)/DirectoryTable.h
	$(CC) $(CFLAG) -c $(SRC)/DirectoryTable.cpp -o $(OBJ)/DirectoryTable.o

font_ttf.o: $(SRC)/font_ttf.cpp $(HEADER)/font_ttf.h
	$(CC) $(CFLAG) -c $(SRC)/font_ttf.cpp -o $(OBJ)/font_ttf.o

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all