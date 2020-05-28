#pragma once
#include "BasicVoice.h"
#include <vector>

extern vector <string> weaving_result;

class FemaleVoice : public BasicVoice
{
public:
	void setSpeech(string A);
	void outSpeech();
	void byeSpeech();
};