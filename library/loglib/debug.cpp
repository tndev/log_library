#include <loglib/debug.h>
#include <map>
#include <thread>
#include <mutex>


namespace loglibns {

	//ostream_selector Debug::log;
	//ostream_selector Debug::err;
	//
	static std::map<std::thread::id,std::shared_ptr<thread_info> > g_thread_infos;
	static std::thread::id main_thread_id = std::this_thread::get_id();


	static std::mutex g_info_mutex;

	std::shared_ptr<thread_info_helper> get_info_for_thread() {

		std::thread::id id = std::this_thread::get_id();

		//mutex_lock

		std::lock_guard<std::mutex> lock(g_info_mutex);
		if( g_thread_infos.find(id) == g_thread_infos.end() ) {
			g_thread_infos.insert( std::make_pair(id, std::make_shared<thread_info>() ) );
		}
		auto res = g_thread_infos[id];

		//mutex_unlock

		return std::make_shared<thread_info_helper>(res);
	}

	//
	//void Debug::__update(unsigned int line, const std::string &&file, const std::string &&function) {
	//	get_info_for_thread()->update(line, std::move(file), std::move(function) );
	//}

}
