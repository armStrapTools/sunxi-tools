bin_PROGRAMS = sunxi-bootinfo
EXTRA_DIST = sunxi-bootinfo.8 version-gen version
sunxi_bootinfo_SOURCES = bootinfo.c
man_MANS = sunxi-bootinfo.8

version:
	echo $(VERSION) > $@-t && mv $@-t $@
