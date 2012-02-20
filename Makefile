#############################################################################
# Makefile for building: chord
# Generated by qmake (2.01a) (Qt 4.8.0) on: Mon Feb 20 11:12:17 2012
# Project:  chord.pro
# Template: app
# Command: /home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/qmake -spec ../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile chord.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/linux-g++ -I. -I../../../../QtSDK/Desktop/Qt/4.8.0/gcc/include/QtCore -I../../../../QtSDK/Desktop/Qt/4.8.0/gcc/include/QtGui -I../../../../QtSDK/Desktop/Qt/4.8.0/gcc/include/QtXml -I../../../../QtSDK/Desktop/Qt/4.8.0/gcc/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/lib -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		element.cpp \
		list.cpp \
		aboutdialog.cpp \
		configure.cpp \
		adddialog.cpp moc_mainwindow.cpp \
		moc_aboutdialog.cpp \
		moc_configure.cpp \
		moc_adddialog.cpp
OBJECTS       = main.o \
		mainwindow.o \
		element.o \
		list.o \
		aboutdialog.o \
		configure.o \
		adddialog.o \
		moc_mainwindow.o \
		moc_aboutdialog.o \
		moc_configure.o \
		moc_adddialog.o
DIST          = ../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/unix.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/linux.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base-unix.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-base.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-unix.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/qconfig.pri \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_functions.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_config.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/exclusive_builds.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_pre.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/debug.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_post.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/warn_on.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/thread.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/moc.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/resources.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/uic.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/yacc.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/lex.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/include_source_dir.prf \
		chord.pro
QMAKE_TARGET  = chord
DESTDIR       = 
TARGET        = chord

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_aboutdialog.h ui_configure.h ui_adddialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: chord.pro  ../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/linux-g++/qmake.conf ../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/unix.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/linux.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base-unix.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-base.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-unix.conf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/qconfig.pri \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_functions.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_config.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/exclusive_builds.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_pre.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/debug.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_post.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/warn_on.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/thread.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/moc.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/resources.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/uic.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/yacc.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/lex.prf \
		../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec ../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile chord.pro
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/unix.conf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/linux.conf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base.conf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base-unix.conf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-base.conf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-unix.conf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/qconfig.pri:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/modules/qt_webkit_version.pri:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_functions.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_config.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/exclusive_builds.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_pre.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/debug.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_post.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/warn_on.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/thread.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/moc.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/resources.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/uic.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/yacc.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/lex.prf:
../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec ../../../../QtSDK/Desktop/Qt/4.8.0/gcc/mkspecs/linux-g++ CONFIG+=debug -o Makefile chord.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/chord1.0.0 || $(MKDIR) .tmp/chord1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/chord1.0.0/ && $(COPY_FILE) --parents mainwindow.h element.h scene.h ui_mainwindow.h list.h aboutdialog.h configure.h ui_aboutdialog.h ui_configure.h adddialog.h .tmp/chord1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp element.cpp list.cpp aboutdialog.cpp configure.cpp adddialog.cpp .tmp/chord1.0.0/ && $(COPY_FILE) --parents mainwindow.ui aboutdialog.ui configure.ui adddialog.ui .tmp/chord1.0.0/ && (cd `dirname .tmp/chord1.0.0` && $(TAR) chord1.0.0.tar chord1.0.0 && $(COMPRESS) chord1.0.0.tar) && $(MOVE) `dirname .tmp/chord1.0.0`/chord1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/chord1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_aboutdialog.cpp moc_configure.cpp moc_adddialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_aboutdialog.cpp moc_configure.cpp moc_adddialog.cpp
moc_mainwindow.cpp: mainwindow.h
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_aboutdialog.cpp: aboutdialog.h
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) aboutdialog.h -o moc_aboutdialog.cpp

moc_configure.cpp: configure.h
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) configure.h -o moc_configure.cpp

moc_adddialog.cpp: adddialog.h
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) adddialog.h -o moc_adddialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_aboutdialog.h ui_configure.h ui_adddialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_aboutdialog.h ui_configure.h ui_adddialog.h
ui_mainwindow.h: mainwindow.ui
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_aboutdialog.h: aboutdialog.ui
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/uic aboutdialog.ui -o ui_aboutdialog.h

ui_configure.h: configure.ui
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/uic configure.ui -o ui_configure.h

ui_adddialog.h: adddialog.ui
	/home/lirenlin/QtSDK/Desktop/Qt/4.8.0/gcc/bin/uic adddialog.ui -o ui_adddialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		list.h \
		element.h \
		aboutdialog.h \
		configure.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

element.o: element.cpp element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o element.o element.cpp

list.o: list.cpp list.h \
		element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o list.o list.cpp

aboutdialog.o: aboutdialog.cpp aboutdialog.h \
		ui_aboutdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o aboutdialog.o aboutdialog.cpp

configure.o: configure.cpp configure.h \
		ui_configure.h \
		list.h \
		adddialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o configure.o configure.cpp

adddialog.o: adddialog.cpp adddialog.h \
		ui_adddialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o adddialog.o adddialog.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_aboutdialog.o: moc_aboutdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_aboutdialog.o moc_aboutdialog.cpp

moc_configure.o: moc_configure.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_configure.o moc_configure.cpp

moc_adddialog.o: moc_adddialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_adddialog.o moc_adddialog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

