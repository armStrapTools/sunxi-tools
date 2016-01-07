EXTRA_DIST = sunxi-meminfo.8 version-gen version
if ARM_BUILD
bin_PROGRAMS = sunxi-meminfo
sunxi_meminfo_SOURCES = meminfo.c
sunxi_meminfo_CFLAGS = -static  
man_MANS = sunxi-meminfo.8
endif

version:
	echo $(VERSION) > $@-t && mv $@-t $@
