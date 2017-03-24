CXX = g++
CXXFLAGS = -g -Wall
OBJS = dice.o

diceApp: diceApp.cpp $(OBJS)
		$(CXX) $(CXXFLAGS) -o diceApp dice.cpp $(OBJS)

.cpp.o:
		$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
		rm *.o diceApp
