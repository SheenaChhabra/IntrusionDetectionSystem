# IntrusionDetectionSystem
An <b>'Intrusion Detection System'</b> for smart surveillance in any fully restricted area using Image Processing.

<b>Project Title:</b> An 'Intrusion Detection System' for smart surveillance in any fully restricted area using Image Processing.<br/>

<b>Introduction:</b><br/>
In today's world, security is rapidly replacing everything as the first and foremost concern when it comes to restricted or protected areas or areas of importance of national security like national border, research labs etc. There has been a significant rise in the number of surveillance cameras installed in such places and it becomes too difficult to get all those cameras 24x7hrs monitored by human, even when there is no intrusion by any unwanted object or person. So, there is a need of some intelligent solution so that all these cameras can be properly monitored with minimum human force.<br/>
This project aims at designing one such efficient solution i.e. an Intrusion Detection System for surveillance in completely restricted areas like national border etc. The key idea behind this solution is to process the live video feed using the potential of Image Processing.<br/><br/>

<b>Brief Description:</b><br/>
In a fully restricted area the unwanted intrusions can be detected by separating foreground(moving objects) and background(still objects).<br/>
The extraction of foreground from a given video frame can be achieved by using following two methods:<br/>
<b>1. Running average Method:</b> In this method, the running average of all the pixels is calculated to build the background model dynamically by regularly updating it. Then, the foreground pixels are calculated on the basis of the difference between the current image and the background model.<br/>
<b>2. Mixture of Gaussian Method:</b> In this method, more than one model per pixel is maintained to detect the fluctuating background with more accuracy.<br/>
