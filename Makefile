CXX = g++
AR = ar

INC =  -Iinclude -Isrc/UI/FLTK/
CFLAGS =  -std=c++11
LIBDIR = 
LIB =  -lfltk

INC_DEBUG =  $(INC)
CFLAGS_DEBUG =  $(CFLAGS) -Wall -g
RCFLAGS_DEBUG =  $(RCFLAGS)
LIBDIR_DEBUG =  $(LIBDIR)
LIB_DEBUG = $(LIB)
OBJDIR_DEBUG = obj/Debug
OUT_DEBUG = bin/Debug/libvisual2darray.a

INC_RELEASE =  $(INC)
CFLAGS_RELEASE =  $(CFLAGS) -O2 -pedantic -Wextra -Wall -std=c++11
RCFLAGS_RELEASE =  $(RCFLAGS)
LIBDIR_RELEASE =  $(LIBDIR)
LIB_RELEASE = $(LIB)
OBJDIR_RELEASE = obj/Release
OUT_RELEASE = bin/Release/libvisual2darray.a

OBJ_DEBUG = $(OBJDIR_DEBUG)/FLTK_UI.o $(OBJDIR_DEBUG)/Fl_Cell.o $(OBJDIR_DEBUG)/Fl_GameWindow.o $(OBJDIR_DEBUG)/color.o $(OBJDIR_DEBUG)/visual2darray.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/FLTK_UI.o $(OBJDIR_RELEASE)/Fl_Cell.o $(OBJDIR_RELEASE)/Fl_GameWindow.o $(OBJDIR_RELEASE)/color.o $(OBJDIR_RELEASE)/visual2darray.o

all: before_build build_debug build_release after_build

clean: clean_debug clean_release

before_build: 

after_build: 


before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d obj/Debug || mkdir -p obj/Debug

after_debug: 

build_debug: before_debug out_debug after_debug

debug: before_build build_debug after_build

out_debug: before_debug $(OBJ_DEBUG)
	$(AR) rcs $(OUT_DEBUG) $(OBJ_DEBUG)

$(OBJDIR_DEBUG)/FLTK_UI.o: src/UI/FLTK/FLTK_UI.cpp include/types.hpp \
	include/abstractui.hpp include/types.hpp include/color.hpp \
 	src/UI/FLTK/FLTK_UI.hpp src/UI/FLTK/Fl_GameWindow.hpp \
 	src/UI/FLTK/Fl_Cell.hpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/UI/FLTK/FLTK_UI.cpp -o $(OBJDIR_DEBUG)/FLTK_UI.o

$(OBJDIR_DEBUG)/Fl_Cell.o: src/UI/FLTK/Fl_Cell.cpp include/types.hpp src/UI/FLTK/Fl_Cell.hpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/UI/FLTK/Fl_Cell.cpp -o $(OBJDIR_DEBUG)/Fl_Cell.o

$(OBJDIR_DEBUG)/Fl_GameWindow.o: src/UI/FLTK/Fl_GameWindow.cpp include/types.hpp src/UI/FLTK/Fl_GameWindow.hpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/UI/FLTK/Fl_GameWindow.cpp -o $(OBJDIR_DEBUG)/Fl_GameWindow.o

$(OBJDIR_DEBUG)/color.o: src/color.cpp include/color.hpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/color.cpp -o $(OBJDIR_DEBUG)/color.o

$(OBJDIR_DEBUG)/visual2darray.o: src/visual2darray.cpp include/types.hpp \
 	include/visual2darray.hpp include/types.hpp include/color.hpp \
 	include/abstractui.hpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/visual2darray.cpp -o $(OBJDIR_DEBUG)/visual2darray.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d obj/Release || mkdir -p obj/Release

after_release: 
	cp $(OUT_RELEASE) bin/
	
build_release: before_release out_release after_release

release: before_build build_release after_build

out_release: before_release $(OBJ_RELEASE)
	$(AR) rcs $(OUT_RELEASE) $(OBJ_RELEASE)

$(OBJDIR_RELEASE)/FLTK_UI.o: src/UI/FLTK/FLTK_UI.cpp include/types.hpp \
	include/abstractui.hpp include/types.hpp include/color.hpp \
 	src/UI/FLTK/FLTK_UI.hpp src/UI/FLTK/Fl_GameWindow.hpp \
 	src/UI/FLTK/Fl_Cell.hpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/UI/FLTK/FLTK_UI.cpp -o $(OBJDIR_RELEASE)/FLTK_UI.o

$(OBJDIR_RELEASE)/Fl_Cell.o: src/UI/FLTK/Fl_Cell.cpp include/types.hpp src/UI/FLTK/Fl_Cell.hpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/UI/FLTK/Fl_Cell.cpp -o $(OBJDIR_RELEASE)/Fl_Cell.o

$(OBJDIR_RELEASE)/Fl_GameWindow.o: src/UI/FLTK/Fl_GameWindow.cpp include/types.hpp src/UI/FLTK/Fl_GameWindow.hpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/UI/FLTK/Fl_GameWindow.cpp -o $(OBJDIR_RELEASE)/Fl_GameWindow.o

$(OBJDIR_RELEASE)/color.o: src/color.cpp include/color.hpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/color.cpp -o $(OBJDIR_RELEASE)/color.o

$(OBJDIR_RELEASE)/visual2darray.o: src/visual2darray.cpp include/types.hpp \
 	include/visual2darray.hpp include/types.hpp include/color.hpp \
 	include/abstractui.hpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/visual2darray.cpp -o $(OBJDIR_RELEASE)/visual2darray.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE) bin/visual2darray.a 

.PHONY: before_build after_build before_debug after_debug clean_debug before_release after_release clean_release

