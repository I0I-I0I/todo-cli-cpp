#include <vector>
#include "../globals/types.h"
#include "../utils/utils.h"
#include "../globals/const.h"

int remove_todo(std::vector<TodosStruct> &todos, ActionStruct action) {
	std::vector<int> args = get_args(action);
	for (int& index : args) {
		todos.erase(todos.begin() + index - 1);
	}
	return NORMAL;
}
