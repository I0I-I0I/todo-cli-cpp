#include <iostream>
#include "actions.h"
#include "../globals/const.h"

int print_todo(std::vector<TodosStruct> &todos, ActionStruct action) {
	for (int i = 0; i < todos.size(); i++) {
		std::cout << i + 1 << " -> "
			<< todos[i].title << " : "
			<< todos[i].state << std::endl;
	}
	return NORMAL;
}
