////////////////////////////////////////////////////////////////////////////////
// CppSQLite3 - A C++ wrapper around the SQLite3 embedded database library.
//
// Copyright (c) 2004 Rob Groves. All Rights Reserved. rob.groves@btinternet.com
//
// Permission to use, copy, modify, and distribute this software and its
// documentation for any purpose, without fee, and without a written
// agreement, is hereby granted, provided that the above copyright notice,
// this paragraph and the following two paragraphs appear in all copies,
// modifications, and distributions.
//
// IN NO EVENT SHALL THE AUTHOR BE LIABLE TO ANY PARTY FOR DIRECT,
// INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST
// PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
// EVEN IF THE AUTHOR HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// THE AUTHOR SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF
// ANY, PROVIDED HEREUNDER IS PROVIDED "AS IS". THE AUTHOR HAS NO OBLIGATION
// TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
//
// V3.0		03/08/2004	-Initial Version for sqlite3
//
// V3.1		16/09/2004	-Implemented getXXXXField using sqlite3 functions
//						-Added CppSQLiteDB3::tableExists()
////////////////////////////////////////////////////////////////////////////////
#ifndef _CppSQLite3_H_
#define _CppSQLite3_H_

#include "sqlite3.h"
#include <cstdio>
#include <cstring>

#define CPPSQLITE_ERROR 1000

class CppSQLite3Exception
{
public:

    CppSQLite3Exception(const int nErrCode,
                    char* szErrMess,
                    bool bDeleteMsg=true);

    CppSQLite3Exception(const CppSQLite3Exception&  e);

    virtual ~CppSQLite3Exception();

    const int errorCode() { return mnErrCode; }

    const char* errorMessage() { return mpszErrMess; }

    static const char* errorCodeAsString(int nErrCode);

private:

    int mnErrCode;
    char* mpszErrMess;
};


class CppSQLite3Buffer
{
public:

    CppSQLite3Buffer();

    ~CppSQLite3Buffer();

    const char* format(const char* szFormat, ...);

    operator const char*() { return mpBuf; }

    void clear();

private:

    char* mpBuf;
};


class CppSQLite3Binary
{
public:

    CppSQLite3Binary();

    ~CppSQLite3Binary();

    void setBinary(const unsigned char* pBuf, int nLen);
    void setEncoded(const unsigned char* pBuf);

    const unsigned char* getEncoded();
    const unsigned char* getBinary();

    int getBinaryLength();

    unsigned char* allocBuffer(int nLen);

    void clear();

private:

    unsigned char* mpBuf;
    int mnBinaryLen;
    int mnBufferLen;
    int mnEncodedLen;
    bool mbEncoded;
};


//##ModelId=4CCD9A7C03A9
class CppSQLite3Query
{
public:

    //##ModelId=4CCD9A7D01E5
    CppSQLite3Query();

    //##ModelId=4CCD9A7D01E6
    CppSQLite3Query(const CppSQLite3Query& rQuery);

    //##ModelId=4CCD9A7D01E8
    CppSQLite3Query(sqlite3* pDB,
				sqlite3_stmt* pVM,
                bool bEof,
                bool bOwnVM=true);

    //##ModelId=4CCD9A7D01F6
    CppSQLite3Query& operator=(const CppSQLite3Query& rQuery);

    //##ModelId=4CCD9A7D01F8
    virtual ~CppSQLite3Query();

    //##ModelId=4CCD9A7D01FA
    int numFields();

    //##ModelId=4CCD9A7D01FB
    int fieldIndex(const char* szField);
    //##ModelId=4CCD9A7D01FD
    const char* fieldName(int nCol);

    //##ModelId=4CCD9A7D0204
    const char* fieldDeclType(int nCol);
    //##ModelId=4CCD9A7D0206
    int fieldDataType(int nCol);

    //##ModelId=4CCD9A7D0208
    const char* fieldValue(int nField);
    //##ModelId=4CCD9A7D020A
    const char* fieldValue(const char* szField);

    //##ModelId=4CCD9A7D0213
    int getIntField(int nField, int nNullValue=0);
    //##ModelId=4CCD9A7D0216
    int getIntField(const char* szField, int nNullValue=0);

    //##ModelId=4CCD9A7D0219
    double getFloatField(int nField, double fNullValue=0.0);
    //##ModelId=4CCD9A7D021C
    double getFloatField(const char* szField, double fNullValue=0.0);

