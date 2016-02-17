#ifndef LOGLIB_THREAD_INFO_H
#define LOGLIB_THREAD_INFO_H

#include <string>
#include <ostream>
#include <sstream>

namespace loglibns {

	struct thread_info {

		thread_info() :
		log(),
		err(),
		_err_first(true),
		_log_first(true) {

		}

		thread_info &update(unsigned int line, const std::string &&file, const std::string &&function);
		void __assert( bool soft, bool valid, const std::string &cond, const std::string &message);
		void __assert( bool soft, bool valid, const std::string &cond);

		unsigned int line;
		std::string ns;
		std::string file;
		std::string function;


		std::ostringstream log;
		std::ostringstream err;

		bool _err_first;
		bool _log_first;
	};

}

#endif
