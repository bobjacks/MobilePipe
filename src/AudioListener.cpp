/*
 ============================================================================
 Name		: AudioListener.cpp
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CAudioListener implementation
 ============================================================================
 */

#include "AudioListener.h"

CAudioListener::CAudioListener()
:_iInputStream(NULL),_iStreamIdx(0)
	{
	// No implementation required
	}

CAudioListener* CAudioListener::NewLC()
	{
	CAudioListener* self = new (ELeave) CAudioListener();
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

CAudioListener* CAudioListener::NewL()
	{
	CAudioListener* self = CAudioListener::NewLC();
	CleanupStack::Pop(); // self;
	return self;
	}

CAudioListener::~CAudioListener()
{    
    if(_iInputStream)
    {
        _iInputStream->Stop();
        delete _iInputStream;
    }
 
    if(_iSoundData)
    {
        delete _iSoundData;
    }
 
}

void CAudioListener::ConstructL()
	{ 
		_iReady = EFalse;
		//CMdaAudioInputStream::NewL()
		_iInputStream = CMdaAudioInputStream::NewL(*this, EMdaPriorityMax, EMdaPriorityPreferenceQuality);
						//_inStream = CMdaAudioInputStream::NewL(this, NULL);
		*_telephonyDevice = TMdaTelephonyAudioDevice(); //todo, replace with common devic efor both sending and receiving 
		_iInputStream->Open(_telephonyDevice);
		
	}

void CAudioListener::MaiscBufferCopied(TInt aError, const TDesC8 &aBuffer)
	{
	_iPlayError = aError;
	if (aError==KErrNone && _iInputStream) 
	{
		//TODO: Print 
		_iInputStream->ReadL(*_iStreamBuffer);
	}
	}

void CAudioListener::MaiscOpenComplete(TInt aError)
	{
	_iPlayError = aError;
	if (aError==KErrNone && _iInputStream) 
	{    
		_iReady = ETrue;
 
		_iStreamIdx=0;
		_iInputStream->ReadL(*_iStreamBuffer);
	}
	}

void CAudioListener::MaiscRecordComplete(TInt aError)
	{
	_iPlayError = aError;
	}
