DIST_SUBDIRS = sunxi-bootinfo sunxi-meminfo sunxi-nand-part sunxi-phoenix_info sunxi-pio sunxi-script_extractor sunxi-fexc sunxi-fel sunxi-baremetal
SUBDIRS = sunxi-nand-part sunxi-phoenix_info sunxi-fexc sunxi-bootinfo sunxi-fel sunxi-baremetal sunxi-meminfo sunxi-pio sunxi-script_extractor
EXTRA_DIST = README.md AUTHORS COPYING INSTALL sunxi-tools.8 version-gen version
man_MANS = sunxi-tools.8

clean-local:
	-find ./ -name "*~" -type f -print0 | xargs -0 /bin/rm -fv
	-find ./ -name ".*~" -type f -print0 | xargs -0 /bin/rm -fv

version:
	echo $(VERSION) > $@-t && mv $@-t $@
