CXX = g++
CXXFLAGS += -std=c++17 -Wall -Wextra -g -I/path/to/gtest/include
LDFLAGS += -L/path/to/gtest/lib -lgtest -lgtest_main -pthread

sym_table: main.o symtable.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

symtable.o: SymTable.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

symtest.o: Symtable_test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

sym_test: symtest.o symtable.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	./sym_test

clean:
	rm -f *.o main sym_test