# Kompilier-Toolchain und Flags
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

# Flags für den Compiler
CFLAGS = -mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -O2 -Wall -Wextra
ASFLAGS = -mcpu=arm1176jzf-s

# Pfade und Dateien
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Alle Quelldateien sammeln
C_SRC = $(wildcard $(SRC_DIR)/*.c)
AS_SRC = $(wildcard $(SRC_DIR)/*.s)

# Objektdateien generieren
C_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SRC))
AS_OBJ = $(patsubst $(SRC_DIR)/%.s,$(OBJ_DIR)/%.o,$(AS_SRC))

# Ziel-Binary
TARGET = kernel.img

# Standard-Target
all: $(BUILD_DIR)/$(TARGET)

# Plattform erkennen
ifeq ($(OS),Windows_NT)
    # Windows-spezifische Befehle
    RM = rmdir /S /Q
    MKDIR = mkdir
else
    # Linux/Unix/Mac-spezifische Befehle
    RM = rm -rf
    MKDIR = mkdir -p
endif

# Build-Verzeichnis erstellen
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# C-Dateien kompilieren
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Assembly-Dateien kompilieren
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(AS) $(ASFLAGS) $< -o $@

# Alles verlinken
$(BUILD_DIR)/$(TARGET): $(AS_OBJ) $(C_OBJ) | $(OBJ_DIR)
	$(MKDIR) $(BUILD_DIR)
	$(LD) -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/kernel.elf $(AS_OBJ) $(C_OBJ)
	$(OBJCOPY) $(BUILD_DIR)/kernel.elf -O binary $(BUILD_DIR)/$(TARGET)

# Aufräumen
clean:
	$(RM) $(BUILD_DIR)

.PHONY: all clean