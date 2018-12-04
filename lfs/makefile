compile:
	clang++ -std=c++17 ./lfs.cpp

install: compile
	cp ./a.out ./lfs
	-sudo cp ./lfs /usr/local/bin/lfs

clean:
	rm ./a.out
	rm ./lfs	

uninstall:
	sudo rm /usr/local/bin/lfs
