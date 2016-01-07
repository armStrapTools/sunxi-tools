bin_PROGRAMS = sunxi-fexc
EXTRA_DIST = sunxi-fexc.8
sunxi_fexc_SOURCES = fexc.c fexc.h script.h script.c script_uboot.h script_uboot.c script_bin.h script_bin.c script_fex.h script_fex.c common.c common.h version-gen version
man_MANS = sunxi-fexc.8 sunxi-bin2fex.8 sunxi-fex2bin.8

install-exec-hook:
	cd $(DESTDIR)$(bindir) && \
	rm -f /sunxi-fex2bin sunxi-bin2fex && \
	$(LN_S) sunxi-fexc sunxi-fex2bin && \
	$(LN_S) sunxi-fexc sunxi-bin2fex
	
uninstall-local:
	-rm -f $(DESTDIR)$(bindir)/sunxi-bin2fex
	-rm -f $(DESTDIR)$(bindir)/sunxi-fex2bin

version:
	echo $(VERSION) > $@-t && mv $@-t $@
