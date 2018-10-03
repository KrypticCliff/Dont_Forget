CXX 			= g++
CFLAGS 		= -lstdc++fs
CXXFLAGS 		= `pkg-config --cflags opencv`
LIBS 		= `pkg-config --libs opencv`

OpenCV: OpenCV.cpp
	$(CXX) $(CFLAGS) OpenCV.cpp -o OpenCV $(CXXFLAGS) $(LIBS)

Format_IMG: Format_IMG.cpp
	$(CXX) $(CFLAGS) Format_IMG.cpp -o Format_IMG $(CXXFLAGS) $(LIBS)

clean:
	rm OpenCV
