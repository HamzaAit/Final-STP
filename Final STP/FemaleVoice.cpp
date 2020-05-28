#include "FemaleVoice.h"
#include <vector>






	


void FemaleVoice::setSpeech(string  A)
{
	
		/*cout << "Enter text:\n";
		cin.ignore(1,'\n');
		getline(wcin, input);*/

	wstring test;
	test.assign(A.begin(), A.end());

	
	//hr = pVoice->Speak((L"<voice required='Gender = Female;'>" + test).c_str(), 0, NULL);

		hr = pVoice->Speak(test.c_str(), 0, NULL);
}

void FemaleVoice::outSpeech()
{
	pVoice->Release();
	pVoice = NULL;
	::CoUninitialize();
}

void FemaleVoice::byeSpeech()
{
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak(L"<voice required='Gender = Female'> < rate absspeed = '-5' > Bhut Shukria Sir", 0, NULL);
	}

}
