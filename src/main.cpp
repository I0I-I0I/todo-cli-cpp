#include <iostream>
#include <vector>
#include <sstream>
#include "utils.h"
#include "types.h"

std::vector<TodosStruct> todos = {};

void greeting() {
	std::cout << "Welcome to ToDo cli app\n";
}

std::string get_todo_title() {
	std::string todo_title;
	std::cout << "Write a todo: \n\t";
	getline(std::cin, todo_title);
	std::cout << std::endl;
	return todo_title;
}

std::vector<int> get_args(ActionStruct &action) {
	std::string prompt;
	if (action.args == "") {
		std::cout << "Choise what check ('q' for quit): ";
		getline(std::cin, prompt);
		if (prompt == "q") return {};
	}
	std::vector<int> args;
	std::istringstream iss(prompt != "" ? prompt : action.args);
	std::string arg;
	while (iss >> arg) {
		args.push_back(stoi(arg));
	}
	return args;
}

int handle_action(ActionStruct action) {
	std::cout << std::endl;

	if (action.action == "quit") {
		return -1;
	} else if (action.action == "add") {
		std::string todo_title = action.args != "" ? action.args : get_todo_title();
		todos.push_back({todo_title, 'n'});
	} else if (action.action == "remove") {
		std::vector<int> args = get_args(action);
		for (int& index : args) {
			todos.erase(todos.begin() + index - 1);
		}
	} else if (action.action == "check") {
		std::vector<int> args = get_args(action);
		for (int& index : args) {
			todos[index - 1].state = 'c';
		}
	} else if (action.action == "uncheck") {
		std::vector<int> args = get_args(action);
		for (int& index : args) {
			todos[index - 1].state = 'n';
		}
	} else if (action.action ==  "print") {
		for (int i = 0; i < todos.size(); i++) {
			std::cout << i + 1 << " -> "
					  << todos[i].title << " : "
					  << todos[i].state << std::endl;
		}
	} else {
		std::cout << "Wrong command!";
	}

	std::cout << std::endl;
	return 0;
}

ActionStruct get_action() {
	ActionStruct action;
	std::string prompt;

	std::cout << "Prompt: ";
	getline(std::cin, prompt);
	trim(prompt);

	int space = prompt.find(' ');
	if (space != -1) {
		std::string first_part = prompt.substr(0, space);
		std::string second_part = prompt.substr(space + 1);
		action.action = first_part;
		action.args = second_part;
	} else {
		action.action = prompt;
	}

	return action;
}

int main() {
	greeting();

	ActionsStruct actions[] = {
		{ "quit", "Quit" },
		{ "add", "Add todo" },
		{ "remove", "Remove todo" },
		{ "check", "Check todo" },
		{ "uncheck", "Uncheck todo" },
		{ "print", "Print all todo" },
	};

	std::cout << "Choice what you want?\n";
	for (ActionsStruct item : actions) {
		std::cout << "\t" << item.key << ": " << item.desc << "\n";
	}
	std::cout << std::endl;

	while (true) {
		ActionStruct action = get_action();
		if (handle_action(action) == -1) return 0;
	}

	return 0;
}
