#include <iostream>
#include <fstream>
#include <string>
#include "opencv2/imgproc.hpp"
// #include "opencv/"

int main(int argc, char** argv) {
     cv::Mat img_rs;
     const int MAX_SIZE = 255;
     char* filename[MAX_SIZE];
     const cv::String keys = 
	     "{help     h |   	 | Prints help message      }"
	     "{@image 	  |<none>| image used for resizing  }"
	     "{path       |.     | path to image files      }"
	     "{e height   |<none>| Sets the height of image }"
	     "{w width    |<none>| Sets the width of image  }"

     cv::CommandLineParser parser(argc, argv, keys);
     
     // If Help is passed, output help message
     if (parser.has("help")) {
     	parser.printMessage();
     }

     // Grabs image from Command Parser for reimaging
     cv::Mat img = cv::CommandLineParser::get<cv::Mat>("@image");
     cv::String img_name = cv::CommandLineParser::get<cv::String>("@image");
     cv::resize(img, img_rs, cv::Size(50,50));

     // Parameters to compress image to PNG 
     std::vector<int> compression_params;
     compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
     compression_params.push_back(9);

     // Writes image to location
     try {
	 cv::imwrite(img_name, img, compression_params);
     }
     catch (cv::Exception& ex) {
	 fprintf(stderr, "Exception coverting image to PNG: %s\n", 
		 ex.what());
	 return 1;
     }

     fprintf(stdout, "Saved PNG file");
     return 0;
}
