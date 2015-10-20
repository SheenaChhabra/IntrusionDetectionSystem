/*
It contains:
*A "VideoProcessor class" which is used for processing any video file.
*A "FrameProcessor class" which is an abstract class used as an interface for frame processor.
*/


#ifndef VIDEO_PROCESSOR
#define VIDEO_PROCESSOR

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

//The frame processor interface
class FrameProcessor
{
public:
	//Processing Method
	virtual void process(Mat &input,Mat &output)= 0;
};

class VideoProcessor
{
private:
	// the OpenCV video capture object
    VideoCapture Input;
    
	string Input_Window_Name;
    string Output_Window_Name;
    int Delay;

	// the callback function to be called 
	// for the processing of each frame
	void (*Process)(Mat &,Mat &);

	// the pointer to the class implementing 
	// the FrameProcessor interface
    FrameProcessor *frameProcessor;
public:

    //Constructor
    VideoProcessor():Delay(0)
    {
    }

    //Setter Function
    bool Set_Input(string Input_Name)
    {
        return Input.open(Input_Name);
    }

    void Set_Input_Window(string Window_Name)
    {
        Input_Window_Name=Window_Name;
        namedWindow(Input_Window_Name);
    }

    void Set_Output_Window(string Window_Name)
    {
        Output_Window_Name=Window_Name;
        namedWindow(Output_Window_Name);
    }

    void Set_Process(void (*frameProcessingCallback)(Mat&,Mat&))
    {
        frameProcessor= 0;
        Process= frameProcessingCallback;
    }
    void Set_Process(FrameProcessor* frameProcessorPtr)
    {
        Process= 0;
        frameProcessor= frameProcessorPtr;
    }


    // Run Functions;
    void Run()
    {
		//current frame
        Mat Frame;

		// output frame
        Mat Output;

		//input frame rate
		double rate = Input.get(CV_CAP_PROP_FPS);
		
		//required delay in output
		Delay = 1000 / rate;

        bool stop(false);

        while(!stop)
        {
            if(!Input.read(Frame))
                break;

			//display input image
            imshow(Input_Window_Name,Frame);

			//applying the actual process on each frame
            if (Process)
                Process(Frame, Output);
            else if (frameProcessor)
                frameProcessor->process(Frame,Output);

			//display output image
            imshow(Output_Window_Name,Output);


            if (waitKey(Delay) >= 0)
			stop = true;

        }
    }
};

#endif // VIDEO_PROCESSOR
