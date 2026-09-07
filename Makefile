BOOTLOADER_DIR = boot
PROGRAM_DIR    = src

.PHONY: all bootloader app flash flash-bootloader flash-app clean size

all: bootloader app

bootloader:
	$(MAKE) -C $(BOOTLOADER_DIR)

app:
	$(MAKE) -C $(PROGRAM_DIR)

flash-bootloader:
	$(MAKE) -C $(BOOTLOADER_DIR) flash

flash-app:
	$(MAKE) -C $(PROGRAM_DIR) flash

# Flashes bootloader first, then application
flash: flash-bootloader flash-app

size:
	$(MAKE) -C $(BOOTLOADER_DIR) size
	$(MAKE) -C $(PROGRAM_DIR) size

clean:
	$(MAKE) -C $(BOOTLOADER_DIR) clean
	$(MAKE) -C $(PROGRAM_DIR) clean