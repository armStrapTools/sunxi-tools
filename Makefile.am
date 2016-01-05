DIST_SUBDIRS = sunxi-bootinfo sunxi-meminfo sunxi-nand-part sunxi-phoenix_info sunxi-pio sunxi-script_extractor sunxi-fexc sunxi-fel sunxi-baremetal
SUBDIRS = sunxi-nand-part sunxi-phoenix_info sunxi-fexc

if ARM_BUILD
SUBDIRS += sunxi-bootinfo sunxi-meminfo sunxi-pio sunxi-script_extractor
endif

if BUILD_SUNXIFEL
SUBDIRS += sunxi-fel
endif

if BUILD_BAREMETAL
SUBDIRS += sunxi-baremetal
endif

clean-local:
	-find ./ -name "*~" -type f -print0 | xargs -0 /bin/rm -fv
	-find ./ -name ".*~" -type f -print0 | xargs -0 /bin/rm -fv
