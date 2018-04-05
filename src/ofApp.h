#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void updateFrameRateAudio();
		//void audioIn(float * input, int bufferSize, int nChannels);
		void audioIn(ofSoundBuffer &outBuffer);

		void drawBufferSample(const float buffer[], const int numChannels, const int channel, const int bufferSize, float x, float y, float width, float height);
		void drawBufferSample(const ofSoundBuffer &soundBuffer, const int channel, float x, float y, float width, float height);

		ofSoundStream soundStream;
		const int numChannels = 12;
		const int bufferSize = 512;
		float *buffer;
		float lastTime;
		float frameRateAudio;

		ofSoundBuffer lastBuffer;
};
