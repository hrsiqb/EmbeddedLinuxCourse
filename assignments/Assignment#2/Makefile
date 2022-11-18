default: writer.c
ifdef CROSS_COMPILE
	aarch64-none-linux-gnu-gcc writer.c -o writer
	file writer > fileresult.txt
else
	gcc writer.c -o writer
endif

clean: 
	rm -r writer *.o
