include config.mk

all: $(TARGET_NAME)

$(TARGET_NAME): $(OBJ_FILES)
	$(CC) $? -o $@

%.o: %.c
	$(CC) -c $? -I$(INC_DIR) -o $@

check:
	@echo $(SRC_FILES)
	@echo $(OBJ_FILES)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(TARGET_NAME) log*
