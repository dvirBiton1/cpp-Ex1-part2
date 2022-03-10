#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

OBJECTS=mat.o
SOURCES=mat.cpp

run: test
	./$^
# StudentTest1.o StudentTest2.o StudentTest3.o
test: TestRunner.o Test.o $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o test

main: Main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# StudentTest1.cpp:  
# 	curl https://raw.githubusercontent.com/YD5463/System-Programing-2/master/Test.cpp > $@

# StudentTest2.cpp: 
# 	curl https://raw.githubusercontent.com/shlomog12/ex1_partA/main/Test.cpp > $@

# StudentTest3.cpp: 
# 	curl https://raw.githubusercontent.com/EN555/EX1-c-/master/Test.cpp > $@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=* --

clean:
	rm -f *.o test
	rm -f StudentTest*.cpp
