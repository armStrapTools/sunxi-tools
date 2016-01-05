bin_PROGRAMS = sunxi-nand-part

sunxi-nand-part$(EXEEXT): nand-part-main.c nand-part.c nand-part-a10.h nand-part-a20.h nand-common.h
	$(CC) $(CFLAGS) -I../include/ -c -o nand-part-main.o nand-part-main.c
	$(CC) $(CFLAGS) -I../include/ -c -o nand-part-a10.o nand-part.c -D A10
	$(CC) $(CFLAGS) -I../include/ -c -o nand-part-a20.o nand-part.c -D A20
	$(CC) $(LDFLAGS) -I../include/ -o $@ nand-part-main.o nand-part-a10.o nand-part-a20.o $(LIBS)
