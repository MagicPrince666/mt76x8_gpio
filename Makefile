CROSS_COMPILE = mipsel-openwrt-linux-uclibc-
CPP = $(CROSS_COMPILE)g++

TARGET	= gpio

DIR		= . ./sys 
INC		= -I./sys
CFLAGS	= -O2 -g -Wall
LDFLAGS += -lpthread -lm -lrt -ldl

OBJPATH	= ./obj

FILES	= $(foreach dir,$(DIR),$(wildcard $(dir)/*.cpp))

OBJS	= $(patsubst %.cpp,%.o,$(FILES))

all:$(OBJS) $(TARGET)

$(OBJS):%.o:%.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $(OBJPATH)/$(notdir $@) $< 

$(TARGET):$(OBJPATH)
	$(CPP) -o $@ $(OBJPATH)/*.o $(LDFLAGS) 

clean:
	-rm -f $(OBJPATH)/*.o
	-rm -f $(TARGET)



