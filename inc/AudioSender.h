/*
 ============================================================================
 Name		: AudioSender.h
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CAudioSender declaration
 ============================================================================
 */

#ifndef AUDIOSENDER_H
#define AUDIOSENDER_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <MdaAudioOutputStream.h>

// CLASS DECLARATION

/**
 *  CAudioSender
 * 
 */
class CAudioSender : public CBase, MMdaAudioOutputStreamCallback
	{
public:
	// Constructors and destructor

	/**
	 * Destructor.
	 */
	~CAudioSender();

	/**
	 * Two-phased constructor.
	 */
	static CAudioSender* NewL();

	/**
	 * Two-phased constructor.
	 */
	static CAudioSender* NewLC();

private:

	/**
	 * Constructor for performing 1st stage construction
	 */
	CAudioSender();

	/**
	 * EPOC default constructor for performing 2nd stage construction
	 */
	void ConstructL();

	/*!
	 * MaoscOpenComplete()
	 *
	 * discussion A callback function that is called when 
	 *    CMdaAudioOutputStream::Open() has completed, indicating that the audio 
	 *    output stream is ready for use.
	 *
	 * param aError KErrNone if the open succeeded, otherwise one of the system 
	 *    error codes.
	 */
	virtual void MaoscOpenComplete(TInt aError);
	
	/*!
	 * MaoscBufferCopied()
	 *
	 * discussion A callback function that is called when a descriptor has been 
	 *    copied to the lower layers of MMF. It is also called when an error has 
	 *    occurred or when the client has stopped the stream playing before the 
	 *    descriptor has been fully copied (by calling 
	 *    CMdaAudioOutputStream::Stop())
	 *
	 * param aError KErrNone if the copy succeeded, otherwise one of the system
	 *    error codes. KErrAbort indicates that the client has stopped the stream
	 *    playing before the descriptor has been copied.
	 * param aBuffer reference to the buffer that has been copied.
	 */
	virtual void MaoscBufferCopied(TInt aError, const TDesC8& aBuffer);
		
	/*!
	 * MaoscPlayComplete()
	 *
	 * discussion A callback function that is called when playback terminates as
	 *    a result of a CMdaAudioOutputStream::Stop().
	 *
	 * param aError KErrNone if the close succeeded, otherwise one of the system
	 *    error codes.
	 */
	virtual void MaoscPlayComplete(TInt aError);
	};
	
#endif // AUDIOSENDER_H
