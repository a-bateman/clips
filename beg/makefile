compile:
	clang++ -std=c++17 ./beg.cpp

install: compile
	cp ./a.out ./beg
	-sudo cp ./beg /usr/local/bin/beg

clean:
	rm ./a.out
	rm ./beg	

uninstall:
	sudo rm /usr/local/bin/beg
