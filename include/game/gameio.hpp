#ifndef GAMEIO_HPP
#define GAMEIO_HPP

#include <string>
#include <iostream>
#include <cctype>

int get_cols();

template<typename T>
void wrapped_print(std::ostream& ostream, T line) {
	std::string s(line);
	int cols = get_cols();
	std::string word;
	word.clear();
	for (char c : s) {
		if (cols < 0) {
			cols = -cols;
		}
		if (cols == 0) {
			ostream << '\n';
			ostream.flush();
			cols = get_cols();
		}
		if (std::isspace(c)) {
			if (!word.empty()) {
				if (cols < (int)word.length()) {
					ostream << '\n';
					ostream.flush();
					cols = get_cols();
				}
				ostream	<< word;
				ostream.flush();
				cols -= word.length();
				word.clear();
			}
			ostream << c;
			ostream.flush();
			if (c != '\n') {
				cols--;
			}
			else {
				cols = get_cols();
			}
		}
		else{
			word += c;
		}
	}
	if (!word.empty()) {
		if (cols < (int)word.length()) {
			ostream << '\n';
			ostream.flush();
			cols = get_cols();
		}
		ostream	<< word;
		ostream.flush();
		cols -= word.length();
		word.clear();
	}
}


void _print(std::ostream& ostream);

template<typename T, typename... Args>
void _print(std::ostream& ostream, T first, Args... args) {
	wrapped_print(ostream, first);
	ostream.flush();

	_print(ostream, args...);
}


template<typename... Args>
void print(Args... args) {
	_print(std::cout, args...);
}

template<typename... Args>
void error(Args... args) {
	_print(std::cerr, args...);
}

std::string get_input_line();

#endif
