bin_PROGRAMS = sunxi-phoenix_info
EXTRA_DIST = sunxi-phoenix_info.8 version-gen version
sunxi_phoenix_info_SOURCES = phoenix_info.c
man_MANS = sunxi-phoenix_info.8

version:
	echo $(VERSION) > $@-t && mv $@-t $@
