all:
	gcc hello.c -o hello `pkg-config --cflags --libs gtk+-3.0`
	gcc toggle-button.c -o toggle-button `pkg-config --cflags --libs gtk+-3.0`
	gcc example-1.c -o example `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm -vf example hello toggle-button
