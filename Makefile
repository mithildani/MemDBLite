compile:
	g++ -std=c++11 -o memdblite main.cpp db.cpp db_impl.cpp cli.cpp

run:
	./memdblite