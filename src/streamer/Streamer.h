#ifndef __STREAMER_H__
#define __STREAMER_H__

#include <string>
#include <stack>
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
        
    }
    void set_path(string path);
    shared_ptr<Mat> get_image();
    
private:
    void list_files();
    string path_;
    stack<string> files_;
};

#endif