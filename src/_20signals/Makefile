
TEST         = sendSig 
SUBDIR       = ../lib
LIBPATH      = -L../lib
LIBNAME      = -ltlpilib 
CLEANSUBDIRS = $(addsuffix .clean, $(SUBDIR))

CC        = gcc
CFLAGS    += -g -Wall -O2 -fPIC

SRC_C     =  $(addsuffix .c, $(TEST))


all:$(SUBDIR) $(TEST)

$(SUBDIR):
	@echo
	@echo Making all in subdirectory $@
	@$(MAKE) -C $@
	
$(TEST):
	$(CC) -o $@ $(SRC_C) $(CFLAGS) $(LIBPATH) $(LIBNAME)

.PHONY: $(SUBDIR) $(CLEANSUBDIRS) clean all

clean:$(CLEANSUBDIRS)
	-rm $(TEST)

$(CLEANSUBDIRS):
	@cd $(basename $@); $(MAKE) clean
	

%:RCS/%
	co $@
