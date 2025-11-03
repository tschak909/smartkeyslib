TARGET_EXEC ?= smartkeys

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

EOS_DIR ?= ../eoslib/src

CC = zcc
AS = z88dk-z80asm

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS  = +coleco -subtype=adam
LDFLAGS = -xsmartkeys

INC_DIRS  := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# -----------------------------
# z88dk share dir detection
# -----------------------------
# Allow user override: `make install Z88DK_SHARE=/opt/z88dk`
ifndef Z88DK_SHARE
  ifneq (,$(wildcard /usr/share/z88dk))
    Z88DK_SHARE := /usr/share/z88dk
  else ifneq (,$(wildcard /usr/local/share/z88dk))
    Z88DK_SHARE := /usr/local/share/z88dk
  else
    $(error Could not find z88dk share directory (tried /usr/share/z88dk and /usr/local/share/z88dk). Set Z88DK_SHARE=/path/to/z88dk)
  endif
endif

# ZCCCFG auto-configuration (can be overridden: `make ZCCCFG=/custom/path`)
ZCCCFG ?= $(Z88DK_SHARE)/lib/config
export ZCCCFG

# Build the library (smartkeys.lib)
$(TARGET_EXEC).lib: $(OBJS)
	$(AS) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(EOS_DIR) -c $< -o $@

.PHONY: install check clean

install: $(TARGET_EXEC).lib src/smartkeys.h
	install -D src/smartkeys.h    $(Z88DK_SHARE)/include/smartkeys.h
	install -D $(TARGET_EXEC).lib $(Z88DK_SHARE)/lib/clibs/$(TARGET_EXEC).lib

check:
	$(MAKE) -C examples/adam-ddp-retension
	$(MAKE) -C examples/adam-smartkeys
	$(MAKE) -C examples/adam-smartkeys-sounds
	$(MAKE) -C examples/fujinet-scan-network-ui
	$(MAKE) -C examples/fujinet-select-images-ui

clean:
	$(RM) -r $(TARGET_EXEC).lib $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

