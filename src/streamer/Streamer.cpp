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
    counter_ = files_.begin();
}

void Streamer::list_files(){
    for(const auto &image : std::experimental::filesystem::directory_iterator(path_)){
        // std::cout << image.path() << endl;
        files_.push_back(image.path());
    }
}

shared_ptr<Mat> Streamer::get_image(){
    if(files_.empty() || counter_ == files_.end()) return nullptr;

    shared_ptr<Mat> out = make_shared<Mat>(imread(*counter_, IMREAD_COLOR)); 
    if(out->empty())
    {
        counter_ = files_.end();
        // ideally should never get here
        std::cout << "Could not read the image: " << *counter_ << std::endl;
        return nullptr;
    }
    counter_++;
    return out;

}

