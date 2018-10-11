CXX 			= g++
BOOST_FLAG	= -lboost_system -lboost_filesystem
CXXFLAGS 		= `pkg-config --cflags opencv`
LIBS 		= `pkg-config --libs opencv`

# Individual Compile Tests
OpenCV: OpenCV.cpp
	$(CXX) $(CFLAGS) OpenCV.cpp -o OpenCV $(CXXFLAGS) $(LIBS)

Format_IMG: Format_IMG.cpp
	$(CXX) $(CFLAGS) Format_IMG.cpp -o Format_IMG $(CXXFLAGS) $(LIBS)

Cascade_Build: Cascade_Build.cpp
	$(CXX) $(CFLAGS) Cascade_Build.cpp -o Cascade_Build $(BOOST_FLAG) $(CXXFLAGS) $(LIBS)

clean:
	rm OpenCV
