#include <iostream>
#include "actions.h"
#include "../globals/const.h"
#include "../db/db.h"

int print_todo(std::vector<TodosStruct> &todos, ActionStruct action) {
	std::vector<DBData> data = db_get_all(DB_NAME);
	for (int i = 0; i < data.size(); i++) {
		std::string completed = data[i].completed == false ? "false" : "true";
		std::cout << i + 1 << ". "
			      << data[i].title
			      << "\t| "
			      << completed
			      << std::endl;
	}
	std::cout << std::endl;
	return NORMAL;
}
