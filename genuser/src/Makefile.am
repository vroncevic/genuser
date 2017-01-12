##
## @info   gencpro ver.1.0
## @author Vladimir Roncevic <elektron.ronca@gmail.com>
## @brief  Process this file with automake to produce Makefile.in
##

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS = \
	-Wall \
	-g

bin_PROGRAMS = genuser

genuser_SOURCES = \
	main.c \
	createuser.c \
	creategroup.c \
	itos.c \
	userinfo.h

genuser_LDFLAGS = 

genuser_LDADD = 

