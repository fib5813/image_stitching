#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "Tailor.h"
#include "Streamer.h"

using namespace std;

/* this program reads in images in a folder and stitches the images 
   that are adjacent. 
*/ 


int main(int argc, char **argv){
    // std::cout << "And so it begins..." << std::endl;
    /*
    for all images in folder:
        load image
        find features
    find corresponences
    adjust image as required
    stitch image and store
    */
    if(argc < 2 || argc > 3){
        cout << "Usage: ./demo <absolute_image_path> " << endl; 
        return 0;
    }
    string path = argv[1];
    string ext = ".jpg";
    // cout << "num args = " << argc << " argv = " << path << endl;   

    Streamer streamer(path);
    Tailor tailor;
    auto img = streamer.get_image();
    
    while(img != nullptr){
        
        tailor.add(img, true);
        tailor.get_keypoints();
        img = streamer.get_image();
    }
    tailor.stitch();
   

    return 0;
}