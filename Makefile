.SUFFIXES : .c .o

CC = gcc

INC =
LIBS = -lm
CFLAGS = $(INC)

OBJS_SINGLE = single.o
OBJS_MULTI = multi.o
OBJS = $(OBJS_SINGLE) $(OBJS_MULTI)
SRCS = $(OBJS:.o=.c)

TARGET = single multi

all : single multi

single : $(OBJS_SINGLE)
	$(CC) -o $@ $(OBJS_SINGLE) $(LIBS)

multi : $(OBJS_MULTI)
	$(CC) -o $@ $(OBJS_MULTI) $(LIBS) -lpthread

dep :
	gccmakedep $(INC) $(SRCS)

clean :
	rm -rf $(OBJS) $(TARGET)

new :
	$(MAKE) clean
	$(MAKE)
