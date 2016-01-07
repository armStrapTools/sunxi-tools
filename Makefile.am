DIST_SUBDIRS = sunxi-bootinfo sunxi-meminfo sunxi-nand-part sunxi-phoenix_info sunxi-pio sunxi-script_extractor sunxi-fexc sunxi-fel sunxi-baremetal
SUBDIRS = sunxi-nand-part sunxi-phoenix_info sunxi-fexc sunxi-bootinfo sunxi-fel sunxi-baremetal sunxi-meminfo sunxi-pio sunxi-script_extractor
EXTRA_DIST = README.md AUTHORS COPYING INSTALL sunxi-tools.8 version-gen version
man_MANS = sunxi-tools.8

clean-local:
	-find ./ -name "*~" -type f -print0 | xargs -0 /bin/rm -fv
	-find ./ -name ".*~" -type f -print0 | xargs -0 /bin/rm -fv
	-rm -f debian-control debian-changelog debian-compat debian-docs debian-rules debian-format debian-copyright
	-rm -rf $(top_srcdir)/packages
	-rm -f $(top_srcdir)/$(PACKAGE)-$(VERSION).tar.gz
version:
	echo $(VERSION) > $@-t && mv $@-t $@

debian-control:
	@echo "Source: ${PACKAGE_NAME}" > debian-control
	@echo "Section: admin" >> debian-control
	@echo "Priority: optional" >> debian-control
	@echo "Maintainer: ${DEBFULLNAME} <${DEBEMAIL}>" >> debian-control
	@echo "Build-Depends: debhelper (>= 9), autotools-dev, libusb-1.0-0-dev" >> debian-control
	@echo "Standards-Version: 3.9.6" >> debian-control
	@echo "Homepage: https://github.com/armStrapTools/sunxi-tools" >> debian-control
	@echo "Vcs-Git: https://github.com/armStrapTools/sunxi-tools.git" >> debian-control
	@echo -e "Vcs-Browser: https://github.com/armStrapTools/sunxi-tools\n" >> debian-control
	@echo "Package: ${PACKAGE_NAME}" >> debian-control
	@echo "Architecture: any" >> debian-control
	@echo 'Depends: $${shlibs:Depends}, $${misc:Depends}'", libusb-1.0-0" >> debian-control
	@echo "Description: Tools to help hacking Allwinner SUNXI based devices" >> debian-control
	@echo " Tools to help hacking Allwinner A10 (aka sun4i) ans A20 (aka sun7i) based" >> debian-control
	@echo " devices and possibly their successors, that's why the 'x' in the package" >> debian-control
	@echo " name." >> debian-control
	
debian-changelog:
	@echo -e "${PACKAGE_NAME} (${VERSION}-1) unstable; urgency=low\n" > debian-changelog
	@echo -e "  * Release ${VERSION} (Closes: `date +%Y%V%w`)\n" >> debian-changelog
	@echo " -- ${DEBFULLNAME} <${DEBEMAIL}>  `date --rfc-2822`" >> debian-changelog
	
debian-compat:
	@echo "9" > debian-compat

debian-docs:
	@echo "README.md" > debian-docs
	
debian-rules:
	@echo "#!/usr/bin/make -f" > debian-rules
	@echo "# See debhelper(7) (uncomment to enable)" >> debian-rules
	@echo "# output every command that modifies files on the build system." >> debian-rules
	@echo -e "#export DH_VERBOSE = 1\n" >> debian-rules
	@echo "# see EXAMPLES in dpkg-buildflags(1) and read /usr/share/dpkg/*" >> debian-rules
	@echo "DPKG_EXPORT_BUILDFLAGS = 1" >> debian-rules
	@echo -e "include /usr/share/dpkg/default.mk\n" >> debian-rules
	@echo "# see FEATURE AREAS in dpkg-buildflags(1)" >> debian-rules
	@echo -e "#export DEB_BUILD_MAINT_OPTIONS = hardening=+all\n" >> debian-rules
	@echo "# see ENVIRONMENT in dpkg-buildflags(1)" >> debian-rules
	@echo "# package maintainers to append CFLAGS" >> debian-rules
	@echo "#export DEB_CFLAGS_MAINT_APPEND  = -Wall -pedantic" >> debian-rules
	@echo "# package maintainers to append LDFLAGS" >> debian-rules
	@echo -e "#export DEB_LDFLAGS_MAINT_APPEND = -Wl,--as-needed\n\n" >> debian-rules
	@echo "# main packaging script based on dh7 syntax" >> debian-rules
	@echo -e -n "%:\n\t" >> debian-rules
	@echo "dh \$$@  --with autotools-dev" >> debian-rules
	@echo -e "\n# dh_make generated override targets" >> debian-rules
	@echo "# This is example for Cmake (See https://bugs.debian.org/641051 )" >> debian-rules
	@echo "#override_dh_auto_configure:" >> debian-rules
	@echo -e "#\tdh_auto_configure -- \\" >> debian-rules
	@echo -e "#\t-DCMAKE_LIBRARY_PATH=\$$(DEB_HOST_MULTIARCH)" >> debian-rules

debian-format:
	@echo "3.0 (quilt)" > debian-format

