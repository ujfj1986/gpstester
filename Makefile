
gpscli :
	$(CC) -o gpscli -DUNIX_API -O2 ./*.cpp

clean:
	rm *.o
	rm gpscli
