#include <loglib/debug.h>
#include <loglib/assert.h>
#include <future>



int main( void )
{

	//assert(2>3);
	loglib.log << "1test " << "test3 " << "test4";
	loglib.log << "2test " << "test3 " << "test4" << std::endl;
	loglib.log << "3test " << "test3 " << "test4" << std::endl;
	loglib.log << "4test " << "test3 " << "test4" << std::endl;

	auto handleA = std::async(std::launch::async, [](void){
		for( int i=0; i<10 ; i++ ) {
			loglib.log << "output: ";
			loglib.log << i;
			loglib.log << " aa";
			loglib.log << std::endl;
		}
	});

	auto handleB = std::async(std::launch::async, [](void){
		for( int i=0; i<10 ; i++ ) {
			loglib.log << "output: " << i << " aa" << std::endl;
		}
	});


	handleA.get();
	handleB.get();

    return 0;
}

