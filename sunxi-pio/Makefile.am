EXTRA_DIST = sunxi-pio.8 version-gen version
if ARM_BUILD
bin_PROGRAMS = sunxi-pio
sunxi_pio_SOURCES = pio.c
sunxi_pio_CFLAGS = -static
man_MANS = sunxi-pio.8
endif

version:
	echo $(VERSION) > $@-t && mv $@-t $@
