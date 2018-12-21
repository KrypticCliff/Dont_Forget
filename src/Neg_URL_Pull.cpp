// Creates grayscale negative images and resizes to 100 x 100.
// Only images placed in 'img/neg_img/' will be converted
// Output files will be placed in 'img/cvt_neg_img/'
// Used for training Image Cascades.

#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

// Stream for CURL inputs
static size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userp) {
     FILE* stream = (FILE*)userp;

     // Error check
     if (!stream) {
          printf("No stream available\n");
          return 0;
     }

     ((std::string*)userp)->append((char*)ptr, 0, size * nmemb);
     return size * nmemb;
} // WriteCallback function

int main(int argc, char** argv) {
     fs::path url_file_chk("url_list.txt");
     fs::path neg_img_dst("../img/neg_img");

// Check if list of urls exists; if not, create a new file.
     if (!fs::exists(url_file_chk)) {
          std::cout << "File Does Not Exist. Creating File...\n";
          std::ofstream url_txt("url_list.txt");
          url_txt.close();
     }

// Check if negative image folder exists; if not, create a new directory.
     if (!fs::exists(neg_img_dst)) {
          std::cout << "Negative Image Destination Does Not Exist. Creating Folder...\n";
          fs::create_directory("../img/neg_img");
     }

     std::ofstream url_txt("./url_list.txt");
     std::string url_content;
     char const *url = "http://image-net.org/api/text/imagenet.synset.geturls?wnid=n09618957";
     CURL *curl = curl_easy_init();
     CURLcode res;

// Pulls URLs from Image-Net
     try {
          curl_easy_setopt(curl, CURLOPT_URL, url);
          curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
          curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url_content);
          res = curl_easy_perform(curl);

          url_txt << url_content;

     } catch (int e) {
          std::cerr << "Error using CURL: " << e << "\n";
          return -1;
     }

     //std::cout << url_content;
     if (res) {
          std::printf("Error: %d\n", res);
     }

// Clean up
     curl_easy_cleanup(curl);
     url_txt.close();
     return 0;

} // Main
