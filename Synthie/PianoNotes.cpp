#include "stdafx.h"
#include "PianoNotes.h"
#include <map>
#include <string>
using namespace std;
static int g_initialized = false;
static map<wstring, string> g_name2file;
const char* NoteToFile(const WCHAR *name, char dynamic){
	string note_file = "CompletePiano\\";
	if (!g_initialized)
	{
		for (int i = 0; i<sizeof(database) / sizeof(PianoNotes); i++)
		{
			g_name2file[database[i].name] = database[i].filename;
		}
		g_initialized = true;
	}
	map<wstring, string>::iterator f = g_name2file.find(name);
	if (f == g_name2file.end())
		return 0;
	if (f->second == "pedald" || f->second == "pedalu"){
		note_file += f->second;
	}
	else{
		note_file += f->second;
		note_file += dynamic;
	}
	note_file += ".wav";
	char* sender = new char[note_file.length() + 1];
	std::strcpy(sender, note_file.c_str());
	return sender;
}