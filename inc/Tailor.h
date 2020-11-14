#ifndef __TAILOR_H__
#define __TAILOR_H__

#include <iostream>
#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

class Tailor{
    public:
    // Tailor(image);
    void add(shared_ptr<Mat> img, bool display = false);
    void display();
    // void preprocess();

    private:
    Mat curr_img_;

};

#endif