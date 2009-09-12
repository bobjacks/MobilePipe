/*
 ============================================================================
 Name		: MobilePipeCaller.h
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CMobilePipeCaller declaration
 ============================================================================
 */

#ifndef MOBILEPIPECALLER_H
#define MOBILEPIPECALLER_H

#include <e32base.h>	// For CActive, link against: euser.lib
#include <e32std.h>		// For RTimer, link against: euser.lib
class CMobilePipeCaller : public CActive
	{
public:
	// Cancel and destroy
	~CMobilePipeCaller();

	// Two-phased constructor.
	static CMobilePipeCaller* NewL(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus));

	// Two-phased constructor.
	static CMobilePipeCaller* NewLC(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus));

	//Dialler
	void Dial();

public:
	// New functions
	// Function for making the initial request
	void StartL(TTimeIntervalMicroSeconds32 aDelay);

private:
	// C++ constructor
	CMobilePipeCaller();

	// Second-phase constructor
	void ConstructL(CTelephony* aTelephony, void (*callEstablishedCallback)(TRequestStatus));

private:
	// From CActive
	// Handle completion
	void RunL();

	// How to cancel me
	void DoCancel();

	// Override to handle leaves from RunL(). Default implementation causes
	// the active scheduler to panic.
	TInt RunError(TInt aError);

private:
	enum TMobilePipeCallerState
		{
		EUninitialized, // Uninitialized
		EInitialized, // Initalized
		EError
		// Error condition
		};

private:
	TInt iState; // State of the active object
	RTimer iTimer; // Provides async timing service

	CTelephony* _iTelephony;
	CTelephony::TCallId _iCallId;
	void (*_callEstablishedCallback)() = NULL;
	};

#endif // MOBILEPIPECALLER_H
