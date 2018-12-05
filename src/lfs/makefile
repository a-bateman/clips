compile:	
	-mkdir ../../build
	g++ -std=c++17 ./lfs.cpp -o ../../build/lfs -lCMD -lINK -lstdc++fs 

install: compile
	-sudo cp ../../build/lfs /usr/local/bin/lfs

clean:
	rm ../../build/lfs	

uninstall:
	sudo rm /usr/local/bin/lfs
