/*
 ============================================================================
 Name		: MobilePipeCaller.cpp
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CMobilePipeCaller implementation
 ============================================================================
 */

#include "MobilePipeCaller.h"

CMobilePipeCaller::CMobilePipeCaller() :
	CActive(EPriorityStandard) // Standard priority
	{
	}

CMobilePipeCaller* CMobilePipeCaller::NewLC(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus))
	{
	CMobilePipeCaller* self = new (ELeave) CMobilePipeCaller();
	CleanupStack::PushL(self);
	self->ConstructL(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus));
	return self;
	}

CMobilePipeCaller* CMobilePipeCaller::NewL(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus))
	{
	CMobilePipeCaller* self = CMobilePipeCaller::NewLC();
	CleanupStack::Pop(); // self;
	return self;
	}

void CMobilePipeCaller::ConstructL(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus))
	{
	 _iTelephony = aTelephony;
     _callEstablishedCallback = callEstablishedCallback;

	User::LeaveIfError(iTimer.CreateLocal()); // Initialize timer
	CActiveScheduler::Add(this); // Add to scheduler
	}

void CMobilePipeCaller::Dial()
	{
	CTelephony::TTelNumber telNumber(KTheNumber);

	CTelephony::TCallParamsV1 callParams;
	callParams.iIdRestrict = CTelephony::ESendMyId;
	CTelephony::TCallParamsV1Pckg callParamsPckg(callParams);

	CActiveScheduler::Start();
	CActiveScheduler::Add(this);
	_iTelephony->DialNewCall(iStatus, callParamsPckg, telNumber, _iCallId);
	SetActive();
	}

CMobilePipeCaller::~CMobilePipeCaller()
	{
	Cancel(); // Cancel any request, if outstanding
	iTimer.Close(); // Destroy the RTimer object
	// Delete instance variables if any
	}

void CMobilePipeCaller::DoCancel()
	{
    _iTelephony->CancelAsync(CTelephony::EDialNewCallCancel);
	iTimer.Cancel();
	}

void CMobilePipeCaller::StartL(TTimeIntervalMicroSeconds32 aDelay)
	{
	Cancel(); // Cancel any request, just to be sure
	iState = EUninitialized;
	iTimer.After(iStatus, aDelay); // Set for later
	SetActive(); // Tell scheduler a request is active
	}

void CMobilePipeCaller::RunL()
	{
	/*if (iState == EUninitialized)
		{
		// Do something the first time RunL() is called
		iState = EInitialized;
		}
	else if (iState != EError)
		{
		// Do something
		}
	iTimer.After(iStatus, 1000000); // Set for 1 sec later
	SetActive(); // Tell scheduler a request is active*/
	
    (*_callEstablishedCallback)(iStatus);
    
	}

TInt CMobilePipeCaller::RunError(TInt aError)
	{
	return aError;
	}
