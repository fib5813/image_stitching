#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include <vector>
#include "kp_base.h"
#include "kp_orb.h"
#include "desc_base.h"
#include "desc_orb.h"
#include <opencv2/features2d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>

class Image{
    public:
    // class to keep track of each image path and keypoints in the image
    Image(std::string path){
        path_ = path;
        
        
    }
    void process(cv::Mat& img, bool f_display = false){
        kp_base* kp_class;
        kp_orb orb_kp;
        kp_class = &orb_kp;
        
        kp_class->preprocess();
        kp_class->set_tuning_params();
        keypoints_ = kp_class->get_keypoints(img);

        desc_base* desc_class;
        desc_orb orb_desc;
        desc_class = &orb_desc;

        desc_class->set_config();
        descriptors_ = desc_class->get_descriptors(img, keypoints_);

        if(f_display){
            display(img);
        }

    }

    void display(cv::Mat &img){
        cv::Mat img_keypoints;
        drawKeypoints(img, keypoints_, img_keypoints );
    }

    private:
    std::string path_;
    std::vector<cv::KeyPoint> keypoints_;
    std::vector<cv::Mat> descriptors_;
};



#endif