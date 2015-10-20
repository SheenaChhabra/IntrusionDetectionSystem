/*
Running_Avg class computes the running average/moving average of each pixel to dynamically build a model of the
background scene and extract the foreground out of given frame.
*/

#ifndef RUNNING_AVG
#define RUNNING_AVG

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Video_Processor.h"

using namespace cv;
class Running_Avg : public FrameProcessor {

	Mat gray;			// current gray-level image
	Mat background;		    	// accumulated background
	Mat backImage;		    	// background image
	Mat foreground;		    	// foreground image
	double learningRate;    	// learning rate in background accumulation
	int Threshold;			// threshold for foreground extraction

  public:

	Running_Avg() : Threshold(10), learningRate(0.01) {}

	// Set the threshold used to declare a foreground
	void setThreshold(int t) {
		
		Threshold = t;
	}

	// Set the learning rate
	void setLearningRate(double r) {

		learningRate= r;
	}

	// processing method
	void process(Mat &frame,Mat &output) {

		// convert to gray-level image
		cvtColor(frame, gray, CV_BGR2GRAY);
	
		// initialize background to 1st frame
		if (background.empty())
			gray.convertTo(background, CV_32F);
	
		// convert background to 8U
		background.convertTo(backImage,CV_8U);
	
		// compute difference between current image and background
		absdiff(backImage,gray,foreground);
	
		// apply threshold to foreground image
		threshold(foreground, output, Threshold, 255, cv::THRESH_BINARY_INV);
	
		// accumulate background
		accumulateWeighted(gray, background, learningRate, output);
	}
};

#endif

