CXX = g++
CXXFLAGS = -g -L/usr/src/gtest -Wall -std=c++11
CXXLIBFLAGS = -lgtest -lpthread
INCS = -I/usr/include
OBJS = ../src/dice.o testDice.o ../src/points.o testPoints.o ../src/player.o testPlayer.o

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCS) -o testAll  jatsiTestAll.cpp $(OBJS) $(CXXLIBFLAGS)

.cpp.o:
		$(CXX) $(CXXFLAGS) $(CXXLIBFLAGS) -c $< -o $@ $(INCS)

clean:
		rm testAll *.o ../src/*.o
