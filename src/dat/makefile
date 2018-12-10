compile:
	clang++ -std=c++17 ./dat.cpp

install: compile
	cp ./a.out ./dat
	-sudo cp ./dat /usr/local/bin/dat

clean:
	rm ./a.out
	rm ./dat

uninstall:
	sudo rm /usr/local/bin/dat
