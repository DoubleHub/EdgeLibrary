// LogManager.h
// Declares Log class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Contains various Log functions
	class Log
	{
	private:
		#pragma region PRIVATE STUFF
		//Checks if a given directory exists
		static bool CheckForDirectory(const std::string &dirName_in);

		//Writes a given log entry into a given file, returns true if succeeds
		template<class T>
		static bool AddLog(T DataToLog, std::string LogType, std::string FilePath);
		#pragma endregion
	public:
		//Checks if given Directories exist and creates them if not, returns true if it succeeds, returns false if it fails
		static bool InitDirectories(std::string HardDrive, std::string Directory);

		//Creates a new Log Section in order to seperate the coming data from the old one, returns true if it succeeds, returns false if it fails
		static bool InitializeNewLogSection(std::string AppName, std::string FilePath);

		//Creates a new Log, defines the LogType as "LOG", returns true if it succeeds, returns false if it fails
		static bool NewLog(std::string Log, std::string FilePath);

		//Creates a new Log, defines the LogType as "WARNING", returns true if it succeeds, returns false if it fails
		static bool NewWarning(std::string Warning, std::string FilePath);

		//Creates a new Log, defines the LogType as "ERROR", returns true if it succeeds, returns false if it fails
		static bool NewError(std::string Error, std::string FilePath);
	};
}