CC = gcc
CFLAGS = -Wall
TARGET_NAME = phonebook.exe
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
INC_DIR = inc
vpath %.c src
