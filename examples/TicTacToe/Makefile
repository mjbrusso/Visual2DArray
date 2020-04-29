PROJECT=tictactoe
CXX=g++
CXX_FLAGS= -Wall      \
		  -ansi      \
		  -pedantic  \
		  -O2		 \
		  -std=c++11 \
		  -I ../../include 
LINK_FLAGS= -L ../../bin \
			-lvisual2darray -lfltk_images  -lfltk  
		  		  
all: first
 
first: main.o 
	$(CXX)  -o $(PROJECT) main.o $(CXX_FLAGS) $(LINK_FLAGS)
 
main.o: main.cpp
	$(CXX)  -o main.o -c main.cpp  $(CXX_FLAGS)
  
clean:
	rm -rf *.o *~ $(PROJECT)