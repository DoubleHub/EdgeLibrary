// LogManager.cpp
// Defines Log class

// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Checks if a given directory exists
	bool Log::CheckForDirectory(const std::string &dirName_in)
	{
		DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
		if (ftyp == INVALID_FILE_ATTRIBUTES)
			return false;

		if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
			return true;

		return false;
	}

	//Writes a given log entry into a given file, returns true if succeeds
	template<class T>
	bool Log::AddLog(T DataToLog, std::string LogType, std::string FilePath)
	{
		SYSTEMTIME CurrentTime;

		GetLocalTime(&CurrentTime);

		std::ofstream writeFile(FilePath, std::ios::app);

		if (writeFile.is_open())
		{
			writeFile << "["
				<< std::setw(2) << std::setfill('0') << CurrentTime.wDay << "/"
				<< std::setw(2) << std::setfill('0') << CurrentTime.wMonth << "/"
				<< std::setw(4) << std::setfill('0') << CurrentTime.wYear << " - "
				<< std::setw(2) << std::setfill('0') << CurrentTime.wHour << ":"
				<< std::setw(2) << std::setfill('0') << CurrentTime.wMinute << ":"
				<< std::setw(2) << std::setfill('0') << CurrentTime.wSecond
				<< "]"
				<< " "
				<< "[" << LogType << "]"
				<< " "
				<< DataToLog
				<< "\n";
			writeFile.close();

			return true;
		}
		else
			return false;
	}

	//Checks if given Directories exist and creates them if not, returns true if it succeeds, returns false if it fails
	bool Log::InitDirectories(std::string HardDrive, std::string Directory)
	{
		std::string HardDriveDir = HardDrive;
		std::string concat = "";
		concat+=HardDriveDir; concat+=Directory;
		std::string BaseDirectory = concat;

		if (!CheckForDirectory(BaseDirectory))
			_mkdir(BaseDirectory.c_str());

		return true;
	}

	//Creates a new Log Section in order to seperate the coming data from the old one, returns true if it succeeds, returns false if it fails
	bool Log::InitializeNewLogSection(std::string AppName, std::string FilePath)
	{
		std::string concat = "";
		concat+="New instance of ";
		concat+=AppName;
		concat+=" started.";
		if (Log::NewLog("=====================================================", FilePath))
			if (Log::NewLog(concat, FilePath)) return true;
			else return false;
		else return false;
	}

	//Creates a new Log, defines the LogType as "LOG", returns true if it succeeds, returns false if it fails
	bool Log::NewLog(std::string Log, std::string FilePath)
	{
		if (Log::AddLog(Log, "LOG", FilePath))
			return true;
		else return false;
	}

	//Creates a new Log, defines the LogType as "WARNING", returns true if it succeeds, returns false if it fails
	bool Log::NewWarning(std::string Warning, std::string FilePath)
	{
		if (Log::AddLog(Warning, "WARNING", FilePath))
			return true;
		else return false;
	}

	//Creates a new Log, defines the LogType as "ERROR", returns true if it succeeds, returns false if it fails
	bool Log::NewError(std::string Error, std::string FilePath)
	{
		if (Log::AddLog(Error, "ERROR", FilePath))
			return true;
		else return false;
	}

}