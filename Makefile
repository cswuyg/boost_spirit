CC=g++
CFLAGS=
BOOSTDIR=/home/users/cswuyg/test_boost/boost_1_55_0
INCLUDE=-I$(BOOSTDIR)/
LIBS=/home/users/cswuyg/test_boost/boost_1_55_0/stage/lib/libboost_locale.a

demo : demo.o unicode_user.o
	$(CC) -o $@ $^
demo.o: demo.cc unicode_user.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

unicode_user.o: unicode_user.cc unicode_user.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

clean:
	rm *.o demo
