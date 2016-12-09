TARGET = main
VBAFLAGS = -0

DEVKITPATH = ../../devkitadv/bin/
LIBGBA = ../../libgba/lib/
BASFILEPATH = ../../basfiles/

CC = $(DEVKITPATH)arm-agb-elf-gcc
LD = $(DEVKITPATH)arm-agb-elf-gcc
AS = $(DEVKITPATH)arm-agb-elf-as
OBJCOPY = $(DEVKITPATH)arm-agb-elf-objcopy

CFLAGS	= -c -Wall -marm -fomit-frame-pointer -O0 $(INCPATH) -DDEBUG
MODEL = -mthumb -mthumb-interwork

INCPATH = -I$(LIBGBA)
LIBPATH = -L$(LIBVBA)
LDFLAGS = -T$(BASFILEPATH)lnkscript
LIBFILE = -lstd -lgba


OBJFILES =  crt0.o visoly.o main.o

OTHER_OBJ = 

.CFILES	= main.c

all : $(TARGET).gba

clean :
	rm -f *.o $(TARGET).gba $(TARGET).elf

run : $(TARGET).gba
	$(VBA) $(TARGET).gba

crt0.o: $(BASFILEPATH)crt0.S
	$(AS) -o $@ $< -mthumb-interwork

visoly.o:  $(BASFILEPATH)visoly.s
	$(AS) -o $@ $< -mthumb-interwork


$(TARGET).gba : $(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).gba

$(TARGET).elf : $(OBJFILES)
	$(LD) -marm -nostdlib -Wl,$(LDFLAGS) -mthumb -mthumb-interwork -o $(TARGET).elf $(OBJFILES) $(OTHER_OBJ) $(LIBPATH) $(LIBFILE)

.c.o:		
				$(CC) $(CFLAGS) $< -mthumb-interwork

