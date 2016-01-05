bin_PROGRAMS = sunxi-fexc

sunxi_fexc_SOURCES = fexc.c fexc.h script.h script.c script_uboot.h script_uboot.c script_bin.h script_bin.c script_fex.h script_fex.c
sunxi_fexc_CFLAGS = -I../include

install-exec-hook:
	-rm -f $(DESTDIR)$(bindir)/sunxi-fex2bin
	-$(LN_S) $(DESTDIR)$(bindir)/sunxi-fexc $(DESTDIR)$(bindir)/sunxi-fex2bin
	-rm -f $(DESTDIR)$(bindir)/sunxi-bin2fex
	-$(LN_S) $(DESTDIR)$(bindir)/sunxi-fexc $(DESTDIR)$(bindir)/sunxi-bin2fex
	
uninstall-local:
	-rm -f $(DESTDIR)$(bindir)/sunxi-bin2fex
	-rm -f $(DESTDIR)$(bindir)/sunxi-fex2bin
