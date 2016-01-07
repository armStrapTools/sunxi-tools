EXTRA_DIST = sunxi-script_extractor.8 version-gen version
if ARM_BUILD
bin_PROGRAMS = sunxi-script_extractor
sunxi_script_extractor_SOURCES = script_extractor.c
sunxi_script_extractor_CPPFLAGS = -I../include/
man_MANS = sunxi-script_extractor.8
endif

version:
	echo $(VERSION) > $@-t && mv $@-t $@
