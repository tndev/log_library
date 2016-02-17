#ifndef LOGLIB_THREAD_INFO_HELPER_H
#define LOGLIB_THREAD_INFO_HELPER_H

#include <loglib/thread_info.h>


#include <memory>

namespace loglibns {

	struct thread_info_helper {
		thread_info_helper(std::shared_ptr<thread_info> info);
		~thread_info_helper();

		std::shared_ptr<thread_info> m_info;
	};

}

#endif
