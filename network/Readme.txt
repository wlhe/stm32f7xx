How to use?

Required:
	cmake
	gcc

Build:
	cp CMakeLists.txt.template CMakeLists.txt
	mkdir build
	cd build
	cmake ..
	make

Usage:
	./client [ip address] [port]

	eg.
	./client
	./client 127.0.0.1
	./client 127.0.0.1 8888

