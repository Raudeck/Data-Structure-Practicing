BUILDIR := build
TARGET := $(BUILDIR)/3.4_Task_1
CC := gcc
CFLAGS := -Wall -g
OBJS := $(addprefix $(BUILDIR)/, $(notdir $(patsubst %.c, %.o, $(wildcard src/*.c))))

$(TARGET): $(OBJS) | $(BUILDIR)
	$(CC) $^ -o $(TARGET)
	
build/%.o: src/%.c $(wildcard src/*.h) | $(BUILDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILDIR):
	mkdir -p $(BUILDIR)