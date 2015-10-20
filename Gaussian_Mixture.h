/*
Gaussian_Mixture class uses inbuilt function of OpenCV(based on Gaussian method) to separate foreground and background.
*/

#ifndef GAUSSIAN_MIXTURE
#define GAUSSIAN_MIXTURE

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Video_Processor.h"

using namespace cv;

class Gaussian_Mixture : public FrameProcessor {
	// The Mixture of Gaussian object
	// used with all default parameters
	BackgroundSubtractorMOG mog;
public:
    	void process(Mat &frame,Mat &output)
    	{
		// update the background
		// and return the foreground
        	mog(frame,output,0.01);

		// Complement the image
        	threshold(output,output,128,255,cv::THRESH_BINARY_INV);
    	}

};
#endif
