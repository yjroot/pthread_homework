.SUFFIXES : .c .o

CC = gcc

INC =
LIBS = -lpthread -lm
CFLAGS = $(INC)

OBJS = main.o
SRCS = main.c

TARGET = pthread

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

dep :
	gccmakedep $(INC) $(SRCS)

clean :
	rm -rf $(OBJS) $(TARGET) core

new :
	$(MAKE) clean
	$(MAKE)
