include config.mk

all: $(TARGET_NAME)

$(TARGET_NAME): $(OBJ_FILES)
	$(CC) $? -o $@

main.o: main.c
	$(CC) -c $? -o $@

supplement.o: supplement.c
	$(CC) -c $? -o $@

filehandling.o: filehandling.c
	$(CC) -c $? -o $@

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(TARGET_NAME) log*
