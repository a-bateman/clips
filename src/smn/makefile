compile:
	-mkdir ../build
	clang++ -std=c++17 ./smn.cpp -lCMD -o ../build/smn

install: compile
	-sudo cp ../build/smn /usr/local/bin/smn

uninstall:
	sudo rm /usr/local/bin/smn
