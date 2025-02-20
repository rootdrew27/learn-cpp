main.exe : main.o name.o time.o utils.o
	clang++ main.o name.o utils.o time.o -o main.exe

main.o : main.cpp utils.hpp.pch
	clang++ -c main.cpp -include-pch utils.hpp.pch

name.o : name.cpp utils.hpp.pch 
	clang++ -c name.cpp -include-pch utils.hpp.pch

time.o : time.cpp utils.hpp.pch
	clang++ -c time.cpp -include-pch utils.hpp.pch

utils.o : utils.cpp utils.hpp.pch 
	clang++ -c utils.cpp -include-pch utils.hpp.pch

utils.hpp.pch : utils.hpp
	clang++ utils.hpp -o utils.hpp.pch

clean : 
	echo Cleaning Project..
	del main.exe main.o name.o time.o utils.o utils.hpp.pch