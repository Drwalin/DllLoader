
CC = g++
ARGS = -ggdb -g3 -ggdb3 -m64 -std=c++17

Main.exe: Main.cpp Square.dll Circle.dll Polygon.dll
	$(CC) Main.cpp -o Main.exe $(ARGS)

Circle.dll: Circle.cpp
	$(CC) Circle.cpp -o Circle.dll $(ARGS) -fPIC -shared

Square.dll: Square.cpp
	$(CC) Square.cpp -o Square.dll $(ARGS) -fPIC -shared

Polygon.dll: Polygon.cpp Square.dll
	$(CC) Polygon.cpp -o Polygon.dll $(ARGS) -fPIC -shared Square.dll Circle.dll

clean:
	del *.exe
	del *.dll
	del *.o

