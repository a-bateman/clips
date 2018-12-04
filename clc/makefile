compile:
	clang++ -std=c++17 ./clc.cpp

install: compile
	cp ./a.out ./clc
	-sudo cp ./clc /usr/local/bin/clc

clean:
	rm ./a.out
	rm ./clc	

uninstall:
	sudo rm /usr/local/bin/clc
