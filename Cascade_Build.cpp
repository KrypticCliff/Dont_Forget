// Train Cascade using negative and positive images.

#include <iostream>
#include <curl/curl.h>
#include "boost/filesystem.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace fs = boost::filesystem;

int main(int argc, char** argv) {
     fs::path p("./img/neg_img/");
     std::vector<cv::Mat> img_v;
     //std::vector<std::string> img_filenames;

     // Path existance check
     if (!fs::exists(p) || !fs::is_directory(p)) {
          printf("No files exist in folder\n");
          return 1;
     }

     fs::recursive_directory_iterator begin(p), end;

     // Iterate through folder findes img files and converts to Grayscale
     try {
          for (; begin != end; begin++) {
               if (fs::is_regular_file(begin->path())) {
               int img_counter = 0;
               //std::cout << begin->path().string() << " has been selected.\n";
               // Places grayscale MAT into img_v vector
               img_v.push_back(cv::imread(begin->path().string(), cv::IMREAD_GRAYSCALE));
               cv::resize(img_v[img_counter], img_v[img_counter], cv::Size(100,100));
               }
          }
     }
     catch(std::exception& e) {
          std::cout << e.what() << "\n";
     }

     return 0;
}
