compile:
	clang++ -std=c++17 ./cal.cpp

install: compile
	cp ./a.out ./cal
	-sudo cp ./cal /usr/local/bin/cal

clean:
	rm ./a.out
	rm ./cal

uninstall:
	sudo rm /usr/local/bin/cal
