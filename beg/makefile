compile:
	-mkdir ../build
	clang++ -std=c++17 ./beg.cpp -lCMD -o ../build/beg

install: compile
	-sudo cp ../build/beg /usr/local/bin/beg

uninstall:
	sudo rm /usr/local/bin/beg
