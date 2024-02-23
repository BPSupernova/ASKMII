#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "Manager.h"
#include <stdio.h>
#include <map>

#define LM df::LogManager::getInstance()

namespace df {

	const std::string LOG_OUTPUT_HERE = "dragonfly.log";

	class LogManager : public Manager {
	private:
		LogManager();
		LogManager(LogManager const&); // Singleton design pattern -> disallows copy
		void operator = (LogManager const&); // Singleton design pattern -> disallows assignment
		bool m_do_flush; // True if the system flushes to disk after write.
		FILE* m_p_f; // Pointer to logfile

	public:
		~LogManager();

		// Singleton design pattern -> Gets sole instance of this manager
		static LogManager &getInstance();

		int startUp();
		void shutDown();

		// supports arbitrary # of args; printf format w/strings; returns number of bytes written (excluding prepends), -1 if error
		int writeLog(const char* fmt, ...) const;

		void setFlush(bool new_do_flush = true);
	};
}

#endif // !LOGMANAGER_H
