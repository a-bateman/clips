compile:
	-mkdir ../../build
	clang++ -std=c++17 ./sfa.cpp -lCMD -o ../build/sfa

install: compile
	-sudo cp ../build/sfa /usr/local/bin/sfa

uninstall:
	sudo rm /usr/local/bin/sfa
