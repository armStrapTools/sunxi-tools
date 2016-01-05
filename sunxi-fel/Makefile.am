EXTRA_DIST = sunxi-fel-gpio
if BUILD_SUNXIFEL
bin_PROGRAMS = sunxi-fel
bin_SCRIPTS = sunxi-fel-gpio
sunxi_fel_SOURCES = fel.c fel-to-spl-thunk.h progress.c progress.h
sunxi_fel_CPPFLAGS = -I../include/ $(USB_CFLAGS)
sunxi_fel_LDADD = $(USB_LDFLAGS)
sunxi-fel-gpio:
endif
