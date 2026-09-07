CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

TARGET  = main
BUILD_DIR = build
SRC_DIR = src

C_SRCS  = $(wildcard $(SRC_DIR)/*.c)
ASM_SRCS= $(wildcard $(SRC_DIR)/*.s)

OBJS    = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRCS)) \
          $(patsubst $(SRC_DIR)/%.s, $(BUILD_DIR)/%.o, $(ASM_SRCS))

MCU     = -mcpu=cortex-m3 -mthumb

CFLAGS  = $(MCU) -Wall -Wextra -O0 -g3 -ffreestanding -nostdlib
LDFLAGS = $(MCU) -Tlinker.ld -nostdlib -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--gc-sections

.PHONY: all clean flash

all: $(BUILD_DIR)/$(TARGET).bin size

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s | $(BUILD_DIR)
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
	st-flash write $< 0x08000000

clean:
	rm -rf $(BUILD_DIR)