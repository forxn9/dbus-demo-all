.PHONY: all

FLAGS=$(shell pkg-config --libs --cflags gio-2.0 gio-unix-2.0 glib-2.0)
all: server client
server: server.o minminbus.o
	gcc -o $@ $^ $(FLAGS)
client: client.o minminbus.o
	gcc -o $@ $^ $(FLAGS)
server.o: Server-side.c
	gcc -o $@ $^ -c $(FLAGS)
client.o: Client-side.c
	gcc -o $@ $^ -c $(FLAGS)
minminbus.o: generated-code.c
	gcc -o $@ $^ -c $(FLAGS)

clean:
	rm -f *.o server client

# gen stub
gen:	
	gdbus-codegen --interface-prefix org.gtk.GDBus.Example.ObjectManager. \
              --generate-c-code generated-code	                      \
              --c-namespace Example 				      \
              --c-generate-object-manager			      \
              --generate-docbook generated-docs                       \
              gdbus-example-objectmanager.xml
#gdbus-codegen --generate-c-code minminbus --c-namespace MinMinBus --interface-prefix com.fatminmin. com.fatminmin.GDBUS.xml

# dbus
introspect:
	gdbus introspect -e -d com.fatminmin -o /com/fatminmin/GDBUS
call:
	gdbus call -e -d com.fatminmin -o /com/fatminmin/GDBUS -m com.fatminmin.GDBUS.HelloWorld fatminmin
