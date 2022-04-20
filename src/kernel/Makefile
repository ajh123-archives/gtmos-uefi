CC = x86_64-elf-gcc
CXX = x86_64-elf-g++
AC = nasm
LD = x86_64-elf-ld

LDS = Linker.ld

BUILD_DIR = .
SOURCE_DIR = .
LIBC_DIR = $(SOURCE_DIR)/../libc

ELF_TARGET = kernel.elf

C_SRCS = $(shell find $(SOURCE_DIR) -name '*.c') $(shell find $(LIBC_DIR) -name '*.c')
CXX_SRCS = $(shell find $(SOURCE_DIR) -name '*.cpp') $(shell find $(LIBC_DIR) -name '*.cpp')
C_HDRS = $(shell find $(SOURCE_DIR) -name '*.h') $(shell find $(LIBC_DIR) -name '*.h')
C_OBJS = $(patsubst $(SOURCE_DIR)%.c, $(BUILD_DIR)%.o, $(C_SRCS))
CXX_OBJS = $(patsubst $(SOURCE_DIR)%.cpp, $(BUILD_DIR)%_cpp.o, $(CXX_SRCS))

ASM_SRCS = $(shell find $(SOURCE_DIR) -name '*.asm')
ASM_OBJS = $(patsubst $(SOURCE_DIR)%.asm, $(BUILD_DIR)%_asm.o, $(ASM_SRCS))

# Default flags
CFLAGS = -g -ffreestanding -fshort-wchar -mno-red-zone -m64 -nostdlib -nostdinc \
		-fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -fno-exceptions
CXXFLAGS = $(CFLAGS)
ACFLAGS = -f elf64
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

all: $(CXX_OBJS) $(C_OBJS) $(ASM_OBJS)
	$(LD) $(LDFLAGS) -o $(BUILD_DIR)/$(ELF_TARGET) $(CXX_OBJS) $(C_OBJS) $(ASM_OBJS)

$(BUILD_DIR)/interrupts/interrupts_cpp.o: $(SOURCE_DIR)/interrupts/interrupts.cpp $(C_HDRS)
	@ mkdir -p $(dir $@)
	$(CXX) -mno-red-zone -mgeneral-regs-only -ffreestanding -fno-stack-protector -c $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(C_HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(abspath $(LIBC_DIR)) -c $< -o $@

$(BUILD_DIR)/%_cpp.o: $(SOURCE_DIR)/%.cpp $(C_HDRS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(abspath $(LIBC_DIR)) -c $< -o $@

$(BUILD_DIR)/%_asm.o: $(SOURCE_DIR)/%.asm
	@mkdir -p $(dir $@)
	$(AC) $(ACFLAGS) -o $@ $<