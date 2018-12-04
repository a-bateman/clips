compile:
	-mkdir ../build
	clang++ -std=c++17 ./pfc.cpp -lCMD -o ../build/pfc

install: compile
	-sudo cp ../build/pfc /usr/local/bin/pfc

uninstall:
	sudo rm /usr/local/bin/pfc
