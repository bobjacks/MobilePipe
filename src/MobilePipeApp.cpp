/*
 ============================================================================
 Name		: MobilePipeApp.cpp
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CMobilePipeApp implementation
 ============================================================================
 */

#include "MobilePipeApp.h"
#include <MobilePipeCaller.h>

CMobilePipeApp::CMobilePipeApp()
	{
	// No implementation required
	}

CMobilePipeApp::~CMobilePipeApp()
	{
	}

CMobilePipeApp* CMobilePipeApp::NewLC()
	{
	CMobilePipeApp* self = new (ELeave) CMobilePipeApp();
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

CMobilePipeApp* CMobilePipeApp::NewL()
	{
	CMobilePipeApp* self = CMobilePipeApp::NewLC();
	CleanupStack::Pop(); // self;
	return self;
	}

void CMobilePipeApp::ConstructL()
	{
	//console->Write(_L("Calling!\n"));
	CMobilePipeCaller* c = CMobilePipeCaller::NewL(CTelephony::NewL(), &CallEstablishedCallback);
	c->Dial();
	}

void CallEstablishedCallback(TRequestStatus iStatus)
	{
	
	}
