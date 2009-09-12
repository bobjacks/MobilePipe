/*
 ============================================================================
 Name		: AudioListener.h
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CAudioListener declaration
 ============================================================================
 */

#ifndef AUDIOLISTENER_H
#define AUDIOLISTENER_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <MdaAudioInputStream.h>
#include <mda/common/audio.h>

// CLASS DECLARATION

/**
 *  CAudioListener
 * 
 */
class CAudioListener : public CBase, MMdaAudioInputStreamCallback
	{
public:
	// Constructors and destructor

	/**
	 * Destructor.
	 */
	~CAudioListener();

	/**
	 * Two-phased constructor.
	 */
	static CAudioListener* NewL();

	/**
	 * Two-phased constructor.
	 */
	static CAudioListener* NewLC();

	void Record();
	void Stop();
	HBufC8* GetAudioBuffer(void);
	TBool StreamReady(){ return _iReady; };
	
private:

	/**
	 * Constructor for performing 1st stage construction
	 */
	CAudioListener();

	/**
	 * EPOC default constructor for performing 2nd stage construction
	 */
	void ConstructL();
	
	virtual void MaiscBufferCopied(TInt aError, const TDesC8 &aBuffer);
	virtual void MaiscOpenComplete(TInt aError);
	virtual void MaiscRecordComplete(TInt aError);

	TMdaTelephonyAudioDevice* _telephonyDevice;
	CMdaAudioInputStream* _iInputStream;
	
	TDes8*     _iStreamBuffer;
	TMdaAudioDataSettings     _iStreamSettings;
	TInt                     _iStreamIdx,_iPlayError;
	HBufC8*                 _iSoundData;
	TBool                     _iReady;
	
	};

#endif // AUDIOLISTENER_H