    //##ModelId=4CCD9A7D0223
    const char* getStringField(int nField, const char* szNullValue="");
    //##ModelId=4CCD9A7D0226
    const char* getStringField(const char* szField, const char* szNullValue="");

    //##ModelId=4CCD9A7D0229
    const unsigned char* getBlobField(int nField, int& nLen);
    //##ModelId=4CCD9A7D022C
    const unsigned char* getBlobField(const char* szField, int& nLen);

    //##ModelId=4CCD9A7D0234
    bool fieldIsNull(int nField);
    //##ModelId=4CCD9A7D0236
    bool fieldIsNull(const char* szField);

    //##ModelId=4CCD9A7D0242
    bool eof();

    //##ModelId=4CCD9A7D0243
    void nextRow();

    //##ModelId=4CCD9A7D0244
    void finalize();

private:

    //##ModelId=4CCD9A7D0245
    void checkVM();

    //##ModelId=4CCD9A7D01C7
	sqlite3* mpDB;
    //##ModelId=4CCD9A7D01D4
    sqlite3_stmt* mpVM;
    //##ModelId=4CCD9A7D01D5
    bool mbEof;
    //##ModelId=4CCD9A7D01D6
    int mnCols;
    //##ModelId=4CCD9A7D01E4
    bool mbOwnVM;
};


class CppSQLite3Table
{
public:

    CppSQLite3Table();

    CppSQLite3Table(const CppSQLite3Table& rTable);

    CppSQLite3Table(char** paszResults, int nRows, int nCols);

    virtual ~CppSQLite3Table();

    CppSQLite3Table& operator=(const CppSQLite3Table& rTable);

    int numFields();

    int numRows();

    const char* fieldName(int nCol);

    const char* fieldValue(int nField);
    const char* fieldValue(const char* szField);

    int getIntField(int nField, int nNullValue=0);
    int getIntField(const char* szField, int nNullValue=0);

    double getFloatField(int nField, double fNullValue=0.0);
    double getFloatField(const char* szField, double fNullValue=0.0);

    const char* getStringField(int nField, const char* szNullValue="");
    const char* getStringField(const char* szField, const char* szNullValue="");

    bool fieldIsNull(int nField);
    bool fieldIsNull(const char* szField);

    void setRow(int nRow);

    void finalize();

private:

    void checkResults();

    int mnCols;
    int mnRows;
    int mnCurrentRow;
    char** mpaszResults;
};


class CppSQLite3Statement
{
public:

    CppSQLite3Statement();

    CppSQLite3Statement(const CppSQLite3Statement& rStatement);

    CppSQLite3Statement(sqlite3* pDB, sqlite3_stmt* pVM);

    virtual ~CppSQLite3Statement();

    CppSQLite3Statement& operator=(const CppSQLite3Statement& rStatement);

    int execDML();

    CppSQLite3Query execQuery();

    void bind(int nParam, const char* szValue);
    void bind(int nParam, const int nValue);
    void bind(int nParam, const double dwValue);
    void bind(int nParam, const unsigned char* blobValue, int nLen);
    void bindNull(int nParam);

    void reset();

    void finalize();

private:

    void checkDB();
    void checkVM();

    sqlite3* mpDB;
    sqlite3_stmt* mpVM;
};


class CppSQLite3DB
{
public:

    CppSQLite3DB();

    virtual ~CppSQLite3DB();

    void open(const char* szFile);

    void close();

	bool tableExists(const char* szTable);

    int execDML(const char* szSQL);

    CppSQLite3Query execQuery(const char* szSQL);

    int execScalar(const char* szSQL);

    CppSQLite3Table getTable(const char* szSQL);

    CppSQLite3Statement compileStatement(const char* szSQL);

    sqlite_int64 lastRowId();

    void interrupt() { sqlite3_interrupt(mpDB); }

    void setBusyTimeout(int nMillisecs);

    static const char* SQLiteVersion() { return SQLITE_VERSION; }

private:

    CppSQLite3DB(const CppSQLite3DB& db);
    CppSQLite3DB& operator=(const CppSQLite3DB& db);

    sqlite3_stmt* compile(const char* szSQL);

    void checkDB();

    sqlite3* mpDB;
    int mnBusyTimeoutMs;
};

#endif
