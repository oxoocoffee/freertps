TC   ?= 
LIBNAME= freertps
BIN    = bin
LIB    = $(BIN)/lib$(LIBNAME).a
# todo: figure out the right flags for other OS to get the posix includes right
CFLAGS = -Iinclude --std=c99 -D_XOPEN_SOURCE=500 -D_GNU_SOURCE
LFLAGS = 

SRCS = freertps.c spdp.c udp.c udp_posix.c discovery.c sedp.c \
       time.c time_posix.c participant.c id.c subscription.c publisher.c
INC_FN = udp.h spdp.h freertps.h subscription.h id.h qos.h time.h  \
         spdp.h sedp.h discovery.h
INCS = $(addprefix include/freertps/,$(INC_FN))
OBJS = $(addprefix $(BIN)/,$(SRCS:.c=.o))

EXAMPLE_NAMES = listener
EXAMPLES = $(addprefix $(BIN)/,$(EXAMPLE_NAMES))

TEST_NAMES = time
TESTS = $(addprefix $(BIN)/,test_$(TEST_NAMES))

default: $(BIN) $(LIB) $(TESTS) $(EXAMPLES)

$(BIN):
	mkdir -p $(BIN)

$(LIB): $(OBJS)

$(BIN)/%.o: %.c $(INCS)
	$(TC)gcc $(CFLAGS) -c $< -o $@

$(LIB): $(OBJS)
	$(TC)ar rcs $@ $(OBJS)
	@#$(TC)objdump -S -d $(LIB) > $(BIN)/$(LIBNAME).objdump

$(BIN)/%: examples/%.c $(LIB)
	$(TC)gcc $(LFLAGS) -Lbin -Iinclude $< -o $@ -l$(LIBNAME)

$(BIN)/%: tests/%.c $(LIB)
	$(TC)gcc $(LFLAGS) -Lbin -Iinclude $< -o $@ -l$(LIBNAME)

.PHONY: clean
clean:
	-rm -rf $(BIN)
