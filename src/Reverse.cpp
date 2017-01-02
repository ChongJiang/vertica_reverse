/* Copyright (c) 2005 - 2012 Vertica, an HP company -*- C++ -*- */
/* 
 *
 * Description: User Defined Scalar Function: reverse string
 *
 * Create Date: Apr 29, 2011
 */
#include "Vertica.h"

using namespace Vertica;

/*
 * This is a simple function that removes all spaces from the input string
 */
class Reverse : public ScalarFunction
{
public:

    /*
     * This method processes a block of rows in a single invocation.
     *
     * The inputs are retrieved via argReader
     * The outputs are returned via resWriter
     */
    virtual void processBlock(ServerInterface &srvInterface,
                              BlockReader &argReader,
                              BlockWriter &resWriter)
    {
        try {
            // Basic error checking
            if (argReader.getNumCols() != 1)
                vt_report_error(0, "Function only accept 1 arguments, but %zu provided", 
                                argReader.getNumCols());

            // While we have inputs to process
            do {
                // Get a copy of the input string
                VString inVStr = argReader.getStringRef(0);

                // reverse string into results
                if( ! inVStr.isNull() ) {
                  std::string inStr = inVStr.str();
                  std::string outStr;
                  outStr.assign( inStr.rbegin(), inStr.rend() );
                  resWriter.getStringRef().copy(outStr);
                }
                else {
                  resWriter.getStringRef().setNull();
                }
               	
                resWriter.next();
            } while (argReader.next());
        } catch(std::exception& e) {
            // Standard exception. Quit.
            vt_report_error(0, "Exception while processing block: [%s]", e.what());
        }
    }
};

class ReverseFactory : public ScalarFunctionFactory
{
    // return an instance of Reverse to perform the actual addition.
    virtual ScalarFunction *createScalarFunction(ServerInterface &interface)
    { return vt_createFuncObj(interface.allocator, Reverse); }

    virtual void getPrototype(ServerInterface &interface,
                              ColumnTypes &argTypes,
                              ColumnTypes &returnType)
    {
        argTypes.addVarchar();
        returnType.addVarchar();
    }

    virtual void getReturnType(ServerInterface &srvInterface,
                               const SizedColumnTypes &argTypes,
                               SizedColumnTypes &returnType)
    {
        const VerticaType &t = argTypes.getColumnType(0);
        
        int len = t.getStringLength();
        if(len <=0) len=1;
        
        returnType.addVarchar(len);
    }
};

RegisterFactory(ReverseFactory);

