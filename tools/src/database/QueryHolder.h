
#ifndef _QUERYHOLDER_H
#define _QUERYHOLDER_H
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "SQLOperation.h"
#include <vector>
#include "QueryResult.h"
#include "PreparedStatement.h"
class SQLQueryHolder
{
    friend class SQLQueryHolderTask;
    private:
        typedef std::pair<SQLElementData, SQLResultSetUnion> SQLResultPair;
        std::vector<SQLResultPair> m_queries;
    public:
        SQLQueryHolder() {}
        ~SQLQueryHolder();
        bool SetQuery(size_t index, const char *sql);
        bool SetPQuery(size_t index, const char *format, ...) ;
        bool SetPreparedQuery(size_t index, PreparedStatement* stmt);
        void SetSize(size_t size);
        QueryResult GetResult(size_t index);
        PreparedQueryResult GetPreparedResult(size_t index);
        void SetResult(size_t index, ResultSet* result);
        void SetPreparedResult(size_t index, PreparedResultSet* result);
};


typedef  boost::function<void (boost::shared_ptr<SQLQueryHolder>) > QueryHolderCallBackFunc; 
class SQLQueryHolderTask : public SQLOperation
{
    private:
        SQLQueryHolder * m_holder;
        QueryHolderCallBackFunc m_callBack;

    public:
        SQLQueryHolderTask(SQLQueryHolder *holder,QueryHolderCallBackFunc callBack)
            : m_holder(holder), m_callBack(callBack){};
        bool Execute();

};

#endif