if BUILD_SUNXIFEL
bin_PROGRAMS = sunxi-fel sunxi-fel-gpio
sunxi_fel_SOURCES = fel.c fel-to-spl-thunk.h progress.c progress.h
sunxi_fel_CPPFLAGS = -I../include/ $(USB_CFLAGS)
sunxi_fel_LDADD = $(USB_LDFLAGS)
endif
