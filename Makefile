TARGET_EXEC ?= smartkeys

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

EOS_DIR ?= ../eoslib/src

CC=zcc
AS=z88dk-z80asm

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS=+coleco -subtype=adam
LDFLAGS=-xsmartkeys

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(AS) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(EOS_DIR) -c $< -o $@

.PHONY: install check clean

install: smartkeys.lib
	install src/smartkeys.h /usr/local/share/z88dk/include/
	install smartkeys.lib /usr/local/share/z88dk/lib/

check:
	$(MAKE) -C examples/adam-ddp-retension
	$(MAKE) -C examples/adam-smartkeys
	$(MAKE) -C examples/adam-smartkeys-sounds
	$(MAKE) -C examples/fujinet-scan-network-ui
	$(MAKE) -C examples/fujinet-select-images-ui

clean:
	$(RM) -r smartkeys.lib $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
