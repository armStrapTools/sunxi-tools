EXTRA_DIST = adb-devprobe.sh boot_head.lds boot_head.S fel-copy.c fel-pio.c fel-pio.lds fel-sdboot.c fel-sdboot.lds fel-to-spl-thunk.S jtag-loop.c jtag-loop.lds jtag-loop.S ramboot.uboot-sh ramboot.scr sunxi-baremetal.8.in mksunxiboot.c

if BUILD_BAREMETAL

pkgdata_DATA = sunxi-fel-copy.bin sunxi-fel-pio.bin sunxi-jtag-loop.sunxi sunxi-jtag-loop-alt.sunxi sunxi-fel-sdboot.sunxi sunxi-boot_head_sun4i.bin sunxi-boot_head_sun5i.bin ramboot.scr ramboot.uboot-sh adb-devprobe.sh fel-to-spl-thunk.S
man_MANS = sunxi-baremetal.8

sunxi-baremetal.8: sunxi-baremetal.8.in
	 sed -e 's|@datadir[@]|$(pkgdatadir)|g' sunxi-baremetal.8.in > sunxi-baremetal.8



mksunxiboot: mksunxiboot.c
	$(CC_FOR_BUILD) mksunxiboot.c -o mksunxiboot



sunxi-fel-copy.elf: fel-copy.c
	$(ARM_GCC) -g -Os -fno-common -ffixed-r8 -msoft-float -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder fel-copy.c -c -o sunxi-fel-copy.elf

sunxi-fel-copy.bin: sunxi-fel-copy.elf
	$(ARM_CPY) -O binary sunxi-fel-copy.elf sunxi-fel-copy.bin



sunxi-fel-pio.elf: fel-pio.c fel-pio.lds
	$(ARM_GCC) -g  -Os -fpic  -fno-common -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder fel-pio.c -nostdlib -o sunxi-fel-pio.elf -T fel-pio.lds

sunxi-fel-pio.nm: sunxi-fel-pio.elf
	$(ARM_NM) sunxi-fel-pio.elf | grep -v " _" > sunxi-fel-pio.nm

sunxi-fel-pio.bin: sunxi-fel-pio.elf sunxi-fel-pio.nm
	$(ARM_CPY) -O binary sunxi-fel-pio.elf sunxi-fel-pio.bin



sunxi-jtag-loop.elf: jtag-loop.c jtag-loop.lds
	$(ARM_GCC) -g  -Os  -fpic -fno-common -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder jtag-loop.c -nostdlib -o sunxi-jtag-loop.elf -T jtag-loop.lds -Wl,-N

sunxi-jtag-loop.bin: sunxi-jtag-loop.elf
	$(ARM_CPY) -O binary sunxi-jtag-loop.elf sunxi-jtag-loop.bin

sunxi-jtag-loop.sunxi: sunxi-jtag-loop.bin mksunxiboot
	$(srcdir)/mksunxiboot sunxi-jtag-loop.bin sunxi-jtag-loop.sunxi
	


sunxi-jtag-loop-alt.elf: jtag-loop.S
	 $(ARM_GCC) -g -g -fno-common -ffixed-r8 -msoft-float -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder jtag-loop.S -o sunxi-jtag-loop-alt.elf -c

sunxi-jtag-loop-alt.bin: sunxi-jtag-loop-alt.elf
	$(ARM_CPY) -O binary sunxi-jtag-loop-alt.elf sunxi-jtag-loop-alt.bin

sunxi-jtag-loop-alt.sunxi: sunxi-jtag-loop-alt.bin mksunxiboot
	$(srcdir)/mksunxiboot sunxi-jtag-loop-alt.bin sunxi-jtag-loop-alt.sunxi
	


sunxi-fel-sdboot.elf: fel-sdboot.c fel-sdboot.lds
	$(ARM_GCC) -g  -Os  -fpic -fno-common -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder fel-sdboot.c -nostdlib -o sunxi-fel-sdboot.elf -T fel-sdboot.lds -Wl,-N

sunxi-fel-sdboot.bin: sunxi-fel-sdboot.elf
	$(ARM_CPY) -O binary sunxi-fel-sdboot.elf sunxi-fel-sdboot.bin

sunxi-fel-sdboot.sunxi: sunxi-fel-sdboot.bin mksunxiboot
	$(srcdir)/mksunxiboot sunxi-fel-sdboot.bin sunxi-fel-sdboot.sunxi



sunxi-boot_head_sun4i.elf: boot_head.S boot_head.lds
	$(ARM_GCC) -g  -Os  -fpic -fno-common -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder boot_head.S -nostdlib -o sunxi-boot_head_sun4i.elf -T boot_head.lds -Wl,-N -DMACHID=0x1008

sunxi-boot_head_sun4i.bin: sunxi-boot_head_sun4i.elf
	$(ARM_CPY) -O binary sunxi-boot_head_sun4i.elf sunxi-boot_head_sun4i.bin




sunxi-boot_head_sun5i.elf: boot_head.S boot_head.lds
	$(ARM_GCC) -g  -Os  -fpic -fno-common -fno-builtin -ffreestanding -nostdinc -mno-thumb-interwork -Wall -Wstrict-prototypes -fno-stack-protector -Wno-format-nonliteral -Wno-format-security -fno-toplevel-reorder boot_head.S -nostdlib -o sunxi-boot_head_sun5i.elf -T boot_head.lds -Wl,-N -DMACHID=0x102A

sunxi-boot_head_sun5i.bin: sunxi-boot_head_sun5i.elf
	$(ARM_CPY) -O binary sunxi-boot_head_sun5i.elf sunxi-boot_head_sun5i.bin
endif



clean-local:
	-rm -f *.nm *.bin *.elf *.sunxi sunxi-baremetal.8 mksunxiboot

BUILT_SOURCES = 
include ../build-aux/version.mk
