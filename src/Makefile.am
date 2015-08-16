## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = gzen_money.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(GZEN_MONEY_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = gzen_money

gzen_money_SOURCES = \
	gzen_money.vala config.vapi

gzen_money_VALAFLAGS =  --pkg libsoup-2.4 --pkg gee-1.0 --pkg gtk+-3.0 --pkg json-glib-1.0  \
	--pkg gtk+-3.0


gzen_money_LDFLAGS = \
	-Wl,--export-dynamic

gzen_money_LDADD = $(GZEN_MONEY_LIBS)




EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

