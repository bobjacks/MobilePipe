/*
 * AudioOutputStreamCallbackImpl.h
 *
 *  Created on: Sep 11, 2009
 *      Author: bill
 */

#ifndef MMDAAUDIOOUTPUTSTREAMCALLBACKIMPL_H_
#define MMDAAUDIOOUTPUTSTREAMCALLBACKIMPL_H_

#include<MdaAudioOutputStream.h>
#include <e32base.h>
#include <e32std.h>
#include <e32cons.h>			// Console

class MMdaAudioOutputStreamCallbackImpl : MMdaAudioOutputStreamCallback
{

public:
	void MaoscBufferCopied(TInt aError, const TDesC8 &aBuffer);
	void MaoscOpenComplete(TInt aError);
	void MaoscPlayComplete(TInt aError);
	
};

#endif /* MMDAAUDIOOUTPUTSTREAMCALLBACKIMPL_H_ */
