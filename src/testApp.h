#pragma once

#include "ofMain.h"

#include "Poco/Stopwatch.h"
#include "Poco/Thread.h"
#include "Poco/Timestamp.h"
#include "Poco/Timer.h"

using Poco::Stopwatch;
using Poco::Thread;
using Poco::Timer;
using Poco::TimerCallback;

class seqTimer
{
public:
    seqTimer()
    {
        stopwatch.start();
    }
	
    void onTimer(Timer& timer)
    {
		void seqTimerFunc(Poco::Timestamp::TimeDiff curTime); // prototype of my function
        seqTimerFunc(stopwatch.elapsed()); // function call
    }
	
private:
	Stopwatch stopwatch;
};


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	
	// and I declare in class testApp : public ofBaseApp
	seqTimer sTimer;
	Timer * timer;
};

