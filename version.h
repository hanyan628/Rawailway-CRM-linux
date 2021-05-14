#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "11";
	static const char MONTH[] = "02";
	static const char YEAR[] = "2017";
	static const char UBUNTU_VERSION_STYLE[] = "12.01";
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "rc";
	
	//Standard Version Type
	static const long MAJOR = 3;
	static const long MINOR = 1;
	static const long BUILD = 2;
	static const long REVISION = 22;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 624;
	#define RC_FILEVERSION 3,1,2,22
	#define RC_FILEVERSION_STRING "3, 1, 2, 22\0"
	static const char FULLVERSION_STRING[] = "3.1.2.22";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 4;
	

}
#endif //VERSION_H
