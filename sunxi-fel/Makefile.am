EXTRA_DIST = sunxi-fel-gpio sunxi-fel.8 sunxi-fel-gpio.8 version-gen version
if BUILD_SUNXIFEL
bin_PROGRAMS = sunxi-fel
bin_SCRIPTS = sunxi-fel-gpio
man_MANS = sunxi-fel.8 sunxi-fel-gpio.8
sunxi_fel_SOURCES = fel.c fel-to-spl-thunk.h progress.c progress.h
sunxi_fel_CPPFLAGS =  $(USB_CFLAGS)
sunxi_fel_LDADD = $(USB_LDFLAGS)
endif

version:
	echo $(VERSION) > $@-t && mv $@-t $@
