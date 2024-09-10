#include <string>
#include <iostream>
#include <vector>
#include "actions.h"
#include "../globals/types.h"
#include "../globals/const.h"

std::string get_todo_title() {
	std::string todo_title;
	std::cout << "Write a todo: \n\t";
	getline(std::cin, todo_title);
	std::cout << std::endl;
	return todo_title;
}

int Store::add_todo(std::vector<TodosStruct>& todos, ActionStruct action) {
	std::string todo_title = action.args != "" ? action.args : get_todo_title();
	todos.push_back({todo_title, 'n'});
	return NORMAL;
}
