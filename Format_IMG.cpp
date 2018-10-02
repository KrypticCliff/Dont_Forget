#include <iostream>
#include <fstream>
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core.hpp"

int main(int argc, char** argv) {
     cv::Mat img_rs;
<<<<<<< HEAD
//     const int MAX_SIZE = 255;
//     char* filename[MAX_SIZE];
     const cv::String keys =
	     "{help h     |      | Prints help message      }"
	     "{@image 	   |      | image used for resizing  }"
          "{@height    |50    | Sets the height of image }"
	     "{@width     |50    | Sets the width of image  }"
	     "{path       |.     | path to image files      }";

     cv::CommandLineParser parser(argc, argv, keys);

=======
     const int MAX_SIZE = 255;
     char* filename[MAX_SIZE];
     const cv::String keys = 
	     "{help     h |   	 | Prints help message      }"
	     "{@image 	  |<none>| image used for resizing  }"
	     "{path       |.     | path to image files      }"
	     "{e height   |<none>| Sets the height of image }"
	     "{w width    |<none>| Sets the width of image  }"

     cv::CommandLineParser parser(argc, argv, keys);
     
>>>>>>> b7a71a89640f25ab5a55c4d32f863368fa0aef7d
     // If Help is passed, output help message
     if (parser.has("help")) {
     	parser.printMessage();
     }

     // Grabs image from Command Parser for reimaging
<<<<<<< HEAD
     cv::String img_name = parser.get<cv::String>(0);
     cv::Mat img = cv::imread("/home/kryptic/OpenCV_Practice/index.png");
     cv::resize(img, img_rs, cv::Size(parser.get<double>(1),parser.get<double>(2)),
                0, 0, cv::INTER_NEAREST);

     // Checks if parser has thrown any errors
     if (!parser.check()) {
          parser.printErrors();
          return 0;
     }

     // Parameters to compress image to PNG
=======
     cv::Mat img = cv::CommandLineParser::get<cv::Mat>("@image");
     cv::String img_name = cv::CommandLineParser::get<cv::String>("@image");
     cv::resize(img, img_rs, cv::Size(50,50));

     // Parameters to compress image to PNG 
>>>>>>> b7a71a89640f25ab5a55c4d32f863368fa0aef7d
     std::vector<int> compression_params;
     compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
     compression_params.push_back(9);

     // Writes image to location
<<<<<<< HEAD
	cv::imwrite("Test.png", img_rs);

=======
     try {
	 cv::imwrite(img_name, img, compression_params);
     }
     catch (cv::Exception& ex) {
	 fprintf(stderr, "Exception coverting image to PNG: %s\n", 
		 ex.what());
	 return 1;
     }

     fprintf(stdout, "Saved PNG file");
>>>>>>> b7a71a89640f25ab5a55c4d32f863368fa0aef7d
     return 0;
}
