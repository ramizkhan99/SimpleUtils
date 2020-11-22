#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>
#include <functional>

#include "Dependencies/termcolor.hpp"

namespace slog
{
	class Logger
	{
	public:
		// Log level enum
		enum class LogLevel : uint8_t
		{
			Debug,
			Minimal,
			Common,
			Custom
		};

		// Default constructor to create Logger
		Logger() = default;

		// Constructor to log files to file stream
		Logger(std::string file);

		// Log level constructor
		Logger(const slog::Logger::LogLevel logLevel);

		// Log level with stream specifier constructor
		Logger(std::string file, const LogLevel logLevel);

		// Operator overload for stream
		std::ostream& operator<<(const std::string& message);

		// Common initializer for all constructors
		void Init();

		// Setter for log format
		virtual void SetFormat(const std::string& format);

		// Method to add custom tokens
		template<const std::string& item, typename T, typename U>
		void AddToken(const std::string& item, std::function<T(U)> function);

		// Method to add token as function
		void AddTokenFunction(const std::string& item, std::function<std::string(void)> function);

		// Setter for log level
		void SetLogLevel(const LogLevel logLevel);

		// Set file method
		void SetFile(std::string file);

	private:
		// Specifier Tokens
		std::vector<std::string> m_TokenKey;

		// Specifier functions
		std::vector<std::function<std::string(void)>> m_SpecifierFunctions;

		// Specifier token output
		std::vector<std::string> m_TokenValue;

		// Log format string
		std::string m_LogFormat;

		// Output log message
		std::string m_LogMessage;

		// Log file
		std::string m_LogFile;

		// Log stream
		std::ofstream m_LogStream;

		// Current Log level
		LogLevel m_LogLevel;

		// Method to get current data time
		void GetCurrentDateTime();
	};
}

