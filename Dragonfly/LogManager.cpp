#include "LogManager.h"
#include "utility.h"
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <cstdarg>

// using namespace df; -> can use to not use df::

df::LogManager::LogManager() {
	m_p_f = nullptr;
	m_do_flush = false;
	setType("LogManager");
}

df::LogManager::~LogManager() {
	if (m_p_f != nullptr) {
		fclose(m_p_f);
		m_p_f = nullptr;
	}
}

df::LogManager &df::LogManager::getInstance()
{
	static LogManager log_manager;
	return log_manager;
}

int df::LogManager::startUp() {
	m_p_f = nullptr;
	errno_t err = fopen_s(&m_p_f, "dragonfly.log", "w");
	if (err != 0) {
		std::cerr << "File failed to load" << std::endl;
		return 1;
	}

	df::Manager::startUp();
	return 0;
}

void df::LogManager::shutDown() {
	if (m_p_f) { 
		if (fclose(m_p_f) == 0) {
			m_p_f = nullptr;
		}
		else {
			std::cerr << "File failed to close" << std::endl;
		}
	}

	df::Manager::shutDown();
}

int df::LogManager::writeLog(const char* fmt, ...) const
{
	fprintf(m_p_f, "Message -> "); // Writes messages out to the log file
	va_list args;
	va_start(args, fmt);
	vfprintf(m_p_f, fmt, args);
	va_end(args);
	
	if (m_do_flush) {
		fflush(m_p_f); // Flushes the file to the disk after writing
	}
	
	return 0;
}

void df::LogManager::setFlush(bool new_do_flush) {
	m_do_flush = new_do_flush;
}

