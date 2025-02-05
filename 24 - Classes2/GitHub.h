#pragma once

#include <string>

class GitHub {
	std::string json;

public:
	GitHub(std::string arr = "None") : json(arr) {};
	void operator =(GitHub git) {
		json = git.json;
	}
	std::string get() { 
		return json;
	}
};