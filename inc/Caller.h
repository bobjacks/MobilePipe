/*
 * Caller.h
 *
 *  Created on: Sep 11, 2009
 *      Author: bill
 */

#ifndef CALLER_H_
#define CALLER_H_

#include <e32base.h>
#include <Etel3rdParty.h>

class Caller : public CActive
{
private:
	CTelephony* iTelephony;
	CTelephony::TCallId iCallId;
	void RunL();
	void DoCancel();

public:
	Caller(CTelephony* aTelephony);
	void Dial();
};

#endif /* CALLER_H_ */
