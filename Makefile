NAME	= readTTF
SRCS	= ./src/readTTF.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= clang
CFLAG	= -Wall -O2

all: $(SRCS)
	$(CC) $(CFLAG) $(SRCS) -o $(NAME)