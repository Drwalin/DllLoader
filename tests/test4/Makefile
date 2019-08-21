
CC = g++
ARGS = -m64 -std=c++17 -s
DLL = dll

Main.exe: Main.cpp Square.$(DLL) Circle.$(DLL) Polygon.$(DLL)
	$(CC) ./Main.cpp -o Main.exe $(ARGS)

Circle.$(DLL): Circle.cpp ./Shape.$(DLL)
	$(CC) ./Circle.cpp -o ./Circle.$(DLL) $(ARGS) -fPIC -shared ./Shape.$(DLL)

Square.$(DLL): Square.cpp ./Shape.$(DLL)
	$(CC) ./Square.cpp -o ./Square.$(DLL) $(ARGS) -fPIC -shared ./Shape.$(DLL)

Polygon.$(DLL): Polygon.cpp Square.$(DLL) Shape.$(DLL)
	$(CC) ./Polygon.cpp -o ./Polygon.$(DLL) $(ARGS) -fPIC -shared ./Square.$(DLL) ./Shape.$(DLL)

Shape.$(DLL): Shape.cpp
	$(CC) ./Shape.cpp -o ./Shape.$(DLL) $(ARGS) -fPIC -shared

clean:
	del *.exe
	del *.$(DLL)
	del *.o

