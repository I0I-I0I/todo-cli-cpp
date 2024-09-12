#include <sqlite3.h>
#include <string>
#include "db.h"

std::string get_query_toggle_check(std::string id, bool flag) {
	std::string cond = flag ? "true" : "false";
	std::string query = "update todos set completed=" + cond + " where id='" + id + "';";
	return query;
}

int db_toggle_check(const char* db_name, std::vector<DBData> data, int index, bool flag) {
	sqlite3* db;
	std::string id = data[index - 1].id;
	std::string query = get_query_toggle_check(id, flag);
	int rc = db_exec(db_name, query.c_str(), 0, "Cannot toggle check todo from db");
	return rc;
}
