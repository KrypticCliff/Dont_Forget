// Creates negative and positive images.

#include <iostream>
#include <curl/curl.h>
#include "boost/filesystem.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace fs = boost::filesystem;

int main(int argc, char** argv) {
     fs::path p("../img/neg_img/");
     std::vector<cv::Mat> img_v;
     cv::Mat img;
     //std::vector<std::string> img_filenames;

     // Path existance check
     if (!fs::exists(p) || !fs::is_directory(p)) {
          printf("No files exist in folder\n");
          return 1;
     }

     fs::recursive_directory_iterator begin(p), end;

     // Iterate through folder finds img files and converts to Grayscale
     try {
          for (int counter = 0; begin != end; begin++, counter++) {
               if (fs::is_regular_file(begin->path())) {
                    std::string str_counter = std::to_string(counter);
                    std::cout << begin->path().string() << " has been selected.\n";

                    // Places grayscale MAT into img_v vector
                    img_v.push_back(cv::imread(begin->path().string(), cv::IMREAD_GRAYSCALE));

                    // Resize and save as numbered jpg
                    cv::resize(img_v[counter], img_v[counter], cv::Size(100,100));
                    cv::imwrite("../img/cvt_neg_img/" + str_counter + ".jpg", img_v[counter]);

                    std::cout << counter << "\n";
                    printf("Converted...\n\n");
               }
          }
     }
     catch(std::exception& e) {
          std::cout << e.what() << "\n";
     }

     return 0;
}
