CC = g++
CFLAGS=-Wall -std=c++11

clean:
	$(RMV) bin\*

run_funcionalTests:
	.\bin\funcional.exe

run_unitTests:
	.\bin\unit.exe

funcionalTests: bin\funcional_main.o bin\funcional_tests.o bin\myVensim.dll
	$(CC) -o bin\funcional.exe bin\funcional_main.o bin\funcional_tests.o -L./ -lbin\myVensim -Wall

unitTests: bin\unit_main.o bin\unit_stock.o bin\unit_flow.o bin\unit_model.o bin\myVensim.dll
	$(CC) -o bin\unit.exe bin\unit_main.o bin\unit_stock.o bin\unit_flow.o bin\unit_model.o -L./ -lbin\myVensim -Wall


bin\myVensim.dll: bin\stock_impl.o bin\flow_impl.o bin\model_impl.o
	$(CC) -shared -o bin\myVensim.dll bin\stock_impl.o bin\flow_impl.o bin\model_impl.o -Wall

bin\minhasFuncoes.o: src\minhasFuncoes.h src\minhasFuncoes.cpp
	$(CC) src\minhasFuncoes.cpp -o bin\minhasFuncoes.o -Wall

bin\stock_impl.o: src\stock.h src\stock_impl.h src\stock_impl.cpp
	$(CC) src\stock_impl.cpp -c -o bin\stock_impl.o -Wall

bin\flow_impl.o: src\flow.h src\flow_impl.h src\flow_impl.cpp src\stock.h
	$(CC) src\flow_impl.cpp -c -o bin\flow_impl.o -Wall

bin\model_impl.o: src\model.h src\model_impl.h src\model_impl.cpp src\stock.h src\flow.h
	$(CC) src\model_impl.cpp -c -o bin\model_impl.o -Wall


bin\funcional_main.o: test\funcional\main.cpp test\funcional\funcional_tests.h
	$(CC) test\funcional\main.cpp -c -o bin\funcional_main.o -Wall

bin\funcional_tests.o: test\funcional\funcional_tests.cpp test\funcional\funcional_tests.h
	$(CC) test\funcional\funcional_tests.cpp -c -o bin\funcional_tests.o -Wall


bin\unit_main.o: test\unit\main.cpp test\unit\unit_stock.h test\unit\unit_flow.h test\unit\unit_model.h
	$(CC) test\unit\main.cpp -c -o bin\unit_main.o -Wall

bin\unit_stock.o: test\unit\unit_stock.cpp test\unit\unit_stock.h
	$(CC) test\unit\unit_stock.cpp -c -o bin\unit_stock.o -Wall

bin\unit_flow.o: test\unit\unit_flow.cpp test\unit\unit_flow.h
	$(CC) test\unit\unit_flow.cpp -c -o bin\unit_flow.o -Wall

bin\unit_model.o: test\unit\unit_model.cpp test\unit\unit_model.h
	$(CC) test\unit\unit_model.cpp -c -o bin\unit_model.o -Wall