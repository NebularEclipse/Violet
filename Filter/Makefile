CC = gcc
CFLAGS = -ggdb3 -gdwarf-4 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow
LDFLAGS = -lm
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
TARGET = filter

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
