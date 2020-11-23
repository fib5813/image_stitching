#ifndef __TAILOR_H__
#define __TAILOR_H__

#include <iostream>
#include <memory>
#include <list>
#include "Image.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>


using namespace cv;
using namespace std;

class Tailor{
public:
    // Tailor(image);
    // set current image and display image according to input
    void add(shared_ptr<Mat> img, bool display = false);

    // method to display image
    void display();

    // method to undistort input images
    void undistort(); 

    // method to find keypoints in images, store the keypoints mapped to images as 
    void get_keypoints(string feature_type = "ORB");  

    //match best keypoints in the list of keypoints for different images, 
    void match_keypoints();

    // use the matches found to find seams between images and merge the images
    void stitch();

private:
    Mat curr_img_;
    // vector<Mat> images_;
    list<Image> input_images;

};

#endif