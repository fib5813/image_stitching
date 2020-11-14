#include "Tailor.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

void Tailor::display(){
    imshow("Display window", curr_img_);
    waitKey(0); // Wait for a keystroke in the window
}

void Tailor::add(shared_ptr<Mat> img, bool f_display){
    curr_img_ = *img;
    if(f_display){
        display();
    }
}