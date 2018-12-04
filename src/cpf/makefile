compile:
	-mkdir ../build
	clang++ -std=c++17 ./cpf.cpp -lCMD -o ../build/cpf

install: compile
	-sudo cp ../build/cpf /usr/local/bin/cpf

uninstall:
	sudo rm /usr/local/bin/cpf
