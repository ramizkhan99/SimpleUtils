#include "Logger.h"

slog::Logger::Logger(std::string file)
	: m_LogLevel(LogLevel::Common), m_LogFile(std::move(file))
{
	m_LogStream.open(m_LogFile, std::ios::out | std::ios::app);
}

slog::Logger::Logger(std::string file, const LogLevel logLevel)
	: m_LogFile(std::move(file)), m_LogLevel(logLevel)
{
	m_LogStream.open(file, std::ios::out | std::ios::app);
}

slog::Logger::Logger(const LogLevel logLevel)
	: m_LogLevel(logLevel)
{}

std::ostream& slog::Logger::operator<<(const std::string& message)
{

}

void slog::Logger::Init()
{
	// #TODO: Setup all default specifiers, i.e., CurrentDateTime, Message, 
}

void slog::Logger::SetFormat(const std::string& format)
{

}

template<const std::string& item, typename T, typename U>
void slog::Logger::AddToken(const std::string& item, std::function<T(U)> function)
{
	m_TokenKey.emplace_back(item);
	m_SpecifierFunctions.emplace_back(function);
}

void slog::Logger::AddTokenFunction(const std::string& item, std::function<std::string(void)> function)
{

}

void slog::Logger::SetLogLevel(const LogLevel logLevel)
{
	m_LogLevel = logLevel;
}

void slog::Logger::SetFile(std::string file)
{
	m_LogFile = std::move(file);
	m_LogStream.open(file, std::ios::out | std::ios::app);
}

void slog::Logger::GetCurrentDateTime()
{

}
