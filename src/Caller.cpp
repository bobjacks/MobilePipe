/*
 * Caller.cpp
 *
 *  Created on: Sep 11, 2009
 *      Author: bill
 */

#include "Caller.h"

_LIT(KTheNumber, "2159171999");  //Bill's Phone

Caller::Caller(CTelephony* aTelephony)
    : CActive(EPriorityStandard),
      iTelephony(aTelephony)
    {
    //default constructor
    }

void Caller::RunL()
    {
    if(iStatus==KErrNone)
       {} // The call has been dialled successfully;
          // iCallId contains the call's ID, needed when controlling the call.
    }

void Caller::Dial()
	{
	CTelephony::TTelNumber telNumber(KTheNumber);

	CTelephony::TCallParamsV1 callParams;
	callParams.iIdRestrict = CTelephony::ESendMyId;
	CTelephony::TCallParamsV1Pckg callParamsPckg(callParams);

	CActiveScheduler::Start();
	CActiveScheduler::Add(this);
	iTelephony->DialNewCall(iStatus, callParamsPckg, telNumber, iCallId);
	SetActive();
	}

void Caller::DoCancel()
	{
    iTelephony->CancelAsync(CTelephony::EDialNewCallCancel);
    }
