CXX 			= g++
BOOST_FLAG	= -lboost_system -lboost_filesystem
CXXFLAGS 		= `pkg-config --cflags opencv`
LIBS 		= `pkg-config --libs opencv`
CURL_FLAG		= -lcurl

# Individual Compile Tests
OpenCV: OpenCV.cpp
	$(CXX) OpenCV.cpp -o OpenCV $(CXXFLAGS) $(LIBS)

Format_IMG: Format_IMG.cpp
	$(CXX) Format_IMG.cpp -o Format_IMG $(CXXFLAGS) $(LIBS)

Grayscale_Img: Grayscale_Img.cpp
	$(CXX) Grayscale_Img.cpp -o Grayscale_Img $(BOOST_FLAG) $(CXXFLAGS) $(LIBS)

Test_Grayscale_Img: Test_Grayscale_Img.cpp
	$(CXX) Test_Grayscale_Img.cpp -o Test_Grayscale_Img $(CURL_FLAG) $(BOOST_FLAG)

clean:
	rm OpenCV

clean_all:
	rm OpenCV Format_IMG Grayscale_Img

