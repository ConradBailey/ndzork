#include "../../include/game/gameio.hpp"

#include <algorithm>

#include <readline/readline.h>
#include <readline/history.h>

#include <term.h>
#include <fcntl.h>
#include <error.h>
#include <string.h>
#include <curses.h>
#include <unistd.h>

void _print(std::ostream& /*ostream*/)
{}


std::string get_input_line() {
	std::string input(readline("\n>"));
	if (!input.empty())
		add_history(input.c_str());

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	return input;
}

static int setup_get_cols() {
  char const *const term = getenv("TERM");
  if (!term) {
		std::cerr << "IO Error: TERM environment variable not set" << std::endl;
    return 0;
  }

  char const *const cterm_path = ctermid(NULL);
  if (!cterm_path || !cterm_path[0]) {
		std::cerr << "IO Error: ctermid() failed" << std::endl;
    return 0;
  }

  int tty_fd = open(cterm_path, O_RDWR);
  if (tty_fd == -1) {
		std::cerr << "IO Error: open(\"" << cterm_path << "\") failed (" << errno << "): " << strerror(errno) << std::endl;
    return 0;
  }

  int errret;
  if (setupterm((char*)term, tty_fd, &errret) == ERR) {
		std::cerr << "IO Error: setupterm failed (errret = " << errret << ") not found" << std::endl;
		return 0;
  }
	close(tty_fd);

  int cols = tigetnum((char*)"cols");
  if (cols < 0) {
		std::cerr << "IO_Error: tigetnum() failed (" << cols << ")" << std::endl;
		return 0;
	}

	return 1;
}

int get_cols() {
	static int good_setup = setup_get_cols();

	if (!good_setup) {
		return 80;
	}

  int cols = tigetnum((char*)"cols");
  if (cols < 0) {
		return 80;
	}

  return cols;
}
