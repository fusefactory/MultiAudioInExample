#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(54, 54, 54);

	// 0 output channels, 
	// 12 input channels
	// 44100 samples per second
	// 512 samples per buffer
	// 4 num buffers (latency) ??

	soundStream.printDeviceList();
	
	//if you want to set a different device id 
	soundStream.setDeviceID(3); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
	buffer = new float[numChannels * bufferSize];
	soundStream.setup(this, 0, numChannels, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::drawBufferSample(const ofSoundBuffer &soundBuffer, const int channel, float x, float y, float width, float height) {
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(x, y, 0);

	ofDrawRectangle(0, 0, width, height);
	ofDrawBitmapString(ofToString(channel + 1), -15, height / 2.0);

	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);

	ofBeginShape();
	for (unsigned int i = 0; i < soundBuffer.getNumFrames(); i++) {
		const float sampleValue = soundBuffer.getSample(i, channel);

		float x = 1.0 * i / bufferSize * width;
		float y = height / 2.0 + sampleValue * height / 2.0;
		ofVertex(x, y);
	}
	ofEndShape(false);

	ofPopStyle();
	ofPopMatrix();
}

void ofApp::drawBufferSample(const float buffer[], const int numChannels,const int channel, const int bufferSize, float x, float y, float width, float height) {
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(x, y, 0);

	ofDrawRectangle(0, 0, width, height);
	ofDrawBitmapString(ofToString(channel+1), -15, height / 2.0);

	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);

	ofBeginShape();
	for (unsigned int i = 0; i < bufferSize ; i++) {
		 const float sampleValue = buffer[i * numChannels + channel];

		float x = 1.0 * i / bufferSize * width;
		float y = height / 2.0 + sampleValue * height / 2.0;
		ofVertex(x, y);
	}
	ofEndShape(false);

	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::draw(){

	float w = (ofGetWidth() - 75) / 2.0;
	float h = ((ofGetHeight() - 40) / (numChannels / 2.0)) - 10;

	for (int channel = 0; channel < numChannels; channel++) {
		float x = channel % 2 * (w + 25) + 25;
		float y = channel / 2 * (h + 10) + 25;
		//drawBufferSample(buffer, numChannels, channel, bufferSize, x, y, w, h);
		drawBufferSample(lastBuffer, channel, x, y, w, h);
	}

	ofDrawBitmapStringHighlight("fps: " + ofToString(ofGetFrameRate()), 15, 15, ofColor(255, 0, 0), ofColor(0));
	ofDrawBitmapStringHighlight("fps Audio: " + ofToString((int) frameRateAudio), 150, 15, ofColor(255, 0, 0), ofColor(0));

}

void ofApp::updateFrameRateAudio() {
	float currentTime = ofGetElapsedTimef();

	frameRateAudio = 1.0 / (ofGetElapsedTimef() - lastTime);
	lastTime = currentTime;
}

/* //Alternative way is using directly float pointer buffer
 
 void ofApp::audioIn(float * input, int bufferSize, int nChannels) {
	updateFrameRateAudio();
	memcpy(buffer, input, sizeof(float) * nChannels * bufferSize);

	for (int i = 0; i < bufferSize * nChannels; i++) {
		buffer[i] = input[i];
	}
}*/

void ofApp::audioIn(ofSoundBuffer &inBuffer) {
	updateFrameRateAudio();
	lastBuffer = inBuffer;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
