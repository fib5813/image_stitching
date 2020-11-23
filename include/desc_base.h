#ifndef __DESC_SEL_H__
#define __DESC_SEL_H__

#include <opencv2/features2d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>

class desc_base{
    public:
    virtual void set_config() = 0;
    virtual cv::Mat get_descriptors(cv::Mat &img, std::vector<cv::KeyPoint>& keypoints)= 0;

};



#endif