CC=g++
TARGET1=lcs
TARGET2=floyd
all:
	$(CC) UDAWANT_OMKAR_pa3_lcs.cpp -o $(TARGET1)
clean:
	rm -f *.o *.d *~ $(TARGET1) 
