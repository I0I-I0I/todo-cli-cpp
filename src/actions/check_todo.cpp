#include <vector>
#include "actions.h"
#include "../utils/utils.h"
#include "../globals/const.h"

int Store::check_todo(std::vector<TodosStruct> &todos, ActionStruct action) {
	std::vector<int> args = get_args(action);
	for (int& index : args) {
		todos[index - 1].state = 'c';
	}
	return NORMAL;
}

int Store::uncheck_todo(std::vector<TodosStruct> &todos, ActionStruct action) {
	std::vector<int> args = get_args(action);
	for (int& index : args) {
		todos[index - 1].state = 'n';
	}
	return NORMAL;
}
