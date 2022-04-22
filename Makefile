# Makefile 
ckn_element:ckn_element.o culculate.o element.o triangle.o node.o
	g++ -g -o ckn_element ckn_element.o culculate.o element.o triangle.o node.o
ckn_element.o:ckn_element.cpp element.h
	g++ -g -c ckn_element.cpp
element.o:element.cpp culculate.h triangle.h node.h
	g++ -g -c element.cpp
culculate.o:culculate.cpp triangle.h node.h
	g++ -g -c culculate.cpp
node.o:node.cpp 
	g++ -g -c node.cpp
triangle.o:triangle.cpp
	g++ -g -c triangle.cpp
clean:
	-rm -rf *.o ckn_element
