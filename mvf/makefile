compile:
	clang++ -std=c++17 ./mvf.cpp

install: compile
	cp ./a.out ./mvf
	-sudo cp ./mvf /usr/local/bin/mvf

clean:
	rm ./a.out
	rm ./mvf

uninstall:
	sudo rm /usr/local/bin/mvf
