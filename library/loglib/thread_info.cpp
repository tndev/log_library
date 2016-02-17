#include <loglib/thread_info.h>
#include <loglib/string_utils.h>

#include <iostream>
#include <vector>

#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#else
#include <signal.h>
#define DEBUG_BREAK raise(SIGTRAP)
#endif

namespace loglibns {


	thread_info &thread_info::update(unsigned int line, const std::string &&file, const std::string &&function) {
		this->line = line;
		this->file = std::move(file);
		this->function = std::move(function);
		this->ns = this->file;
        
        //remove suffixes
        this->ns = string_replace(this->ns,".cpp","");
        this->ns = string_replace(this->ns,".h","");
        this->ns = string_replace(this->ns,".hpp","");
        this->ns = string_replace(this->ns,".cc","");
        
        
		this->ns = string_replace(this->ns,"/media/LinuxDrive/Projects/","");


        //remove prefixes


		return *this;
	}


	void thread_info::__assert(bool soft, bool valid, const std::string &cond, const std::string &message) {
		//log_library: /media/LinuxDrive/Projects/log_library/main.cpp:8: int main(): Assertion `2>3' failed.
		if( !valid ) {
			std::cerr << "ERROR: Assertion `" << cond << "` failed (" << message << ")." << std::endl;
			std::cerr << "       " << this->file << ":" << this->line << " [" << this->function << "]" << std::endl;


			if( soft ) {
				DEBUG_BREAK;
			} else {
				std::abort();
			}
		}
	}

	void thread_info::__assert(bool soft, bool valid, const std::string &cond) {
		__assert(soft, valid, cond, "");
	}

}
