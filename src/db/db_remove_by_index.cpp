#include <sqlite3.h>
#include <string>
#include <vector>
#include "db.h"
#include "../globals/types.h"

std::string get_query_by_id(std::string id) {
	std::string query = "delete from todos where id = '" + id + "';";
	return query;
}

int db_remove_by_index(const char* db_name, std::vector<DBData> data, int index) {
	sqlite3* db;
	std::string id = data[index - 1].id;
	std::string query = get_query_by_id(id);
	int rc = db_exec(db_name, query.c_str(), 0, "Cannot remove value from db");
	return rc;
}
