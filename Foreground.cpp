/*
Main Function: To detect the movement in fully restricted area by separating foreground and background.
Two methods are shown to extract foreground:
1. Running average Method
2. Mixture of Gaussian Method
*/

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include "Video_Processor.h"
#include "Running_Avg.h"
#include "Gaussian_Mixture.h"

using namespace cv;
using namespace std;

int main()
{
	// Foreground separation by Running average method

	// Creating instance of VideoProcessor
	VideoProcessor Processor1;

	// Creating instance of Running_Avg class
    	Running_Avg function1;

	//Set threshold value
    	function1.setThreshold(25);
	
	//Open video file
    	Processor1.Set_Input("video_feed.mp4");

	//Declare a window to display the input video 
    	Processor1.Set_Input_Window("Input Video");

	//Declare a window to display the output video
    	Processor1.Set_Output_Window("Extracted Foreground");

	//set frame processor
    	Processor1.Set_Process(&function1);

	//Start the process
    	Processor1.Run();

	///////////////////////////////////////////////////////////////////
    
	// Foreground separation by Mixture of Gaussian method

	// Creating instance of VideoProcessor
	VideoProcessor Processor2;

	// Creating instance of Running_Avg class
	Gaussian_Mixture function2;

	//Open video file
	Processor2.Set_Input("video_feed.mp4");

	//Declare a window to display the input video
	Processor2.Set_Input_Window("Input Video");

	//Declare a window to display the output video
	Processor2.Set_Output_Window("Extracted Foreground");

	//set frame processor
	Processor2.Set_Process(&function2);

	//Start the process
	Processor2.Run();
	
}
