## All available commands
# "make" -> Compile all binaries
# "make clean" -> Clean up all binaries

.PHONY = all clean

# Compiler
CC = gcc

# Flags for gcc
LINKERFLAG = -lm

# Variable containing all ".c" files
SRCS := $(wildcard *.c)

# Variable cotaining all binaries
BINS := $(SRCS:%.c=%)

# Calls values in BINS as individual targets
all: ${BINS}

# Compiles binaries
%: %.o
	@echo "Checking.."
	${CC} ${LINKERFLAG} $< -o $@

%.o: %.c
	@echo "Creating object.."
	${CC} -c $<

# Cleans all binaries
clean:
	@echo "Cleaning up..."
	rm -rvf *.o ${BINS}
	rm -rvf *.so ${BINS}