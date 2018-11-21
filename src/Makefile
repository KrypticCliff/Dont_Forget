CXX 			= g++
BOOST_FLAG	= -lboost_system -lboost_filesystem
CXXFLAGS 		= `pkg-config --cflags opencv`
LIBS 		= `pkg-config --libs opencv`

# Individual Compile Tests
OpenCV: OpenCV.cpp
	$(CXX) $(CFLAGS) OpenCV.cpp -o OpenCV $(CXXFLAGS) $(LIBS)

Format_IMG: Format_IMG.cpp
	$(CXX) $(CFLAGS) Format_IMG.cpp -o Format_IMG $(CXXFLAGS) $(LIBS)

Grayscale_Img: Grayscale_Img.cpp
	$(CXX) $(CFLAGS) Grayscale_Img.cpp -o Grayscale_Img $(BOOST_FLAG) $(CXXFLAGS) $(LIBS)

clean:
	rm OpenCV

clean_all:
	rm OpenCV Format_IMG Grayscale_Img
