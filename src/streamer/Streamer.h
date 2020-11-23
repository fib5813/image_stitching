#ifndef __STREAMER_H__
#define __STREAMER_H__

#include <string>
#include <list>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class Streamer{
public:
    Streamer(string path = ""){
        path_ = path;
        list_files();
        counter_ = files_.begin();
    }
    void set_path(string path);
    shared_ptr<Mat> get_image();
    
private:
    void list_files();
    string path_;
    list<string> files_;
    list<string>::iterator counter_;
};

#endif