.PHONY: all clean install

all: minesweeper

clean:
	rm -f minesweeper

minesweeper: src/main.cpp
	g++ src/main.cpp src/mineSweeper.cpp include/mineSweeper.h include/split.h include/colors.h include/global.h -o minesweeper

install:
	mkdir -p $(DESTDIR)/usr/bin
	cp minesweeper $(DESTDIR)/usr/bin/minesweeper

uninstall:
	rm $(DESTDIR)/usr/bin/minesweeper