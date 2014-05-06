#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <boost/shared_ptr.hpp>
#include "Field.h"
class ResultSet
{
public:
	ResultSet(MYSQL_RES* result, MYSQL_FIELD* fields, uint64 rowCount, uint32 fieldCount);
	~ResultSet();

	bool NextRow();
	uint64 GetRowCount() const { return _rowCount; }
	uint32 GetFieldCount() const { return _fieldCount; }

	Field* Fetch() const { return _currentRow; }
	const Field & operator [] (uint32 index) const
	{
		ASSERT(index < _fieldCount);
		return _currentRow[index];
	}

protected:
	uint64 _rowCount;
	Field* _currentRow;
	uint32 _fieldCount;

private:
	void CleanUp();
	MYSQL_RES* _result;
	MYSQL_FIELD* _fields;
};

typedef boost::shared_ptr<ResultSet> QueryResult;

class PreparedResultSet
{
public:
	PreparedResultSet(MYSQL_STMT* stmt, MYSQL_RES* result, uint64 rowCount, uint32 fieldCount);
	~PreparedResultSet();

	bool NextRow();
	uint64 GetRowCount() const { return m_rowCount; }
	uint32 GetFieldCount() const { return m_fieldCount; }

	Field* Fetch() const
	{
		ASSERT(m_rowPosition < m_rowCount);
		return m_rows[uint32(m_rowPosition)];
	}

	const Field & operator [] (uint32 index) const
	{
		ASSERT(m_rowPosition < m_rowCount);
		ASSERT(index < m_fieldCount);
		return m_rows[uint32(m_rowPosition)][index];
	}

protected:
	std::vector<Field*> m_rows;
	uint64 m_rowCount;
	uint64 m_rowPosition;
	uint32 m_fieldCount;

private:
	MYSQL_BIND* m_rBind;
	MYSQL_STMT* m_stmt;
	MYSQL_RES* m_res;

	my_bool* m_isNull;
	unsigned long* m_length;

	void FreeBindBuffer();
	void CleanUp();
	bool _NextRow();

};

typedef boost::shared_ptr<PreparedResultSet> PreparedQueryResult;

#endif

