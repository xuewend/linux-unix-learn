
TLPILIB   = libtlpilib.a

CC        = gcc
AR        = ar
CFLAGS    += -g -Wall -O2 -fPIC

SRC_C     = $(wildcard *.c)
C_OBJ     := $(SRC_C:.c=.o)

lib:$(TLPILIB)

$(TLPILIB):$(C_OBJ)
	$(AR) cr $@ $^ 
	
$(C_OBJ):%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY:clean lib 

clean:
	-rm $(C_OBJ) $(TLPILIB)