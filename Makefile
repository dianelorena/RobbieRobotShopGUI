#This Makefile is donated to the Public Domain
#$(fltk-config --cxxflags) -I/usr/local/include -I/usr/local/include/FL/images -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
CXX = g++
CXXOPTS = -std=c++11

all: executable
rebuild: clean all

debug: CXXFLAGS += -g
debug: executable

executable: main.o part.o head.o arm.o locomotor.o battery.o torso.o model.o customer.o sa.o order.o shop.o controller.o
	$(CXX) $(CXXOPTS) `fltk-config --use-forms --use-gl --use-images --ldstaticflags --cxxflags` -o 'rrs' 'main.o' 'part.o' 'head.o' 'arm.o' 'locomotor.o' 'battery.o' 'torso.o' 'model.o' 'customer.o' 'sa.o' 'order.o' 'shop.o' 'controller.o' 
	
main.o: main.cpp part.h model.h customer.h sa.h order.h shop.h controller.h
	$(CXX) -c `fltk-config --use-forms --use-gl --use-images --ldstaticflags --cxxflags` $(CXXOPTS) main.cpp

part.o: part.cpp
	$(CXX) -c $(CXXOPTS) part.cpp

head.o: head.cpp head.h part.h
	$(CXX) -c $(CXXOPTS) head.cpp

arm.o: arm.cpp arm.h part.h
	$(CXX) -c $(CXXOPTS) arm.cpp

locomotor.o: locomotor.cpp locomotor.h part.h
	$(CXX) -c $(CXXOPTS) locomotor.cpp

battery.o: battery.cpp battery.h part.h
	$(CXX) -c $(CXXOPTS) battery.cpp

torso.o: torso.cpp torso.h part.h
	$(CXX) -c $(CXXOPTS) torso.cpp

model.o: model.cpp part.h head.h arm.h torso.h locomotor.h battery.h
	$(CXX) -c $(CXXOPTS) model.cpp

customer.o: customer.cpp part.h head.h arm.h torso.h locomotor.h battery.h
	$(CXX) -c $(CXXOPTS) customer.cpp

sa.o: sa.cpp part.h head.h arm.h torso.h locomotor.h battery.h
	$(CXX) -c $(CXXOPTS) sa.cpp

order.o: order.cpp model.h customer.h sa.h
	$(CXX) -c $(CXXOPTS) order.cpp

shop.o: shop.cpp shop.h arm.h battery.h head.h locomotor.h torso.h model.h customer.h sa.h order.h
	$(CXX) -c $(CXXOPTS) shop.cpp

controller.o: controller.cpp controller.h shop.h arm.h battery.h head.h locomotor.h torso.h model.h customer.h sa.h order.h
	$(CXX) -c $(CXXOPTS) `fltk-config --use-forms --use-gl --use-images --ldstaticflags --cxxflags` controller.cpp

clean:
	-rm -f *.o
div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
