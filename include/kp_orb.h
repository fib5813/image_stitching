#ifndef __KP_ORB_H__
#define __KP_ORB_H__

#include "json.hpp"
#include "kp_base.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/features2d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types.hpp>



using json = nlohmann::json;

class kp_orb : public kp_base{
    void preprocess(){
        // convert to grayscale if reqd

    }
    void set_tuning_params(){
        std::ifstream i("/home/bubbles/image_stitching/include/config.json");
        json j;
        i >> j;

        j.at("orb").at("nfeatures").get_to(nfeatures);
        j.at("orb").at("scaleFactor").get_to(scaleFactor);
        j.at("orb").at("nlevels").get_to(nlevels);
        j.at("orb").at("edgeThreshold").get_to(edgeThreshold);
        j.at("orb").at("firstLevel").get_to(firstLevel);
        j.at("orb").at("patchSize").get_to(patchSize);
        
    }
    std::vector<cv::KeyPoint> get_keypoints(cv::Mat& img){
        std::vector<cv::KeyPoint> kp_out;
        cv::Ptr<cv::ORB> orb_detector= cv::ORB::create();
        orb_detector->detect(img, kp_out);

        // imshow("getting keypoints", img);
        // waitKey(0); // Wait for a keystroke in the window
        return kp_out;
    }


    int nfeatures=500; 
    float scaleFactor=1.2f; 
    int nlevels=8; 
    int edgeThreshold=31;
    int firstLevel=0; 
    int WTA_K=2; 
    int scoreType=cv::ORB::HARRIS_SCORE;
    int patchSize=31; 
    int fastThreshold=20;
    
};  



#endif