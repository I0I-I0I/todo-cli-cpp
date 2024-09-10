all: 
	g++ -o build/main\
		src/main.cpp\
		src/actions/handle_action.cpp\
		src/actions/add_todo.cpp\
		src/actions/remove_todo.cpp\
		src/actions/check_todo.cpp\
		src/actions/print_todo.cpp\
		src/commands/help.cpp\
		src/commands/quit.cpp\
		src/utils/trim.cpp\
		src/utils/get_args.cpp\
		src/utils/get_action.cpp\

clean:
	@echo "Cleaning files"
	rm build/*