debian-copyright:
	@echo "Format: https://www.debian.org/doc/packaging-manuals/copyright-format/1.0/" > debian-copyright
	@echo "Upstream-Name: ${PACKAGE_NAME}" >> debian-copyright
	@echo -e "Source: https://github.com/armStrapTools/sunxi-tools\n" >> debian-copyright
	@echo "Files: *" >> debian-copyright
	@echo "Copyright: 2015-2016 Eddy Beaupre <eddy@beaupre.biz>" >> debian-copyright
	@echo "           2011-2012 Henrik Nordstrom <henrik@henriknordstrom.net>" >> debian-copyright
	@echo "           2012 Alejandro Mery <amery@geeks.cl>" >> debian-copyright
	@echo "           2015 Bernhard Nortmann <bernhard.nortmann@web.de>" >> debian-copyright
	@echo "           2012 Floris Bos <bos@je-eigen-domein.nl>" >> debian-copyright
	@echo "           2014 Luc Verhaegen <libv@skynet.be>" >> debian-copyright
	@echo "           2013 Patrick H Wood <github.com/patrickhwood>" >> debian-copyright
	@echo "           2015 Olliver Schinagl <oliver@schinagl.nl>" >> debian-copyright
	@echo "           2012 Jens Andersen <jens.andersen@gmail.com>" >> debian-copyright
	@echo "           2007-2011 Allwinner Technology Co., Ltd. <www.allwinnertech.com>" >> debian-copyright
	@echo "           2007-2011 Tom Cubie <tangliang@allwinnertech.com>" >> debian-copyright
	@echo -e "License: GPL-2.0+\n" >> debian-copyright
	@echo "Files: debian/*" >> debian-copyright
	@echo "Copyright: `date +%Y` ${DEBFULLNAME} <${DEBEMAIL}>" >> debian-copyright
	@echo -e "License: GPL-2.0+\n" >> debian-copyright
	@echo "License: GPL-2.0+" >> debian-copyright
	@echo " This package is free software; you can redistribute it and/or modify" >> debian-copyright
	@echo " it under the terms of the GNU General Public License as published by" >> debian-copyright
	@echo " the Free Software Foundation; either version 2 of the License, or" >> debian-copyright
	@echo " (at your option) any later version." >> debian-copyright
	@echo " ." >> debian-copyright
	@echo " This package is distributed in the hope that it will be useful," >> debian-copyright
	@echo " but WITHOUT ANY WARRANTY; without even the implied warranty of" >> debian-copyright
	@echo " MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" >> debian-copyright
	@echo " GNU General Public License for more details." >> debian-copyright
	@echo " ." >> debian-copyright
	@echo " You should have received a copy of the GNU General Public License" >> debian-copyright
	@echo " along with this program. If not, see <https://www.gnu.org/licenses/>" >> debian-copyright
	@echo " ." >> debian-copyright
	@echo " On Debian systems, the complete text of the GNU General" >> debian-copyright
	@echo " Public License version 2 can be found in \"/usr/share/common-licenses/GPL-2\"." >> debian-copyright

dpkg-deb: dist-gzip debian-control debian-changelog debian-compat debian-docs debian-rules debian-format debian-copyright
	rm -rf $(abs_top_srcdir)/packages
	mkdir $(abs_top_srcdir)/packages
	(cd $(abs_top_srcdir)/packages && bzr dh-make --bzr-only $(PACKAGE) $(VERSION) $(abs_top_srcdir)/$(PACKAGE)-$(VERSION).tar.gz)
	$(MKDIR_P) $(abs_top_srcdir)/packages/$(PACKAGE)/debian/source/
	$(INSTALL_DATA) debian-control $(abs_top_srcdir)/packages/$(PACKAGE)/debian/control
	$(INSTALL_DATA) debian-changelog $(abs_top_srcdir)/packages/$(PACKAGE)/debian/changelog
	$(INSTALL_DATA) debian-compat $(abs_top_srcdir)/packages/$(PACKAGE)/debian/compat
	$(INSTALL_DATA) debian-docs $(abs_top_srcdir)/packages/$(PACKAGE)/debian/docs
	$(INSTALL_DATA) debian-copyright $(abs_top_srcdir)/packages/$(PACKAGE)/debian/copyright
	$(INSTALL_DATA) debian-format $(abs_top_srcdir)/packages/$(PACKAGE)/debian/source/format
	$(INSTALL_SCRIPT) debian-rules $(abs_top_srcdir)/packages/$(PACKAGE)/debian/rules
	(cd $(abs_top_srcdir)/packages/$(PACKAGE) && bzr add)
	(cd $(abs_top_srcdir)/packages/$(PACKAGE) && bzr commit -m "Initial commit of Debian packaging.")
	(cd $(abs_top_srcdir)/packages/$(PACKAGE) && bzr builddeb)
	-rm -rf $(abs_top_srcdir)/packages/build-area
	-rm -rf $(abs_top_srcdir)/packages//$(PACKAGE)
	-rm -f $(abs_top_srcdir)/$(PACKAGE)-$(VERSION).tar.gz
	@echo -e "\nDebian package ready in $(abs_top_srcdir)/packages/\n"
