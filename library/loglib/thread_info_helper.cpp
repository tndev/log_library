#include <loglib/thread_info_helper.h>
#include <loglib/string_utils.h>

#include <iostream>
#include <mutex>
#include <vector>
#include <map>

namespace loglibns {

	static std::mutex g_stream_mutex;


	thread_info_helper::thread_info_helper(std::shared_ptr<thread_info> info)
			: m_info(info) {
		}



	namespace style {
#if 1
		std::string reset  = "\033[0m";
		std::string black  = "\033[0;30m";
		std::string red    = "\033[0;31m";
		std::string green  = "\033[0;32m";
		std::string yellow = "\033[0;33m";
		std::string blue   = "\033[0;34m";
		std::string purple = "\033[0;35m";
		std::string cyan   = "\033[0;36m";
		std::string white  = "\033[0;37m";

		std::string black_bold   = "\033[1;30m";
		std::string red_bold     = "\033[1;31m";
		std::string green_bold   = "\033[1;32m";
		std::string yellow_bold  = "\033[1;33m";
		std::string blue_bold    = "\033[1;34m";
		std::string purple_bold  = "\033[1;35m";
		std::string cyan_bold    = "\033[1;36m";
		std::string white_bold   = "\033[1;37m";

		std::string error = "\033[41;30m";
#else
		std::string reset  = "";
		std::string black  = "";
		std::string red    = "";
		std::string green  = "";
		std::string yellow = "";
		std::string blue   = "";
		std::string purple = "";
		std::string cyan   = "";
		std::string white  = "";


		std::string black_bold   = "";
		std::string red_bold     = "";
		std::string green_bold   = "";
		std::string yellow_bold  = "";
		std::string blue_bold    = "";
		std::string purple_bold  = "";
		std::string cyan_bold    = "";
		std::string white_bold   = "";
		std::string error = "";

#endif
	}


	std::map<std::string, size_t> nsIdxMapping;
	std::string getColor(size_t i) {
		switch(i%9) {
		case 0:
			return style::red;
		case 1:
			return style::green;
		case 2:
			return style::cyan_bold;
		case 3:
			return style::purple;
		case 4:
			return style::cyan;
		case 5:
			return style::red_bold;
		case 6:
			return style::green_bold;
		case 7:
			return style::blue_bold;
		case 8:
			return style::purple_bold;
		case 9:
			return style::blue;
		}
		return "";
	}



	void process_log(const std::shared_ptr<thread_info> &info, std::ostringstream &buffer, std::ostream &out ) {
		auto logLines = split_string(buffer.str(), "\n");


		if( nsIdxMapping.find( info->ns) == nsIdxMapping.end() ) {
			nsIdxMapping[info->ns] = nsIdxMapping.size();
		}

		if( logLines.size() > 1 ) {
			buffer.str(logLines.back());
			logLines.pop_back();

			for( auto line : logLines ) {
				out << style::reset << getColor(nsIdxMapping[info->ns]) << "[" << info->ns  <<":" << info->function << "]:" << style::reset << " " << line << std::endl;
			}
		}

	}

	thread_info_helper::~thread_info_helper() {
		/*
		 * mutex(lock)
		 * TODO check if there was a newline in the text if yes flush it until there
		 *      insert file and ns infos
		 *
		 **/
		std::lock_guard<std::mutex> lock(g_stream_mutex);

		process_log(m_info, m_info->err, std::cout);
		process_log(m_info, m_info->log, std::cout);


	}
}

