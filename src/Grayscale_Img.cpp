// Creates grayscale negative images and resizes to 100 x 100.
// Only images placed in 'img/neg_img/' will be converted
// Output files will be placed in 'img/cvt_neg_img/'
// Used for training Image Cascades.

#include <iostream>
#include "boost/filesystem.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace fs = boost::filesystem;

int main(int argc, char** argv) {
     cv::Mat img;
     std::vector<cv::Mat> img_v;
     fs::path p("../img/neg_img/");

     // Path existance check
     if (!fs::exists(p) || !fs::is_directory(p)) {
          printf("No files exist in folder\n");
          return -1;
     }

     fs::recursive_directory_iterator begin(p), end;

     // Iterate through folder finds img files and converts to Grayscale
     try {
          for (int counter = 0; begin != end; begin++, counter++) {
               if (fs::is_regular_file(begin->path())) {
                    // extract file extension from file.
                    std::string file_ext = begin->path().extension().string();

                    // Counter for cvted image; Creates increment number name
                    // Ex. filename: 1.jpg, 2.jpg, ... , n.jpg
                    std::string str_counter = std::to_string(counter);
                    std::cout << begin->path().string() <<
                         " has been selected.\n";

                    // Places grayscale MAT into img_v vector
                    img_v.push_back(cv::imread(begin->path().string(),
                         cv::IMREAD_GRAYSCALE));

                    // Resize and save as numbered jpg
                    cv::resize(img_v[counter], img_v[counter],
                         cv::Size(100,100));

                    cv::imwrite("../img/cvt_neg_img/" + str_counter + file_ext,
                         img_v[counter]);

                    std::cout << counter << "\n";
                    printf("Converted...\n\n");
               } // If Statement

          } // For Statement

     } // Try Statement
     catch(std::exception& e) {
          std::cout << e.what() << "\n";
     }

     return 0;
}
