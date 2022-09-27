all:
	gcc `pkg-config --libs --cflags dbus-1` sender.c -o sender  -I/media/xiangnian/data/source-demo/gdbus-demo/test/signal/dbus-glib-0.70/ -I/usr/include/glib-2.0/ -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/
	gcc `pkg-config --libs --cflags dbus-1` receiver.c -o receiver -I/media/xiangnian/data/source-demo/gdbus-demo/test/signal/dbus-glib-0.70/ -I/usr/include/glib-2.0/ -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/

clean:
	rm -vf sender receiver
