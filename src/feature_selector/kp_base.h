#ifndef __KD_BASE__
#define __KD_BASE__

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <vector>

class kp_base{
    public:
    virtual void preprocess() = 0;
    virtual void set_tuning_params() = 0;
    virtual std::vector<cv::KeyPoint> get_keypoints(cv::Mat& img) = 0;    
};
#endif