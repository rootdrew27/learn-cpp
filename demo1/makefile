main.exe : main.o name.o time.o utils.o
	clang++ main.o name.o utils.o time.o -o main.exe

main.o : main.cpp name.hpp time.hpp utils.hpp.pch
	clang++ -c main.cpp -include-pch utils.hpp.pch

name.o : name.cpp name.hpp utils.hpp.pch 
	clang++ -c name.cpp -include-pch utils.hpp.pch

time.o : time.cpp time.hpp utils.hpp.pch
	clang++ -c time.cpp -include-pch utils.hpp.pch

utils.o : utils.cpp utils.hpp.pch utils.hpp
	clang++ -c utils.cpp -include-pch utils.hpp.pch

utils.hpp.pch : utils.hpp
	clang++ utils.hpp  -o utils.hpp.pch

clean : 
	echo Cleaning Project..
	rm main.exe main.o name.o time.o utils.o utils.hpp.pch