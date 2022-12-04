CFLAGS = -Wno-unused-result -O
CC = gcc

list: driver.o BatchMode.o CD.o InteractiveMode.o MyExit.o comRedirect.o exeCom.o parseArg.o parseCom.o signalHandle.o
	$(CC) $(CFLAGS) -o major2 driver.o BatchMode.o CD.o InteractiveMode.o MyExit.o comRedirect.o exeCom.o parseArg.o parseCom.o signalHandle.o -lm

driver.o: driver.c major2.h
	$(CC) $(CFLAGS) -c driver.c

BatchMode.o: BatchMode.c major2.h
	$(CC) $(CFLAGS) -c BatchMode.c 

CD.o: CD.c major2.h
	$(CC) $(CFLAGS) -c CD.c 

InteractiveMode.o: InteractiveMode.c major2.h
	$(CC) $(CFLAGS) -c InteractiveMode.c 

MyExit.o: MyExit.c major2.h
	$(CC) $(CFLAGS) -c MyExit.c
  
comRedirect.o: comRedirect.c major2.h
	$(CC) $(CFLAGS) -c comRedirect.c
  
exeCom.o: exeCom.c major2.h
	$(CC) $(CFLAGS) -c exeCom.c
  
parseArg.o: parseArg.c major2.h
	$(CC) $(CFLAGS) -c parseArg.c
  
parseCom.o: parseCom.c major2.h
	$(CC) $(CFLAGS) -c parseCom.c

signalHandle.o: signalHandle.c major2.h
	$(CC) $(CFLAGS) -c signalHandle.c

clean:
	rm -f major1 *.o
