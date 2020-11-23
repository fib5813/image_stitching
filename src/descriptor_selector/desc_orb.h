#ifndef __DESC_ORB__
#define __DESC_ORB__


#include "json.hpp"
#include "desc_base.h"
#include <fstream>
#include <vector>
#include <opencv2/features2d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>

using json = nlohmann::json;

class desc_orb : public desc_base{

    void set_config(){
        // json j;
        // std::ifstream i("/home/bubbles/image_stitching/src/feature_selector/config.json");
        // i << j;

    }

    cv::Mat get_descriptors(cv::Mat &img, std::vector<cv::KeyPoint>& keypoints){
        cv::Ptr<cv::DescriptorExtractor> extractor;
        cv::Mat desc_output;
        extractor->compute(img, keypoints, desc_output);
        return desc_output;

    }

};


#endif