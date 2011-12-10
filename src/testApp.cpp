#include "testApp.h"

Poco::Timestamp::TimeDiff hdelay = 125000; // delay between 2 events, in microseconds
Poco::Timestamp::TimeDiff nextTime = 0;    // time when next event occurs (calculated in seqTimerFunc)

void seqTimerFunc(Poco::Timestamp::TimeDiff curTime);
void seqTimerFunc(Poco::Timestamp::TimeDiff curTime)
// Events that are regularly sent are processed here
{
    if(curTime >= nextTime) {
        nextTime += hdelay;
		cout <<  (long)(curTime / 1000) <<  " .. " << (long)(nextTime / 1000) << endl;
		// Execute real messages (midi etc) here ...
    }
}

//--------------------------------------------------------------
void testApp::setup(){
	// and in the method void testApp::setup()
	timer = new Timer(0, 10); // parameters : immediate and delay of 10 milliseconds (fast enough i think)
	timer->start(TimerCallback<seqTimer>(sTimer, &seqTimer::onTimer), Thread::PRIO_HIGHEST);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

void testApp::exit(){
	delete timer;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}