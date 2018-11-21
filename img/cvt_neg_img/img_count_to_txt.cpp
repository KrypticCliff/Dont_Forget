#include <iostream>
#include <ostream>
#include "boost/filesystem.hpp"

namespace fs = boost::filesystem;

int main(int argc, const char** argv) {
     std::string img_src = "./";
     std::string txt_dest = "../neg_count.txt";

     if(!fs::exists(txt_dest)) {
          std::cout << "Creating Negative Text File.\n";
     }

     std::ofstream neg_file;
     neg_file.open(txt_dest);

     fs::recursive_directory_iterator begin(img_src), end;

     for (int counter = 0; begin != end; begin++) {
          counter += 1;
          neg_file << counter << + ".jpg\n";
     }
     neg_file.close();

}
