.PHONY: all clean install

all: mineSweeper

clean:
	rm -f mineSweeper

mineSweeper: src/main.cpp
	g++ src/main.cpp src/mineSweeper.cpp include/mineSweeper.h include/split.h include/colors.h include/global.h -o mineSweeper

install:
	mkdir -p $(DESTDIR)/usr/bin
	cp mineSweeper $(DESTDIR)/usr/bin/mineSweeper

uninstall:
	rm $(DESTDIR)/usr/bin/mineSweeper
