#pragma once
#include <string>
#include <fstream>
#include <chrono>

namespace Logger
{
	enum class logLevel
	{
		Trace,
		Warning,
		Error,
	};

	void LogToFile(std::string input, std::string fileName, logLevel level)
	{
		std::string stringToLog;
		stringToLog += "[";
		if (level == logLevel::Trace)
			stringToLog += "Trace]";
		else if (level == logLevel::Warning)
			stringToLog += "Warning]";
		else
			stringToLog += "Error]";

		stringToLog += " " + input + "\n";

		std::ofstream of;

		of.open(fileName, std::ios::app);
		of << stringToLog;
		of.close();
	}
}