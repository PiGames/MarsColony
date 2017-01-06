#pragma once

#include "engine/console/Console.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace pi
{
	// Logger class
	// First, initialize it with init() method, then use log() to log messages
	class Logger final
	{
	public: 
		enum class MessageType
		{
			Separator = 0,
			Info,
			Warning,
			Error,
			Assert
		};

		enum class OutputType
		{
			Console = 0,
			File,
			Both
		};

	private:
		static void logToFile(const std::string& message);
		static void logToConsole(const std::string& message);

	public:

		// Logger class is static - you cannot make Logger object
		Logger() = delete;

		// Initializes Logger file 
		static void init(const std::string& outputFileName = "output.txt", Console* console = nullptr);
		static void log(const std::string& message, MessageType messageType = MessageType::Info, OutputType outputType = OutputType::Console);

	private:
		static std::ofstream file;
		static Console* console;
	};
}

