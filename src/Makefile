CXX 			= g++
BOOST_FLAG	= -lboost_system -lboost_filesystem
CXXFLAGS 		= `pkg-config --cflags opencv`
LIBS 		= `pkg-config --libs opencv`
CURL_FLAG		= -lcurl

# Individual Compile Tests
OpenCV: OpenCV_Test.cpp
	$(CXX) OpenCV_Test.cpp -o OpenCV_Test $(CXXFLAGS) $(LIBS)

Format_IMG: Format_IMG.cpp
	$(CXX) Format_IMG.cpp -o Format_IMG $(CXXFLAGS) $(LIBS)

Grayscale_Img: Grayscale_Img.cpp
	$(CXX) Grayscale_Img.cpp -o Grayscale_Img $(BOOST_FLAG) $(CXXFLAGS) $(LIBS)

Neg_URL_Pull: Neg_URL_Pull.cpp
	$(CXX) Neg_URL_Pull.cpp -o Neg_URL_Pull $(CURL_FLAG) $(BOOST_FLAG)

clean:
	rm OpenCV

clean_all:
	rm OpenCV Format_IMG Grayscale_Img
