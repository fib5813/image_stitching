#include <experimental/filesystem>
#include <iostream>
#include <memory>
#include "Streamer.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void Streamer::set_path(string path){
    path_ = path;
    list_files();
    
}

void Streamer::list_files(){
    for(const auto &image : std::experimental::filesystem::directory_iterator(path_)){
        // std::cout << image.path() << endl;
        files_.push(image.path());
    }
}

shared_ptr<Mat> Streamer::get_image(){
    if(files_.empty()) return nullptr;

    shared_ptr<Mat> out = make_shared<Mat>(imread(files_.top(), IMREAD_COLOR)); 
    if(out->empty())
    {
        // ideally should never get here
        std::cout << "Could not read the image: " << files_.top() << std::endl;
        return nullptr;
    }
    files_.pop();
    return out;

}

