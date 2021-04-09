
libDllLoader.a: bin/DllImporter.o bin/ModulesFactory.o
	ar rcsu $@ $^

bin/%.o: src/%.cpp
	g++ -c $^ -o $@ -Ofast -s -std=c++17 -pedantic -Wall

.PHONE: clean
clean:
	rm -f *.a bin/*.o
