cxx:=g++
salida:= laboratorio1


programa: main.o archivo.o
	$(cxx) -I./include -o laboratorio1 main.o archivo.o

main.o: main.cpp include/archivo.h
	$(cxx) -I./include -c main.cpp

archivo.o: src/archivo.cpp	include/archivo.h
	$(cxx) -I./include -c src/archivo.cpp
	
clean:
	rm *.o
	rm laboratorio1
	
	
