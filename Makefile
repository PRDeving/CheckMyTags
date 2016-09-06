hellomake: src/checkmytags.cpp
	gcc -xc++ -lstdc++ -shared-libgcc -o checkmytags src/checkmytags.cpp

install:
	mkdir /etc/checkmytags
	mv lookfor.conf /etc/checkmytags
	mv checkmytags /usr/bin
