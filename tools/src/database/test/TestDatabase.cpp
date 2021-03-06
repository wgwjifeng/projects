#include "TestDatabase.h"

void TestDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_TESTDATABASE_STATEMENTS);
	PREPARE_STATEMENT(TEST_INS_TESTDATA_STATEMENTS_ASYNC,stmttestsql[TESTSQL_INSERT],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_DEL_TESTDATA_STATEMENTS_ASYNC,stmttestsql[TESTSQL_DELETE],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_UPD_TESTDATA_STATEMENTS_ASYNC,stmttestsql[TESTSQL_UPDATE],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_SEL_TESTDATA_STATEMENTS_ASYNC,stmttestsql[TESTSQL_SELECT],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_COUNT_TESTDATA_STATEMENTS_ASYNC,stmttestsql[TESTSQL_COUNT],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_UPD_TESTDATACOLUMN1_STATEMENTS_ASYNC,stmttestsql[TESTSQL_UPDATECOLUMN1],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_UPD_TESTDATACOLUMN2_STATEMENTS_ASYNC,stmttestsql[TESTSQL_UPDATECOLUMN1],CONNECTION_ASYNC)
	PREPARE_STATEMENT(TEST_UPD_TESTDATACOLUMN3_STATEMENTS_ASYNC,stmttestsql[TESTSQL_UPDATECOLUMN1],CONNECTION_ASYNC)

	PREPARE_STATEMENT(TEST_INS_TESTDATA_STATEMENTS_SYNCH,stmttestsql[TESTSQL_INSERT],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_DEL_TESTDATA_STATEMENTS_SYNCH,stmttestsql[TESTSQL_DELETE],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_UPD_TESTDATA_STATEMENTS_SYNCH,stmttestsql[TESTSQL_UPDATE],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_SEL_TESTDATA_STATEMENTS_SYNCH,stmttestsql[TESTSQL_SELECT],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_COUNT_TESTDATA_STATEMENTS_SYNCH,stmttestsql[TESTSQL_COUNT],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_UPD_TESTDATACOLUMN1_STATEMENTS_SYNCH,stmttestsql[TESTSQL_UPDATECOLUMN1],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_UPD_TESTDATACOLUMN2_STATEMENTS_SYNCH,stmttestsql[TESTSQL_UPDATECOLUMN1],CONNECTION_SYNCH)
	PREPARE_STATEMENT(TEST_UPD_TESTDATACOLUMN3_STATEMENTS_SYNCH,stmttestsql[TESTSQL_UPDATECOLUMN1],CONNECTION_SYNCH)

}
