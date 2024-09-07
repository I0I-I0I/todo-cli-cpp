#include <array>
#include <iostream>
#include <limits>
#include <vector>

std::vector<std::array<std::string, 2>> todos = {};

void clear_input() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string get_todo_title() {
	std::string todo_title;
	std::cout << "Write a todo" << std::endl;
	clear_input();
	getline(std::cin, todo_title);
	return todo_title;
}

void handle_action(char action) {
	switch (action) {
		case 'a': {
			std::string todo_title = get_todo_title();
			todos.push_back({todo_title, "n"});
			break;
		}
		case 'r': {
			char choise;
			for (int i = 0; i < todos.size(); i++) {
				std::cout << i << " -> " << todos[i][0] << " : " << todos[i][1] << std::endl;
			}
			std::cout << "Choise what remove ('q' for quit): ";
			std::cin >> choise;
			if (choise == 'q') break;
			todos.erase(todos.begin() + choise - 2);
			break;
		}
		case 'p':
			for (int i = 0; i < todos.size(); i++) {
				std::cout << todos[i][0] << " : " << todos[i][1] << std::endl;
			}
			break;
		default:
			std::cout << "Wrong command!";
			break;
	}
}

void greeting() {
	std::cout << "Welcome to ToDo cli app\n";
}

char get_action(std::string actions[][2]) {
	char action;
	std::cout << "Choice what you want?\n";
	for (int i = 0; i < 4; i++) {
		std::cout << "\t" << actions[i][0] << ": " << actions[i][1] << "\n";
	}
	std::cout << std::endl;
	std::cin >> action;
	return action;
}

int main() {
	greeting();

	std::string actions[][2] = {
		{ "q", "Quit" },
		{ "a", "Add todo" },
		{ "r", "Remove todo" },
		{ "p", "Print all todo" },
	};

	while (true) {
		char action = get_action(actions);
		if (action == 'q') {
			return 0;
		}
		handle_action(action);
	}

	return 0;
}
