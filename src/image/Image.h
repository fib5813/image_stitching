#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include <vector>
#include "kp_base.h"
#include "orb.h"
#include <opencv2/features2d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>

class Image{
    public:
    // class to keep track of each image path and keypoints in the image
    Image(std::string path, cv::Mat& img){
        path_ = path;
        
        kp_base* kp_class;
        orb orb_obj;
        kp_class = &orb_obj;
        
        kp_class->preprocess();
        kp_class->set_tuning_params();
        keypoints_ = kp_class->get_keypoints(img);

    }

    private:
    std::string path_;
    std::vector<cv::KeyPoint> keypoints_;
};



#endif