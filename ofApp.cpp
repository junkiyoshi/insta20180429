#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetColor(239);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius = 300;
	vector<ofColor> colors = { ofColor(239, 39, 39), ofColor(39, 239, 39), ofColor(39, 39, 239)};

	for (int i = 0; i < colors.size(); i++) {

		ofSetColor(colors[i], 239);

		ofBeginShape();
		for (int deg = 0; deg <= 360; deg += 1) {

			int x = radius * cos(deg * DEG_TO_RAD);
			int y = radius * sin(deg * DEG_TO_RAD);

			float noise_value = ofNoise(i, x * 0.001, y * 0.001, ofGetFrameNum() * 0.008);
			noise_value = floorf(noise_value * 10) * 0.1 + 0.25;

			x = (radius * noise_value) * cos(deg * DEG_TO_RAD);
			y = (radius * noise_value) * sin(deg * DEG_TO_RAD);

			ofVertex(ofPoint(x, y));
		}
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}