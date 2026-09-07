CC         = arm-none-eabi-gcc
OBJCOPY    = arm-none-eabi-objcopy
SIZE       = arm-none-eabi-size

TARGET     = program
BUILD_DIR  = build
SRC_DIR    = .
INC_DIR    = include
FLASH_ADDR = 0x08004000

C_SRCS     = $(wildcard $(SRC_DIR)/*.c)
ASM_SRCS   = $(wildcard $(SRC_DIR)/*.s) $(wildcard $(SRC_DIR)/*.S)

OBJS       = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRCS)) \
             $(patsubst $(SRC_DIR)/%.s, $(BUILD_DIR)/%.o, $(filter %.s, $(ASM_SRCS))) \
             $(patsubst $(SRC_DIR)/%.S, $(BUILD_DIR)/%.o, $(filter %.S, $(ASM_SRCS)))

MCU        = -mcpu=cortex-m3 -mthumb

CFLAGS     = $(MCU) -Wall -Wextra -O0 -g3 -ffreestanding -nostdlib -I$(INC_DIR)
LDFLAGS    = $(MCU) -Tlinker.ld -nostdlib -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--gc-sections

.PHONY: all clean flash size

all: $(BUILD_DIR)/$(TARGET).bin size

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(BUILD_DIR):
	mkdir -p $@

size: $(BUILD_DIR)/$(TARGET).elf
	$(SIZE) $<

flash: $(BUILD_DIR)/$(TARGET).bin
	st-flash write $< $(FLASH_ADDR)

clean:
	rm -rf $(BUILD_DIR)