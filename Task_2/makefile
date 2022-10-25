TARGET := build/task_2
CC := gcc
CFLAGS := -Wall -g
OBJS := $(addprefix build/, $(notdir $(patsubst %.c, %.o, $(wildcard src/*.c))))

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)
	
build/%.o: src/%.c $(wildcard src/*.h)
	$(CC) -c $< -o $@ $(CFLAGS)