# this does not work btw (stupid imagemagick ig)

@PHONY: all clean

all: src/data/dvdlogo.h
	pio run

clean:
	rm assets/dvdlogo.raw
	rm src/data/dvdlogo.h

src/data/dvdlogo.h: assets/dvdlogo.raw
	@mkdir -p $(@D)
	touch $@
	echo "#define DVDLOGO_WIDTH 80" >> $@
	echo "#define DVDLOGO_HEIGHT 35" >> $@
	xxd -i $< >> $@

assets/dvdlogo.raw: assets/dvdlogo.svg
	magick $< \
 		-resize 80x35 \
		-alpha off \
		-background black \
		-flatten \
		-colorspace RGB \
		-depth 16 \
		-define png:color-type=6 \
		rgb:$@
		# -type truecolor \
		# -define quantum:format=unsigned \
		# -define quantum:scale=unsigned \
		# -endian LSB \
