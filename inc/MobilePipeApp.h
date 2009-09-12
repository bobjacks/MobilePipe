/*
 ============================================================================
 Name		: MobilePipeApp.h
 Author	  : 
 Version	 : 1.0
 Copyright   : Your copyright notice
 Description : CMobilePipeApp declaration
 ============================================================================
 */

#ifndef MOBILEPIPEAPP_H
#define MOBILEPIPEAPP_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <Etel3rdParty.h>
#include <MobilePipeCaller.h>

// CLASS DECLARATION

/**
 *  CMobilePipeApp
 * 
 */
class CMobilePipeApp : public CBase
	{
public:
	// Constructors and destructor

	/**
	 * Destructor.
	 */
	~CMobilePipeApp();

	/**
	 * Two-phased constructor.
	 */
	static CMobilePipeApp* NewL();

	/**
	 * Two-phased constructor.
	 */
	static CMobilePipeApp* NewLC();

private:

	/**
	 * Constructor for performing 1st stage construction
	 */
	CMobilePipeApp();

	/**
	 * EPOC default constructor for performing 2nd stage construction
	 */
	void ConstructL();

	};

	void CallEstablishedCallback(TRequestStatus iStatus);

#endif // MOBILEPIPEAPP_H
