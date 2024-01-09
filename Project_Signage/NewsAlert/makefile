HTMLReq.o: HTMLReq.cpp HTMLReq.h ProcessHTML.h
	g++ -c HTMLReq.cpp -lcurl --std=c++11
JSONReq.o: JSONReq.cpp JSONReq.h ProcessJSON.h
	JSONReq.cpp -lcurl --std=c++11
NewsData.o: NewsData.cpp NewsData.h Request2.h gumbo.h
	g++ -c NewsData.cpp -lcurl --std=c++11
ProcessHTML.o: ProcessHTML.cpp ProcessHTML.h NewsArticle.h gumbo.h Document.h Node.h
	g++ -c ProcessHTML.cpp -I/usr/local/include/gq -L/home/val/western/cs3307/gumbo/gumbo-q2/gumbo-query/lib/ -lcurl --std=c++11 -lgq
ProcessJSON.o: ProcessJSON.cpp ProcessJSON.h NewsArticle.h
	g++ -c ProcessJSON.cpp -lcurl --std=c++11
NewsArticle.o: NewsArticle.cpp NewsArticle.h
	g++ -c NewsArticle.cpp
Request2.o: Request2.cpp Request2.h
	g++ -c Request2.cpp -lcurl
clean:
	rm -f *.o
