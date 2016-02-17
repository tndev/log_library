#ifndef LOGLIB_DEBUG_H
#define LOGLIB_DEBUG_H

#include <string>
#include <iostream>
#include <sstream>
#include <memory>

//__func__ does nto work in visual studio
#define loglib (loglibns::get_info_for_thread()->m_info->update(__LINE__, __FILE__, __FUNCTION__))
#define CMD_TO_STRING(cond, ...) #cond

#ifndef NDEBUG
#define DBG_ASSERT(...)  (loglibns::get_info_for_thread()->m_info->update(__LINE__, __FILE__, __FUNCTION__)).__assert(false, __VA_ARGS__, CMD_TO_STRING(__VA_ARGS__));
#define SOFT_ASSERT(...)  (loglibns::get_info_for_thread()->m_info->update(__LINE__, __FILE__, __FUNCTION__)).__assert(true, __VA_ARGS__, CMD_TO_STRING(__VA_ARGS__));
#else
#define DBG_ASSERT(...)
#define SOFT_ASSERT(...)
#endif

/*
 return a helper object that will be destructen at the end of the chain
 **/
//last message repeated nth times
#include <loglib/thread_info_helper.h>

namespace loglibns {
	std::shared_ptr<thread_info_helper> get_info_for_thread();
}

#endif

// #include <functional>
// #include <memory>
// #include <mutex>
//
// #include <ostream>
// #include <sstream>
//
// #include <iostream>
// #include <thread>
//
//
//
// class log_stream : public std::ostream {
// public:
// 	log_stream() : std::ostream(new std::stringbuf()) {}
//
// 	log_stream(const log_stream& c)
// 		: std::ostream( new std::stringbuf() )
// 	{
//
// 	}
//
// 	~log_stream() {
// 		global_log(*this);
// 		delete rdbuf();
// 	}
//
//
// 	static std::mutex s_log_mutex;
//
// 	static void global_log( const log_stream &stream ) {
// 		std::lock_guard<std::mutex> lock(log_stream::s_log_mutex);
// 		auto id = std::this_thread::get_id();
// 		std::cout << std::this_thread::get_id()  << std::endl;
// 		std::cout << "ok: " << stream.rdbuf() << std::endl;
// 	}
// };
//
//
// struct ostream_selector {
// 	template<typename T>
// 	std::ostream & operator << (const T &t) {
// 		auto &stream  = std::cout;//logger::get_log_stream_for_thread();
// 		stream << t;
// 		return stream;
// 	}
// };
//
// class logger {
// public:
// 	logger() {
//
// 	}
//
//
// 	//static logger_entry log;
// 	//static logger_entry err;
//
// 	static ostream_selector log;
// 	static ostream_selector err;
//
// 	static std::ostream & get_log_stream_for_thread() {
// 		return std::cout;
// 	}
//
// 	static logger &__update(unsigned long line, const std::string &file, const std::string &function) {
// 		std::cout << line << " " << file << " " << function << std::endl;
// 		//TODO return the instance
//
// 		return s_instace;
// 	}
//
//
// protected:
// 	static logger s_instace;
// };
//
//
// #define loglib logger::__update(__LINE__,__FILE__,__func__);logger
//
// logger logger::s_instace;
// ostream_selector logger::log = ostream_selector();
// ostream_selector logger::err = ostream_selector();
// //logger_entry logger::err;
//
// /*
//  create on output buffer per thread
//
//  */
//
//
// std::mutex log_stream::s_log_mutex;
//
//
// log_stream log() {
// 	return log_stream();
// }
