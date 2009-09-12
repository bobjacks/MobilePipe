/*
 ============================================================================
 Name		: AudioSender.cpp
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CAudioSender implementation
 ============================================================================
 */

#include "AudioSender.h"

CAudioSender::CAudioSender()
	{
	// No implementation required
	}

CAudioSender::~CAudioSender()
	{
	}

CAudioSender* CAudioSender::NewLC()
	{
	CAudioSender* self = new (ELeave) CAudioSender();
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

CAudioSender* CAudioSender::NewL()
	{
	CAudioSender* self = CAudioSender::NewLC();
	CleanupStack::Pop(); // self;
	return self;
	}

void CAudioSender::ConstructL()
	{
	
	
	}

// ----------------------------------------------------------------------------
// CAudioStreamEngine::MaoscOpenComplete(
//     TInt aError)
//
// called upon completion of CMdaAudioOutputStream::Open(),
// if the stream was opened succesfully (aError==KErrNone), it's ready for use.
// upon succesful open, the first audio data block will be written to the 
// output stream.
// ----------------------------------------------------------------------------
void CAudioSender::MaoscOpenComplete(TInt aError)
    {
    /*if (aError==KErrNone) 
        {
        // output stream opened succesfully, set status
        iOutputStatus = EOpen;
        // Set the data type (encoding). Should not fail, since we already
        // have tested support for this encoding in SetEncodingL with the 
        // corresponding input stream!
        TRAPD(error, iOutputStream->SetDataTypeL(iCurrentEncoding));
        PanicIfError(error);
        
        // set volume to 1/4th of stream max volume
        iOutputStream->SetVolume(iOutputStream->MaxVolume()/2);
        // set stream priority to normal and time sensitive
        iOutputStream->SetPriority(EPriorityNormal, 
            EMdaPriorityPreferenceTime);                
        ShowMessage(_L("Playing "), ETrue);

        if (iUseAMR)
            {
            // In case of AMR, the whole recorded/loaded buffer is played back at once, not frame by frame. 
            // The buffer might not be fully recorded, so we will only play back the part
            // that is filled with data.
            iStreamIdx = iStreamEnd;
            TRAPD(error2, iOutputStream->WriteL(GetPlaybackFrames(iStreamEnd)));
            PanicIfError(error2);
            }
        else
            {
            // PCM needs to be played back frame by frame, otherwise some older devices might
            // run into buffer overflow situations.
            iStreamIdx = 0;
            TRAPD(error3, iOutputStream->WriteL(GetFrame(iStreamIdx)));
            PanicIfError(error3);
            }
        }
    else 
        {
        // output stream open failed
        iOutputStatus = ENotReady;
        ShowMessage(_L("Playback failed!"), ETrue);
        } */      
    }

// ----------------------------------------------------------------------------
// CAudioStreamEngine::MaoscBufferCopied(
//     TInt aError, const TDesC8& aBuffer)
//
// called when a block of audio data has been written to MMF. calls to WriteL() 
// will be issued until all blocks in the audio data buffer (iStreamBuffer) are 
// written.
// ----------------------------------------------------------------------------
void CAudioSender::MaoscBufferCopied(TInt aError, const TDesC8& /*aBuffer*/)
    {
    /*if (aError==KErrNone) 
        {
        if (iStreamIdx==iStreamEnd)
            {
            ShowMessage(_L("\nPlayback complete!"), EFalse);
            // Playback is complete:
            // Start the active object that will stop the stream
            iStop->Start( TCallBack(BackgroundStop, this) );            
            }
        else 
            {
            iStreamIdx++;
            TRAPD(error, iOutputStream->WriteL(GetFrame(iStreamIdx)));  
            PanicIfError(error);
            }
        }
    else if (aError==KErrAbort) 
        {
        // Playing was aborted, due to call to CMdaAudioOutputStream::Stop().
        // MaoscRecordComplete() will be called after exiting this method.
        iOutputStatus = ENotReady;
        }
    else 
        {
        ShowMessage(_L("\nError writing data \nto output"), EFalse);            
        iOutputStatus = ENotReady;
        }*/
    }


// ----------------------------------------------------------------------------
// CAudioStreamEngine::MaoscPlayComplete(
//     TInt aError)
//
// called when output stream is closed by CMdaAudioOutputStream::Stop() or if 
// end of audio data has been reached, in this case KErrUnderflow will be 
// returned.
// ----------------------------------------------------------------------------
void CAudioSender::MaoscPlayComplete(TInt aError)
    {
    /*iOutputStatus = ENotReady;
    if (aError==KErrNone) 
        {
        // normal stream closure
        }   
    else if (aError==KErrUnderflow) 
        {
        // end of audio data stream was reached because of stream underflow,
        }
    else 
        {
        // completed with error(s)
        }*/   
    }
